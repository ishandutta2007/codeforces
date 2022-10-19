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
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int) (v).size())
#define lbv(v, x) (lower_bound((v).begin(), (v).end(), x) - (v).begin())
#define ubv(v, x) (upper_bound((v).begin(), (v).end(), x) - (v).begin())
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
#define FR(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define dbg(x) {cerr << #x << ' ' << x << endl;}
#define dbgArr(arr, n) {cerr << #arr; FR(_i, n) cerr << ' ' << arr[_i]; cerr << endl;}

template <typename T, int MSZ>
struct BIT {
    T data[MSZ+1];

    inline void update(int i, T x){
        for (++i; i <= MSZ; i += i & -i) data[i] += x;
    }

    // Sum of [0, i]
    inline T query(int i){
        T res = 0;
        for (++i; i > 0; i -= i & -i) res += data[i];
        return res;
    }
};

const int MN = 2e5 + 5;
const int MEM = 2 << 20;
const int MQ = 1e6 + 5;
int n, q;
int arr[MN], vToPos[MN];
pii queries[MQ];
int sortedQs[MQ];
ll ans[MQ];
pii lUpds[MEM];
int li;

bool state[MN];
BIT<int, MN> slopeBit;
BIT<ll, MN> sumBit;

int main(){
    boost();
    cin >> n >> q;
    FR(i, n){
        cin >> arr[i];
        vToPos[arr[i]] = i;
    }

    FR(i, q){
        int l, r;
        cin >> l >> r;
        l--;
        queries[i] = {l, r};
        sortedQs[i] = i;
    }

    for(int flag = 0; flag < 2; flag++){
        set<int> st;
        FORR(i, n, 1){
            int p = vToPos[i];
            auto iter = st.lower_bound(p);
            int nxt = iter == st.end() ? n : *iter;
            int prv = iter == st.begin() ? -1 : *--iter;
            st.insert(p);

            vi facts;
            for(int j = 1; j*j < i; j++){
                if(i % j == 0) facts.pb(j), facts.pb(i/j);
            }

            sort(ALL(facts), [&](int a, int b){return vToPos[a] < vToPos[b];});

            if(p-prv < nxt-p || (p-prv == nxt-p && flag)){
                int ptr = SZ(facts)-1;
                int mn = INF;
                while(ptr != -1 && vToPos[facts[ptr]] >= p){
                    int p1 = vToPos[facts[ptr]];
                    int p2 = vToPos[i/facts[ptr]];
                    if(p1 < p2) mn = min(mn, p2);
                    ptr--;
                }
                FORR(j, p, prv+1){
                    if(ptr != -1 && vToPos[facts[ptr]] >= j){
                        int p1 = vToPos[facts[ptr]];
                        int p2 = vToPos[i/facts[ptr]];
                        if(p1 < p2) mn = min(mn, p2);
                        ptr--;
                    }
                    if(mn < nxt) lUpds[li++] = {max(p, mn), j}, lUpds[li++] = {nxt, j};
                }
            }
        }

        sort(lUpds, lUpds + li);
        li = 0;

        sort(sortedQs, sortedQs + q, [&](int a, int b){return queries[a].sn < queries[b].sn;});

        FR(i, q){
            auto [l, r] = queries[sortedQs[i]];

            while(lUpds[li].fs && lUpds[li].fs <= r){
                auto [v, p] = lUpds[li++];
                state[p] ^= 1;

                //cerr << state[p] << ' ' << p << ' ' << v << endl;
                if(state[p]){
                    slopeBit.update(p, 1);
                    sumBit.update(p, -v);
                }
                else {
                    slopeBit.update(p, -1);
                    sumBit.update(p, v);
                }
            }

            int slope = slopeBit.query(n-1) - slopeBit.query(l-1);
            ll sum = sumBit.query(n-1) - sumBit.query(l-1);
            ans[sortedQs[i]] += sum + (ll) slope*r;
        }

        li = 0;
        ms(lUpds, 0);
        reverse(arr, arr + n);
        FR(i, q){
            auto [l, r] = queries[i];
            queries[i] = {n-r, n-l};
        }
        FR(i, n+1) vToPos[i] = n-1-vToPos[i];

        ms(slopeBit.data, 0);
        ms(sumBit.data, 0);
    }

    FR(i, q) cout << ans[i] << '\n';
}