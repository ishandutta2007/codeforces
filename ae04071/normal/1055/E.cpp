#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
typedef long long lli;
typedef pair<lli,int> pli;
typedef pair<int,int> pii;

const int inf=1e9+10;

int n,s,m,k,a[2000],dp[1602][1602],ps[3002],ts;
pii seg[2000];

void upd(int cur,int i,int val){
    while(cur<=n){
        dp[i][cur]=max(dp[i][cur],val);
        cur+=cur&-cur;
    }
}
int sum(int cur,int i){
    int res=0;
    while(cur){
        res=max(dp[i][cur],res);
        cur-=cur&-cur;
    }
    return res;
}
bool check(int val){
    for(int i=1;i<=n;i++)ps[i]=ps[i-1]+(a[i]<=val);
    memset(dp,0,sizeof(dp));

    int i=1,j=0;
    for(;i<=n;i++){
        for(int k=0;k<=m;k++){
            upd(i,k,sum(i-1,k));
            if(k!=0 && j<s && seg[j].fi<=i && i<=seg[j].se){
                upd(i,k,sum(seg[j].fi-1,k-1)+ps[i]-ps[seg[j].fi-1]);
            }
        }
        if(j<s && seg[j].se==i){
            j++;
        }
    }
    int mx=0;
    for(int i=0;i<=m;i++) {
        mx=max(mx,sum(n,i));
    }

    return mx>=k;
}

int main(){
    scanf("%d%d%d%d",&n,&s,&m,&k);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=0;i<s;i++){
        scanf("%d%d",&seg[i].fi,&seg[i].se);
    }
    sort(seg,seg+s,[](const pii &a,const pii &b){
         return a.se-a.fi>b.se-b.fi;
    });


    vector<pii>tmp;
    for(int i=s-1;i>=0;i--) {
        int f=0;
        for(int j=i-1;j>=0;j--) if(seg[j].fi<=seg[i].fi && seg[i].se<=seg[j].se) {
            f=1;
            break;
        }
        if(!f) tmp.push_back(seg[i]);
        else ts++;
    }
    for(int i=0;i<sz(tmp);i++) seg[i]=tmp[i];
    s=sz(tmp);
    sort(seg,seg+s);

    int lo=0,up=inf;
    while(up-lo>1){
        int md=(lo+up)>>1;
        if(check(md))up=md;
        else lo=md;
    }
    if(up>inf-4) {
        puts("-1");
    } else printf("%d\n",up);

    return 0;
}