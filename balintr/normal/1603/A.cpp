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
#define pb push_back
#define eb emplace_back
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
#define LAST(v) (v)[SZ(v)-1]
#define SZ(v) ((int) (v).size())
#define ms(a, x) memset(a, x, sizeof(a))
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
inline constexpr ll lg2(ll x){return 64 - __builtin_clzll(x);} // Num used bits
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

const int MN = 1e5 + 5;
int t, n;
int arr[MN];

int main(){
    boost();
    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        bool impossible = false;
        for (int i = 0; i < min(n, 100); i++) {
            bool allDivide = true;
            for (int j = 2; j <= i+2; j++) {
                if(arr[i] % j){
                    allDivide = false;
                    break;
                }
            }
            if(allDivide){
                impossible = true;
                break;
            }
        }
        cout << (impossible ? "NO\n" : "YES\n");
    }
}