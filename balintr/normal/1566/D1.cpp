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

template <typename T, int MSZ>
struct BIT {
    int sz;
    T data[MSZ+1];

    void init(int inSz){
        sz = inSz;
    }

    inline void update(int i, T x){
        for (++i; i <= sz; i += i & -i) data[i] += x;
    }

    // Sum of [0, i]
    inline T query(int i){
        T res = 0;
        for (++i; i > 0; i -= i & -i) res += data[i];
        return res;
    }

    // Returns the smallest index i such that query(i) >= x or sz if there are no such indices
    // All values must be positive
    int lower_bound(T x){
        int i = 0;
        for (int pw = 1 << lg2(sz); pw > 0; pw >>= 1) {
            if(i + pw <= sz && data[i + pw] < x){
                x -= data[i += pw];
            }
        }
        return i;
    }
};

const int MN = 305;
int t, n, m;
int arr[MN];
BIT<int, MN> bit;

int main(){
    boost();
    cin >> t;
    while(t--){
        cin >> n >> m;

        vi compr;
        for (int i = 0; i < m; ++i) {
            cin >> arr[i];
            compr.pb(arr[i]);
        }
        UNIQUE(compr);

        bit.init(m);
        fill(bit.data, bit.data + m + 1, 0);

        ll ans = 0;
        for (int i = 0; i < m; ++i) {
            int a = lower_bound(ALL(compr), arr[i]) - compr.begin();
            ans += bit.query(a-1);
            bit.update(a, 1);
        }

        cout << ans << '\n';
    }
}