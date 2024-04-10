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

const int MN = 1005;
int n;
int arr[MN];
ll total;

int main(){
    boost();
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i += 2) {
        ll cur = 0;
        int numValid = arr[i];
        for (int j = i; j < n; ++j) {
            ll newCur = (j & 1) ? cur - arr[j] : cur + arr[j];
            if(newCur > cur) cur = newCur;
            else {
                total += max(0LL, numValid - max(0LL, newCur));
                numValid = min((ll) numValid, newCur + 1);
                cur = newCur;
                if(numValid <= 0) break;
            }
        }
    }

    cout << total << '\n';
}