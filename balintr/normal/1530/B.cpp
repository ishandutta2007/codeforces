#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, bool> pib;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<pib> vpib;
typedef int8_t int8;
typedef complex<double> cmplx;
template <typename T> using minPq = priority_queue<T, vector<T>, greater<T>>;
#define boost() cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
inline constexpr ll lg2(ll x){return 32 - __builtin_clzll(x);} // Num used bits
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

const int MN = 25;
int t, n, m;
bool grid[MN][MN];

int main(){
    boost();
    cin >> t;
    while(t--){
        memset(grid, 0, sizeof(grid));
        cin >> n >> m;
        for (int i = 0; i < n; i += 2) {
            grid[i][0] = true;
        }
        for (int i = 0; i < m; i += 2) {
            grid[0][i] = true;
        }
        for (int i = n-1; i >= 2; i -= 2) {
            grid[i][m-1] = true;
        }
        for (int i = m-1; i >= 2; i -= 2) {
            grid[n-1][i] = true;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << (grid[i][j] ? '1' : '0');
            }
            cout << '\n';
        }
        cout << '\n';
    }
}