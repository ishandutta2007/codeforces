#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize "Ofast"
#pragma GCC target "avx2"

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

#ifdef WIN32
const int MN = 10, MSZ = 1 << MN;
#else
const int MN = 20, MSZ = 1 << MN;
#endif
int n, m, sz;
bitset<MSZ> grid[MN];
int mem[MSZ][MN+1];

int main(){
    boost();
    cin >> n >> m;
    sz = 1 << n;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    for (int i = 0; i < m; i++) {
        int a = 0;
        for (int j = 0; j < n; j++) {
            a = (a << 1) | grid[j][i];
        }
        mem[a][0]++;
    }

    int pw = 1;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < sz; i += pw*2) {
            for (int j = 0; j < pw; j++){
                int a = i+j, b = i+j+pw;
                for (int l = n; l > 0; l--) {
                    mem[a][l] += mem[b][l - 1];
                    mem[b][l] += mem[a][l - 1];
                }
            }
        }
        pw *= 2;
    }

    int best = INF;
    for (int i = 0; i < sz; i++) {
        int cur = 0;
        for (int j = 0; j <= n; j++) {
            cur += min(j, n-j) * mem[i][j];
        }
        best = min(best, cur);
    }
    cout << best << '\n';
}