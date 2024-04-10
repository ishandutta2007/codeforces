#include <bits/stdc++.h>
using namespace std;
#define int ll
#define ll long long
#define pii pair<ll, ll>
#define f first
#define s second

#define FOR(i,a,b) for (int i = a; i<b; ++i)
#define REP(i,n) for (int i = 0; i<n; ++i)
#define REP1(i,n) for (int i = 1; i<=n; ++i)

#define SZ(x) (int)((x).size())
#define ALL(x) (x).begin(), (x).end()
#define pb push_back
#define MX(a,b) a = max(a,b)
#define MN(a,b) a = min(a,b)


#ifdef BALBIT
#define bug(...) cerr<<"#"<<__LINE__<<": "#__VA_ARGS__<<"- ", _do(__VA_ARGS__)
template<typename T> void _do(T && x) {cerr<<x<<endl;}
template<typename T,typename ...S> void _do(T && x, S && ...y) {cerr<<x<<", "; _do(y...);}
#else
#define bug(...)
#define endl '\n'
#endif // BALBIT


const int maxn = 2e5+5;
const ll inf = 0x3f3f3f3f3f3f3f3f;

ll org[11], take[11];

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

    clock_t t = clock();

    ll W; cin>>W;

    ll SUM = 0;

    REP1(i,8) {
        cin>>org[i];
        SUM += org[i] * (ll)i;
    }

    if (SUM <= W) {
        cout<<SUM<<endl; return 0;
    }

    SUM = 0;

    for (int i = 8; i>=1; --i) {
        take[i] = min(org[i], (W-SUM) / i);
        SUM += take[i] * i;
    }
    ll re = SUM;
    bug(SUM);

    while ((clock() -t) / (double)(CLOCKS_PER_SEC) < 1.7) {
        if (SUM <= W-8) {
            int at = rnd () % 8 + 1;
            if (take[at] < org[at]) {
                SUM += at; ++take[at];
            }
        }else{
            if (rnd() % 2) {
                int at = rnd () % 8 + 1;
                if (take[at] < org[at] && at + SUM <= W) {
                    SUM += at; ++take[at];
                }
            }else{
                int at = rnd () % 8 + 1;
                if (take[at] > 0) {
                    SUM -= at; --take[at];
                }
            }
        }
        MX(re, SUM);

    }
    cout<<re<<endl;
}