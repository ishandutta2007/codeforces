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
    // All values must be non-negative
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

const int MN = 1e5 + 5;
int t, n;
string s1, s2;
deque<int> dqs[26];
BIT<int, MN> bit;

ll solve(){
    for (int i = 0; i < 26; i++) {
        dqs[i].clear();
    }
    ll best = LLINF;
    for (int i = 0; i < n; i++) {
        dqs[s1[i]-'a'].pb(i);
    }

    bit.init(n+1);
    fill(bit.data, bit.data+n+2, 0);

    ll cur = 0;
    for (int i = 0; i < n; i++) {
        ll bestSmall = LLINF, bestSame = LLINF;
        for (int j = 0; j < s2[i]-'a'; j++) {
            if(!dqs[j].empty()) bestSmall = min(bestSmall, (ll) dqs[j].front());
        }
        if(bestSmall != LLINF) best = min(best, cur + bestSmall + i - bit.query(bestSmall) - i);

        int ord = s2[i]-'a';
        if(!dqs[ord].empty()) bestSame = dqs[ord].front();
        if(bestSame == LLINF) return best;
        cur += bestSame + i - bit.query(bestSame) - i;
        bit.update(bestSame, 1);
        dqs[ord].pop_front();
    }
    return best;
}

int main(){
    boost();
    cin >> t;
    while(t--){
        cin >> n >> s1 >> s2;
        ll qRes = solve();
        cout << (qRes == LLINF ? -1 : qRes) << '\n';
    }
}