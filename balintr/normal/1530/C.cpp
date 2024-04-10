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

const int MN = 1e5 + 5;
int t, n;
int a[MN], b[MN];

int main(){
    boost();
    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
        }

        sort(a+1, a + n + 1);
        sort(b+1, b + n + 1);

        for (int i = 2; i <= n; ++i) {
            a[i] += a[i-1];
            b[i] += b[i-1];
        }

        int res = 0;
        while(true){
            int k = n + res;
            int numUsed = k - k/4;
            int aScore = a[n] - a[max(0, min(n, n-numUsed+res))] + res*100;
            aScore = min(numUsed*100, aScore);
            int bScore = b[n] - b[max(0, min(n, n-numUsed))];
            if(aScore >= bScore) break;
            res++;
        }
        cout << res << '\n';
    }
}