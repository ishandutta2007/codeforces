#include <bits/stdc++.h>
using namespace std;
using lli = long long;

const lli MOD=1e9+7;
const lli INF=1e18;

int n,h,w;
lli arr[4][500001];
char str[500005];

void solve(char *str,int m,char c1,char c2,lli *a1,lli *a2) {
    vector<lli> mx1(n,0),mx2(n,0);
    lli x=0;
    for(int i=0;i<n;i++) {
        if(str[i]==c1) x--;
        else if(str[i]==c2) x++;
        if(i!=0) {
            mx1[i] = mx1[i-1];
            mx2[i] = mx2[i-1];
        }
        if(x<0) mx1[i] = max(mx1[i],-x);
        else mx2[i] = max(mx2[i],x);
    }

    for(int i=1;i<=m;i++) {
        if(i-mx1[n-1]<1 || x<0) {
            lli lo=-1,up=1e12;
            while(up-lo>1) {
                lli md=(lo+up)>>1;
                lli v=max(-x,0ll)*(md/n) + mx1[md%n];
                if(md>=n)  v = max(v, max(-x,0ll)*(md/n-1) + mx1[n-1]);
                if(i-v<1) up=md;
                else lo=md;
            }
            a1[i] = up;
        } else a1[i] = INF;
        if(m-mx2[n-1]-i<0 || x>0) {
            lli lo=-1,up=1e12;
            while(up-lo>1) {
                lli md=(lo+up)>>1;
                lli v=max(x,0ll)*(md/n) + mx2[md%n];
                if(md>=n) v = max(v, max(x,0ll)*(md/n-1) + mx2[n-1]);
                if(m-v-i<0) up=md;
                else lo=md;
            }
            a2[i] = up;
        } else a2[i] = INF;
    }
}
int main() {
    scanf("%d%d%d",&n,&h,&w);
    scanf("%s",str);

    solve(str, w,'L','R', arr[0],arr[1]);
    solve(str, h,'U','D', arr[2],arr[3]);

    int idx[4],sg[4]={1,-1,1,-1};
    idx[0]=idx[2]=1;
    idx[1]=w;
    idx[3]=h;

    lli ans=0;
    while(idx[0]<=idx[1] && idx[2]<=idx[3]) {
        lli v=INF;
        for(int i=0;i<4;i++) v = min(v,arr[i][idx[i]]);
        if(v==INF) {
            puts("-1");
            return 0;
        }
        
        for(int i=0;i<4;i++) if(v==arr[i][idx[i]]) {
            int op=((i>>1)<<1)^2;
            ans = (ans + 1ll*(idx[op|1] - idx[op] + 1)*((v+1)%MOD)%MOD)%MOD;
            idx[i] += sg[i];
        }
    }
    printf("%lld\n",ans);
    
    return 0;
}