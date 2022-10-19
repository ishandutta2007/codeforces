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

const int MN = 26*26*26;
int t, n;
bitset<MN> found;

int main(){
    boost();
    cin >> t;
    while(t--) {
        cin >> n;
        found.reset();
        bool good = false;
        while(n--){
            string str; cin >> str;
            if(good) continue;
            for(char &ch : str) ch -= 'a';
            if(str.front() == str.back()) good = true;
            else if(SZ(str) == 2){
                int a = str[0]*676 + str[1]*26;
                int rev = str[1]*676 + str[0]*26;
                for(int i = 0; i < 26; i++) good |= found[rev+i];
                for(int i = 0; i < 26; i++) found[a+i] = true;
            }
            else {
                int a = str[0]*676 + str[1]*26 + str[2];
                int rev = str[2]*676 + str[1]*26 + str[0];
                good |= found[rev];
                found[a] = true;
            }
        }
        cout << (good ? "YES\n" : "NO\n");
    }
}