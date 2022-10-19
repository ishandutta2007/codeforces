#include <bits/stdc++.h>
using namespace std;

typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef complex<double> cmplx;
template <typename T> using minPq = priority_queue<T, vector<T>, greater<T>>;
#define boost() cin.sync_with_stdio(0); cin.tie(0)
#define ms(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define eb emplace_back
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int) (v).size())
#define lbv(v, x) (lower_bound((v).begin(), (v).end(), x) - (v).begin())
#define ubv(v, x) (upper_bound((v).begin(), (v).end(), x) - (v).begin())
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
inline constexpr ll lg2(ll x){return 64 - __builtin_clzll(x);} // Num used bits
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

struct Res {
    int t;
    int rate;
    ll v;
};

bool operator<(const int &a, const Res &r){
    return a < r.t;
}

const int MN = 55, MM = 305;
int n, m;
pair<pii, pii> edges[MM];
vi times;
vector<Res> results;
int dsu[MN];

int find(int a){
    return dsu[a] == a ? a : dsu[a] = find(dsu[a]);
}

int main(){
    boost();
    cin >> n >> m;
    times.pb(0);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        edges[i] = {{0, c}, {a, b}};
        times.pb(c);
        for (int j = 0; j < i; j++) {
            times.pb((c + edges[j].fs.sn)/2 + 1);
        }
    }
    UNIQUE(times);
    results.reserve(SZ(times));

    for(int t : times){
        for(int i = 0; i < n; i++) dsu[i] = i;

        for (int i = 0; i < m; i++) edges[i].fs.fs = abs(t - edges[i].fs.sn);
        sort(edges, edges + m);

        ll v = 0;
        int rate = 0;
        for (int i = 0; i < m; i++) {
            auto [p1, p2] = edges[i];
            auto [nc, oc] = p1;
            auto [a, b] = p2;
            a = find(a), b = find(b);
            if(a == b) continue;
            dsu[a] = b;
            v += nc;
            rate += oc <= t ? 1 : -1;
        }

        results.pb({t, rate, v});
    }

    int p, k, a, b, c;
    cin >> p >> k >> a >> b >> c;
    int qry;
    ll ans = 0;

    for (int i = 0; i < p; i++) {
        cin >> qry;
        Res res = *--upper_bound(ALL(results), qry);
        //cout << res.v + (ll) res.rate*(qry-res.t) << '\n';
        ans ^= res.v + (ll) res.rate*(qry-res.t);
    }
    for (int i = 0; i < k-p; i++) {
        qry = ((ll) qry*a + b) % c;
        Res res = *--upper_bound(ALL(results), qry);
        //cout << res.v + (ll) res.rate*(qry-res.t) << '\n';
        ans ^= res.v + (ll) res.rate*(qry-res.t);
    }
    cout << ans << '\n';
}