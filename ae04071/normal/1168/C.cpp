#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
using namespace std;
using lli = long long;
using pii = pair<int,int>;
using pll = pair<lli,lli>;
using pli = pair<lli,int>;
using pdd = pair<double,double>;

int n,m,arr[300001],nxt[300001][19];
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",arr+i);
    
    int v[20]={0,};
    for(int i=n;i;i--) {
        for(int j=0;j<19;j++) {
            if(arr[i]>>j&1) nxt[i][j]=i;
            else nxt[i][j]=n+1;
        }
        for(int j=0;j<19;j++) if(arr[i]>>j&1) {
            if(v[j]) {
                for(int k=0;k<19;k++) nxt[i][k] = min(nxt[i][k], nxt[v[j]][k]);
            }
            v[j]=i;
        }
    }   

    while(m--) {
        int a,b,f=0;
        scanf("%d%d",&a,&b);
        for(int j=0;j<19;j++) {
            if((arr[b]>>j&1) && nxt[a][j]<=b) {
                f=1;
                break;
            }
        }
        puts(f ? "Shi" : "Fou");
    }

    return 0;
}