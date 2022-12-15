#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pii = pair<int,int>;
using lli = long long;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

int n,m,arr[100000];
pii ans[100000],aft[100000];
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",arr+i);

    int v=arr[0];
    for(int i=1;i<n;i++) {
        int t=arr[i];
        ans[i] = pii(v,t);
        if(t>v) swap(t,v);
        arr[i] = t;
    }
    arr[0] = v;
    for(int i=1;i<n;i++) {
        aft[i-1] = pii(v,arr[i]);
    }
    while(m--) {
        lli x;
        scanf("%lld",&x);
        if(x<=n-1) printf("%d %d\n",ans[x].fi,ans[x].se);
        else {
            x = (x-1)%(n-1);
            printf("%d %d\n",aft[x].fi,aft[x].se);
        }
    }
    
    return 0;
}