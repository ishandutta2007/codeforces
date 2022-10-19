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

const pii MOVES[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int t, n, m;

int main(){
    boost();
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<vector<bool>> grid(n+2, vector<bool>(m+2));
        vector<vector<bool>> ansGrid(n+2, vector<bool>(m+2));
        int srcX = -1, srcY = -1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                char ch; cin >> ch;
                if(ch == 'L') srcX = i, srcY = j;
                if(ch == '.') grid[i][j] = true;
            }
        }

        queue<pii> qu;
        qu.push({srcX, srcY});
        while(!qu.empty()){
            auto [x, y] = qu.front(); qu.pop();
            for(auto [dx, dy] : MOVES){
                int x1 = x+dx, y1 = y + dy;
                if(!grid[x1][y1] || ansGrid[x1][y1]) continue;
                int numSide = 0;
                for(auto [dx1, dy1] : MOVES){
                    int x2 = x1+dx1, y2 = y1+dy1;
                    if(!grid[x2][y2] || ansGrid[x2][y2]) continue;
                    numSide++;
                }
                if(numSide <= 1){
                    ansGrid[x1][y1] = true;
                    qu.push({x1, y1});
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if(i == srcX && j == srcY) cout << 'L';
                else if(ansGrid[i][j]) cout << '+';
                else if(grid[i][j]) cout << '.';
                else cout << '#';
            }
            cout << '\n';
        }
    }
}