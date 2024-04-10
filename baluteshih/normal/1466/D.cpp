#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define ET cout << "\n"
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(),v.end()
#define pb push_back
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#ifdef bbq
#define debug(...) {\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}
#define DB(a,s,e) {for(int _i=s;_i<e;++_i) cerr << a[_i] << " ";cerr << "\n";}
template<typename T>void _do(T &&x){cerr<<x<<endl;}
template<typename T,typename ...S> void _do(T &&x,S &&...t){cerr<<x<<", ";_do(t...);}
template<typename a,typename b> ostream& operator << (ostream &s,const pair<a,b> &p){return s<<"("<<p.X<<","<<p.Y<<")";}
#else
#define debug(...)
#define DB(a,s,e)
#endif

ll w[100005], ans[100005];
vector<int> G[100005];

int main() {
    IOS();
    int t;
    cin >> t;
    while (t--) {
        int n, a, b, tp = 0;
        ll sum = 0;
        cin >> n, ans[0] = 0;
        for (int i = 1; i <= n; ++i)
            cin >> w[i], G[i].clear(), ans[i] = 0;
        for (int i = 1; i < n; ++i)
            cin >> a >> b, G[a].pb(b), G[b].pb(a);
        for (int i = 1; i <= n; ++i) {
            sum += w[i];
            for (int j = 1; j < SZ(G[i]); ++j)
                ans[tp++] = w[i];
        }
        sort(ans, ans + tp, greater<ll>());
        for (int i = 0; i + 1 < n; ++i)
            cout << sum << " \n"[i == n - 2], sum += ans[i];
    }
}