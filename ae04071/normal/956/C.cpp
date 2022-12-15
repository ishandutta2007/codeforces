#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using lli = long long;
using pii = pair<int,int>;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

int n,arr[100001],he[100001];

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",arr+i);
    
    vector<pii> ta;
    for(int i=0;i<n;i++) ta.push_back({arr[i]+1, i});
    sort(ta.begin(),ta.end(), [](const pii &a,const pii &b) {
        if(a.fi!=b.fi) return a.fi > b.fi;
        else return a.se < b.se;
    });

    int cur = n-1;
    for(; cur >= ta[0].se; cur--) he[cur] = ta[0].fi;
    for(int i=1;i<sz(ta);i++) {
        //printf("%d %d\n",ta[i].fi,ta[i].se);
        if(cur >= ta[i].se) {
            int nh = he[cur+1];
            for(int cnt=1; cur >= ta[i].se; cur--, cnt++) he[cur] = max(ta[i].fi, nh - cnt);
        }
    }
    lli ans = 0;
    for(int i=0;i<n;i++) ans += he[i] - arr[i] - 1;
    printf("%lld\n",ans);
    
    return 0;
}