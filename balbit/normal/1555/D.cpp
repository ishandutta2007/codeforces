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

int fit[6][maxn];

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    bug(1,2);

    int n,q; cin>>n>>q;
    vector<int> p = {0,1,2};
    string s; cin>>s;
    REP(j, 6) {
        REP(i,n) {
            fit[j][i+1] = fit[j][i] + (s[i] != ('a' + (p[i%3])));
        }
        next_permutation(ALL(p));
    }
    REP(i, q) {
        int a,b; cin>>a>>b; --a; --b;
        int re = inf;
        REP(j,6) {
            MN(re, fit[j][b+1] - fit[j][a]);
        }
        cout<<re<<endl;
    }

}