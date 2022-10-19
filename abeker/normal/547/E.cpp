#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 200005;
const int MAXQ = 500005;
const int BASE = 3137;
const int MOD = 1000000007;

struct fenwick {
    int f[MAXN];
    fenwick() {
        memset(f, 0, sizeof f);
    }
    void update(int x) {
        for (++x; x < MAXN; x += x & -x)
            f[x]++;
    }
    int get(int x) {
        int ret = 0;
        for (++x; x; x -= x & -x)
            ret += f[x];
        return ret;
    }
    int query(int lo, int hi) {
        return get(hi) - get(lo - 1);
    }
};

int N, Q;
string s[MAXN];
char buff[MAXN];
int pow[MAXN];
vector <int> hash[MAXN];
vector < pii > V;
int lb[MAXN], ub[MAXN];
int l[MAXQ], r[MAXQ], k[MAXQ];
vector <int> in[MAXN], out[MAXN];
int sol[MAXQ];
fenwick F;

inline int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    else if (x < 0) x += MOD;
    return x;
}

inline int mul(int x, int y) {
    return (long long)x * y % MOD;
}

void load() {
    scanf("%d%d", &N, &Q);
    for (int i = 0; i < N; i++) {
        scanf("%s", buff);
        s[i] = buff;
        hash[i].push_back(0);
        for (int j = 0; j < s[i].size(); j++) {
            hash[i].push_back(add(mul(hash[i].back(), BASE), s[i][j]));
            V.push_back(pii(i, j));
        }
    }
    for (int i = 0; i < Q; i++) {
        scanf("%d%d%d", l + i, r + i, k + i);
        l[i]--; r[i]--; k[i]--;
    }
}

int sz(pii x) {
    return s[x.first].size() - x.second; 
}

int get_hash(pii x, int len) {
    return add(hash[x.first][x.second + len], -mul(pow[len], hash[x.first][x.second]));
}

int lcp(pii x, pii y) {
    int lo = 0, hi = min(sz(x), sz(y));
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (get_hash(x, mid) == get_hash(y, mid)) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

bool cmp(const pii &lhs, const pii &rhs) {
    int len = lcp(lhs, rhs);
    int lsz = sz(lhs);
    int rsz = sz(rhs);
    if (len < lsz && len < rsz)
        return s[lhs.first][lhs.second + len] < s[rhs.first][rhs.second + len];
    return lsz < rsz;
}

int get_lb(int x) {
    int lo = 0, hi = x;
    int len = sz(V[x]), target = get_hash(V[x], len);
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (sz(V[mid]) >= len && get_hash(V[mid], len) == target) hi = mid;
        else lo = mid + 1;  
    }
    return lo;
}

int get_ub(int x) {
    int lo = x, hi = (int)V.size() - 1;
    int len = sz(V[x]), target = get_hash(V[x], len);
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (sz(V[mid]) >= len && get_hash(V[mid], len) == target) lo = mid;
        else hi = mid - 1;  
    }
    return lo;
}

void solve() {
    pow[0] = 1;
    for (int i = 1; i < MAXN; i++)
        pow[i] = mul(pow[i - 1], BASE);
        
    sort(V.begin(), V.end(), cmp);
    
    for (int i = 0; i < V.size(); i++) {
        if (V[i].second) continue;
        lb[V[i].first] = get_lb(i);
        ub[V[i].first] = get_ub(i);
    }
    
    for (int i = 0; i < Q; i++) {
        in[lb[k[i]]].push_back(i);
        out[ub[k[i]]].push_back(i);
    }
    
    for (int i = 0; i < V.size(); i++) {
        for (int j = 0; j < in[i].size(); j++)  
            sol[in[i][j]] -= F.query(l[in[i][j]], r[in[i][j]]);
        F.update(V[i].first);
        for (int j = 0; j < out[i].size(); j++)
            sol[out[i][j]] += F.query(l[out[i][j]], r[out[i][j]]);
    }
    
    for (int i = 0; i < Q; i++)
        printf("%d\n", sol[i]);        
}

int main() {
    load();
    solve();
    return 0;
}