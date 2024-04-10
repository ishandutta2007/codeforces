#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i=0; i<n; i++)
#define repl(i,n) for(i=1; i<=n; i++)

#define sz(x) (int) x.size()
#define pb push_back
#define all(x) x.begin(),x.end()
#define uu first
#define vv second
#define mem(x, y) memset(x, y, sizeof(x))
#define un(x) x.erase(unique(all(x)), x.end())

#define sdi(x) scanf("%d", &x)
#define sdii(x, y) scanf("%d %d", &x, &y)
#define sdiii(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sdl(x) scanf("%lld", &x)
#define sdll(x, y) scanf("%lld %lld", &x, &y)
#define sdlll(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define sds(x) scanf("%s", x)
#define pfi(x) printf("%d\n", x)
#define pfii(x, y) printf("%d %d\n", x, y)
#define pfiii(x, y, z) printf("%d %d %d\n", x, y, z)
#define pfl(x) printf("%lld\n", x)
#define pfll(x, y) printf("%lld %lld\n", x, y)
#define pflll(x, y, z) printf("%lld %lld %lld\n", x, y, z)

#define eps 1e-9
#define OK cerr << "ok\n"
#define DB(x) cerr << #x << " = " << x << endl

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair <int, int> pii;

inline int setBit(int N, int pos) { return N=N | (1<<pos); }
inline int resetBit(int N, int pos) { return N= N & ~(1<<pos); }
inline bool checkBit(int N, int pos) { return (bool)(N & (1<<pos)); }

//int kx[] = {+2, +1, -1, -2, -2, -1, +1, +2};
//int ky[] = {+1, +2, +2, +1, -1, -2, -2, -1}; //Knight Direction
//int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
//int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1}; //Four & Eight Direction


const int MAXT = 200005, MAXD = 1000006;
int n, m;
LL k;
struct tariff {
    LL idx, l, r, p, c;
    inline bool operator < (const tariff &other) const {
        return (p < other.p);
    }
} tList[MAXT];
vector <tariff> st[MAXD], en[MAXD];
struct treeType {
    LL core, spend;
} dummy, tree[MAXT*4];

inline treeType Merge(treeType l, treeType r) {
    return {
        l.core  + r.core,
        l.spend + r.spend
    };
}

/// flag=true => entry, otherwise exit
void update(int node, int beg, int endd, int x, bool flag) {
    if(beg == x && endd == x) {
        if(flag) tree[node] = { tList[beg].c, tList[beg].c*tList[beg].p };
        else tree[node] = { 0, 0 };
        return;
    }

    int left = node << 1;
    int right = left + 1;
    int mid = (beg+endd) >> 1;

    if(x <= mid) update(left, beg, mid, x, flag);
    else update(right, mid+1, endd, x, flag);

    tree[node] = Merge(tree[left], tree[right]);
}

treeType sumQuery(int node, int beg, int endd, int x, int y) {
    if(x > y) return dummy;
    if(beg == x && endd == y) return tree[node];

    int left = node << 1;
    int right = left + 1;
    int mid = (beg+endd) >> 1;

    treeType l = (x <= min(y, mid))? sumQuery(left, beg, mid, x, min(y, mid)) : dummy;
    treeType r = (max(x, mid+1) <= y)? sumQuery(right, mid+1, endd, max(x, mid+1), y) : dummy;

    return Merge(l, r);
}

int diabloQuery(int node, int beg, int endd, LL k) {
    if(beg == endd) return beg;

    int left = node << 1;
    int right = left + 1;
    int mid = (beg+endd) >> 1;

    if(tree[left].core >= k) return diabloQuery(left, beg, mid, k);
    else return diabloQuery(right, mid+1, endd, k-tree[left].core);
}

LL solve() {
    int i;
    LL ret = 0;
    sort(tList+1, tList+1+m);
    repl(i, m) {
        tList[i].idx = i;
        st[ tList[i].l ].pb(tList[i]);
        en[ tList[i].r ].pb(tList[i]);
    }
    repl(i, n) {
        for(tariff x:st[i]) update(1, 1, m, x.idx, true);
        if(tree[1].core <= k) ret += tree[1].spend;
        else {
            int position = diabloQuery(1, 1, m, k);
            treeType now = sumQuery(1, 1, m, 1, position);
            LL extra = now.core-k;
            if(extra > 0) ret -= tList[ position ].p*extra;
            ret += now.spend;
        }
        for(tariff x:en[i]) update(1, 1, m, x.idx, false);
    }
    return ret;
}

int main() {
//    assert(freopen("in.txt","r",stdin));
//    assert(freopen("out.txt","w",stdout));

    int i;

    scanf("%d %lld %d", &n, &k, &m);
    repl(i, m) {
        sdll(tList[i].l, tList[i].r);
        sdll(tList[i].c, tList[i].p);
    }
    pfl(solve());

    return 0;
}