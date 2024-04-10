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

const int MN = 9e5 + 5;
int n;
BIT<ll, MN> bit, bit1;

int main(){
    boost();
    cin >> n;
    bit.init(MN);
    bit1.init(MN);
    ll p = 0;
    ll sum = 0;

    for (int i = 0; i < n; ++i) {
        ll a; cin >> a;

        p += sum;
        p += a * i;
        p -= bit.query(a);
        for (int j = a; j < MN; j += a) {
            bit.update(j, a);
            p -= (bit1.query(j-1) - bit1.query(j-1-a)) * (j/a - 1) * a;
        }
        bit1.update(a, 1);

        sum += a;

        cout << p << " \n"[i == n-1];
    }
}