#include <bits/stdc++.h>
using namespace std;

#define int ll

#define ll long long
#define pii pair<ll, ll>
#define f first
#define s second

#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define pb push_back
#define MX(a,b) a = max(a,b)
#define MN(a,b) a = min(a,b)

#define FOR(i,a,b) for (int i = a; i<b; ++i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for (int i = n-1; i>=0; --i)

#ifdef BALBIT
#define bug(...) cerr<<"#"<<__LINE__<<"- "<<#__VA_ARGS__<<": ", _do(__VA_ARGS__)
template<typename T> void _do(T && x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T && x, S && ...y){cerr<<x<<", "; _do(y...);}
#else
#define bug(...)
#define endl '\n'
#endif // BALBIT

const int maxn = 3e5+5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9+7;



signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    bug(1,2);

    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        vector<int> a(n), b(n);
        REP(i,n) {
            cin>>a[i];
        }
        REP(i,n) {
            cin>>b[i];
        }
        REP(i,n) {
            if (i) b[i] += b[i-1];
        }
        RREP(i,n) {
            if (i != n-1) a[i] += a[i+1];
        }
        ll re = inf;
        REP(i,n) {
            MN(re, max((i?b[i-1]:0), (i!=n-1?a[i+1]:0)));
        }
        cout<<re<<endl;
    }

}