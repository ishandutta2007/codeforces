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

template<typename T, int MSZ>
struct SegTree {
    T data[MSZ*2];
    static constexpr T unit = -LLINF;

    inline T merge(T t1, T t2){
        return max(t1, t2);
    }

    void build(){
        for (int i = MSZ-1; i > 0; --i){
            data[i] = merge(data[i*2], data[i*2+1]);
        }
    }

    // Set value at position p to v
    void update(int p, T v){
        for (data[p += MSZ] = v; p >>= 1;){
            data[p] = merge(data[p*2], data[p*2+1]);
        }
    }

    // Query range [l, r)
    T query(int l, int r){
        T resL = unit, resR = unit;
        for (l += MSZ, r += MSZ; l < r; l >>= 1, r >>= 1) {
            if(l&1) resL = merge(resL, data[l++]);
            if(r&1) resR = merge(data[--r], resR);
        }
        return merge(resL, resR);
    }

    // Access the last layer of the segment tree
    inline T& operator[](int i){
        return data[i + MSZ];
    }
};

const int MN = 5e4 + 5;
int t, n;
int arr[MN];
int prv[MN];

SegTree<ll, MN> tree;

void genPrv(){
    fill(tree.data, tree.data + MN*2, -LLINF);
    tree.update(0, 0);
    ll cur = 0;
    for (int i = 1; i <= n; i++) {
        cur += arr[i];

        int lo = -1;
        int hi = i-2;
        while(lo < hi){
            int mid = (lo + hi + 1)/2;
            ll qRes = tree.query(mid, i-1);
            bool works = cur - qRes < 0;
            if(works) lo = mid;
            else hi = mid - 1;
        }
        prv[i] = lo+1;
        tree.update(i, cur);
    }
}

int countPokes(){
    set<pii> bstart, bend;
    for (int i = 2; i <= n; i++) {
        if(prv[i] == 0) continue;
        bstart.insert({prv[i], i});
        bend.insert({i, prv[i]});
    }
    int res = 0;
    while(!bend.empty()){
        res++;
        auto iter = bend.begin();
        int p = iter->fs;
        while(!bstart.empty()){
            auto iter1 = bstart.begin();
            if(iter1->fs <= p){
                bend.erase({iter1->sn, iter1->fs});
                bstart.erase(iter1);
            }
            else break;
        }
    }
    return res;
}

int main(){
#ifdef WIN32
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
#endif

    boost();
    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        int x; cin >> x;
        for (int i = 1; i <= n; i++) {
            arr[i] -= x;
        }

        genPrv();
        //for (int i = 1; i <= n; i++) cout << prv[i] << " \n"[i == n];
        cout << n-countPokes() << '\n';
    }
}