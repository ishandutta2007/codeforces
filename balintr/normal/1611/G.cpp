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

const int MN = 1e6 + 10;
int t, n, m, sz;
set<int> grid[2][MN];

int main(){
    boost();
    cin >> t;
    while(t--){
        cin >> n >> m;
        sz = (n+m)/2 + 5;
        for (int i = 0; i < n; i++) {
            string str; cin >> str;
            for (int j = 0; j < m; j++) {
                if(str[j] == '0') continue;
                int x = (i + j)/2;
                int y = (i - j + m)/2;
                grid[(i + j) & 1][x].insert(y);
            }
        }

        int ans = 0;

        for (int g = 0; g < 2; g++){
            set<int> st;
            for (int i = 0; i < sz; i++) {
                int skipUntil = INF;
                for (auto iter = grid[g][i].rbegin(); iter != grid[g][i].rend(); ++iter){
                    if(*iter >= skipUntil) continue;
                    auto siter = st.upper_bound(*iter);
                    if(siter == st.begin()){
                        ans++;
                        st.insert(*iter);
                        break;
                    }
                    int v = *--siter;
                    st.erase(siter);
                    st.insert(*iter);
                    skipUntil = v;
                }
                grid[g][i].clear();
            }
        }

        cout << ans << '\n';
    }
}