#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize "Ofast"

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

    inline T query(int i){
        T res = 0;
        for (++i; i > 0; i -= i & -i) res += data[i];
        return res;
    }

    pair<int, T> lower_bound(T x){
        int i = 0;
        for (int pw = 1 << lg2(sz); pw > 0; pw >>= 1) {
            bool flag = i + pw <= sz && data[i+pw] < x;
            x -= flag*data[i += flag*pw];
        }
        return {i, x};
    }
};

const int MN = 1e5 + 5;
int n, m, q;
BIT<ll, MN> bit, offsBit;
ll bSum;
ll aArr[105], bArr[MN];

int main(){
    boost();
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
        cin >> aArr[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> bArr[i];
        bSum += bArr[i];
    }

    bit.init(m);
    offsBit.init(m);
    offsBit.update(0, bArr[0]);
    bit.update(1, bArr[1]-bArr[0]);
    for (int i = 2; i < m; i++) {
        ll dd = (bArr[i]-bArr[i-1]) - (bArr[i-1]-bArr[i-2]);
        bit.update(i, dd);
        offsBit.update(i, -dd*(i-1));
    }

    while(q--){
        int type, k, d;
        cin >> type >> k >> d;
        if(type == 1){
            for (int i = n-k; i < n; i++) {
                aArr[i] += d*(i-n+k+1);
            }
        }
        else {
            bSum += (ll) d*k*(k+1)/2;
            if(m == k){
                bit.update(1, d);
                offsBit.update(0, -d*(m-k-1));
            }
            else {
                bit.update(m-k, d);
                offsBit.update(m-k, -d*(m-k-1));
            }
        }

        ll total = bSum + aArr[0]*(n+m-1);
        for (int i = 0; i < n-1; i++) {
            ll dif = aArr[i+1] - aArr[i];
            pair<int, ll> qRes = bit.lower_bound(dif);
            assert(qRes.fs > 0);
            ll dif1 = dif - qRes.sn;
            ll offs = offsBit.query(qRes.fs-1);
            total += offs + dif1*(qRes.fs-1);
            total += dif*(m-qRes.fs + n-i - 1);
        }
        cout << total << '\n';
    }
}