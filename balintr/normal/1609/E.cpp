#include <bits/stdc++.h>
using namespace std;
#define DEBUG 0

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
    int sz;
    static constexpr T unit = {INF, 0};

    inline T merge(T t1, T t2){
        return {min(t1.fs, t1.sn + t2.fs), t1.sn + t2.sn};
    }

    void init(int inSz){
        sz = inSz;
    }

    void build(){
        for (int i = sz-1; i > 0; --i){
            data[i] = merge(data[i*2], data[i*2+1]);
        }
    }

    // Add value v, to pos p
    void update(int p, int v){
        p += sz;
        for (data[p] = {data[p].fs + v, data[p].sn + v}; p >>= 1;){
            data[p] = merge(data[p*2], data[p*2+1]);
        }
    }

    // Query range [l, r)
    T query(int l, int r){
        T resL = unit, resR = unit;
        for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
            if(l&1) resL = merge(resL, data[l++]);
            if(r&1) resR = merge(data[--r], resR);
        }
        return merge(resL, resR);
    }

    // Access the last layer of the segment tree
    inline T& operator[](int i){
        return data[i + sz];
    }
};

const int MN = 1 << 17;
int n, q;
char arr[MN];

namespace jTree {
    int tree[2*MN], lazy[2*MN];

    void pushDown(int i){
        tree[i*2] += lazy[i];
        tree[i*2+1] += lazy[i];
        lazy[i*2] += lazy[i];
        lazy[i*2+1] += lazy[i];
        lazy[i] = 0;
    }

    int query(int i, int segL, int segR, int l, int r){
        if(r <= segL || l >= segR) return INF;
        if(l <= segL && r >= segR) return tree[i];
        pushDown(i);
        int mid = (segL + segR)/2;
        return min(query(i*2, segL, mid, l, r), query(i*2+1, mid, segR, l, r));
    }

    int update(int i, int segL, int segR, int l, int r, int v){
        if(r <= segL || l >= segR) return tree[i];
        if(l <= segL && r >= segR){
            lazy[i] += v;
            return tree[i] += v;
        }
        pushDown(i);
        int mid = (segL + segR)/2;
        return tree[i] = min(update(i*2, segL, mid, l, r, v), update(i*2+1, mid, segR, l, r, v));
    }
}

SegTree<pii, MN> iTree;

// Add i+1
void addA(int i){
    int prv = i ? iTree.query(0, i).fs : INF;
    // Find the lowest number such that function is true, lo and hi are both inclusive
    int lo = 0;
    int hi = n;
    while(lo < hi){
        int mid = (lo + hi)/2;
        bool works = iTree.query(0, mid).fs < prv;
        if(works) hi = mid;
        else lo = mid + 1;
    }
    jTree::update(1, 0, n, lo, n, 1);
    if(DEBUG) cout << lo << " 1\n";
    iTree.update(i, 1);
}

// Add i+1
void removeA(int i){
    pii prv = iTree.query(0, i);
    // Find the lowest number such that function is true, lo and hi are both inclusive
    int lo = i;
    int hi = n;
    while(lo < hi){
        int mid = (lo + hi)/2;
        bool works = prv.sn + iTree.query(i, mid).fs <= prv.fs;
        if(works) hi = mid;
        else lo = mid + 1;
    }
    jTree::update(1, 0, n, lo, n, -1);
    if(DEBUG) cout << lo << " -1\n";
    iTree.update(i, -1);
}

void addC(int i){
    jTree::update(1, 0, n, i, n, -1);
    if(DEBUG) cout << i << " -1\n";
}

void removeC(int i){
    jTree::update(1, 0, n, i, n, 1);
    if(DEBUG) cout << i << " 1\n";
}

void addB(int i){
    removeA(i);
    removeC(i);
}

void removeB(int i){
    addA(i);
    addC(i);
}

int main(){
    boost();
    cin >> n >> q;
    n += 2;
    iTree.init(n);

    int numC = 0;

    for (int i = 1; i < n-1; i++) {
        cin >> arr[i];
        if(arr[i] == 'a') addA(i+1);
        else if(arr[i] == 'b') addB(i);
        else addC(i-1), numC++;
    }

    //cout << jTree::query(1, 0, n, 0, n) + numC << '\n';

    while(q--){
        int p;
        char ch;
        cin >> p >> ch;
        if(arr[p] == 'a') removeA(p+1);
        else if(arr[p] == 'b') removeB(p);
        else removeC(p-1), numC--;
        arr[p] = ch;
        if(arr[p] == 'a') addA(p+1);
        else if(arr[p] == 'b') addB(p);
        else addC(p-1), numC++;

        cout << jTree::query(1, 0, n, 0, n) + numC << '\n';
    }
}