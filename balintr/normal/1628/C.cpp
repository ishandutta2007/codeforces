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

const pii MOVES[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

const int MN = 1005;
int t, n;
int arr[MN][MN];
bool grid[MN][MN], res[MN][MN];

void flip(int x, int y){
    res[x][y] ^= 1;
    for(auto [dx, dy] : MOVES){
        int x1 = x + dx, y1 = y + dy;
        if(x1 < 0 || y1 < 0 || x1 >= n || y1 >= n) continue;
        grid[x1][y1] ^= 1;
    }
}

int main(){
    boost();
    cin >> t;
    while(t--){
        cin >> n;
        ms(grid, 0);
        ms(res, 0);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i-1][j] == 0) flip(i, j);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int a; cin >> a;
                ans ^= a * res[i][j];
            }
        }
        cout << ans << '\n';

        /*for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << grid[i][j];
            }
            cout << '\n';
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << res[i][j];
            }
            cout << '\n';
        }
        cout << endl;*/
    }
}