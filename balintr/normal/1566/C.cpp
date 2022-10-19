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
#define ms(a, x) memset(a, x, sizeof(a))
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
inline constexpr ll lg2(ll x){return 32 - __builtin_clzll(x);} // Num used bits
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

const int MN = 1e5 + 5;
int t, n;
bool arr[2][MN];
bool skip[MN];

int main(){
    boost();
    cin >> t;
    while(t--){
        string str1, str2;
        cin >> n >> str1 >> str2;
        for (int i = 0; i < n; ++i) {
            arr[0][i] = str1[i] == '1';
            arr[1][i] = str2[i] == '1';
        }

        int ans = 0;
        fill(skip, skip + n, false);
        for (int i = 0; i < n-1; ++i) {
            if(arr[0][i] == 0 && arr[1][i] == 0 && arr[0][i+1] == 1 && arr[1][i+1] == 1){
                skip[i] = skip[i+1] = true;
                ++i;
                ans += 2;
            }
            else if(arr[0][i] == 1 && arr[1][i] == 1 && arr[0][i+1] == 0 && arr[1][i+1] == 0){
                skip[i] = skip[i+1] = true;
                ++i;
                ans += 2;
            }
        }

        for (int i = 0; i < n; ++i) {
            if(!skip[i]){
                if(arr[0][i] == 0){
                    if(arr[1][i] == 0) ans++;
                    else ans += 2;
                }
                else {
                    if(arr[1][i] == 0) ans += 2;
                }
            }
        }

        cout << ans << '\n';
    }
}