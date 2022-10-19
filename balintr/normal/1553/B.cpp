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
#define ms(a, x) memset(a, x, sizeof(a))
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
inline constexpr ll lg2(ll x){return 32 - __builtin_clzll(x);} // Num used bits
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

const int MN = 505;
int q;
string s, t;
bool fwd[MN][MN];

bool solve(){
    cin >> s >> t;
    ms(fwd, 0);
    int n = s.length();
    int m = t.length();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; i+j < n && j < m; ++j) {
            if(s[i+j] != t[j]) break;
            fwd[i][j] = true;
            if(j == m-1) return true;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m && i+j < n; ++j) {
            if(s[i+j] != t[m-j-1]) break;
            if(i+j+1 - (m-j-1) + 1 < 0 || i+j+1 - (m-j-1) + 1 >= MN || m-j-1 < 0 || m-j-1 >= MN) continue;
            if(fwd[i+j+1 - (m-j-1) + 1][m-j-2]) return true;
        }
    }
    return false;
}

int main(){
    boost();
    cin >> q;
    while(q--){
        cout << (solve() ? "YES\n" : "NO\n");
    }
}