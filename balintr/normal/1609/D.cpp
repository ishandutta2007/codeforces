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

const int MN = 1005;
int n, d;

namespace Dsu {
    int dsu[MN], dsuSz[MN], dsuComps;

    void dsuInit() {
        dsuComps = n;
        for (int i = 0; i < n; ++i) dsu[i] = i, dsuSz[i] = 1;
    }

    int find(int a) {
        return dsu[a] == a ? a : dsu[a] = find(dsu[a]);
    }

    void merge(int a, int b) {
        if ((a = find(a)) != (b = find(b))) {
            --dsuComps;
            if (dsuSz[a] < dsuSz[b]) dsu[a] = b, dsuSz[b] += dsuSz[a];
            else dsu[b] = a, dsuSz[a] += dsuSz[b];
        }
    }
}
using namespace Dsu;

int main(){
    boost();
    cin >> n >> d;
    dsuInit();

    int numGroup = 1;
    for (int i = 0; i < d; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if(find(a) == find(b)) numGroup++;
        else merge(a, b);

        vi gSz;
        for (int j = 0; j < n; j++) {
            if(dsu[j] == j) gSz.pb(dsuSz[j]);
        }
        sort(ALL(gSz));

        int ans = 0;
        for (int j = SZ(gSz)-1; j >= SZ(gSz) - numGroup && j >= 0; j--) {
            ans += gSz[j];
        }
        cout << ans-1 << '\n';
    }
}