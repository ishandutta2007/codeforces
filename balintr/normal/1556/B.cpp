#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
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

const int MN = 2e5 + 5;
int t, n;
bool arr[MN];
int arr1[MN];

int main(){
    boost();
    cin >> t;
    while(t--){
        cin >> n;
        int num0s = 0;
        int num1s = 0;

        for (int i = 0; i < n; ++i) {
            int a; cin >> a;
            arr[i] = a & 1;
            if(arr[i]) num1s++;
            else num0s++;
        }

        if(abs(num1s - num0s) > 1) cout << "-1\n";
        else {
            ll total = LLINF;
            ll total1 = LLINF;
            int n0s = 0;
            int n1s = 0;

            if(num1s >= num0s){
                total = 0;
                for (int i = 0; i < n; ++i) {
                    if(arr[i] == 1){
                        total += max(0, i - (2*(n1s++)));
                    }
                    else {
                        total += max(0, i - (1 + 2*(n0s++)));
                    }
                }
            }

            n0s = 0;
            n1s = 0;
            if(num0s >= num1s){
                total1 = 0;
                for (int i = 0; i < n; ++i) {
                    if(arr[i] == 0){
                        total1 += max(0, i - (2*(n0s++)));
                    }
                    else {
                        total1 += max(0, i - (1 + 2*(n1s++)));
                    }
                }
            }

            ll ans = min(total, total1);
            cout << ans << '\n';
        }
    }
}