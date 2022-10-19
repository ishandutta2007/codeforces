#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 200005;

struct frog {
    int x, id;
    ll t;
    frog(int x, ll t, int id) : x(x), t(t), id(id) {}
    frog() : x(0), t(0), id(0) {}
    bool operator <(const frog &rhs) const {
        return x < rhs.x;
    }
};

struct fenwick {
    ll f[MAXN];
    fenwick() {
        memset(f, -1, sizeof f);
    }
    void update(int x, ll val) {
        for (x++; x < MAXN; x += x & -x)
            f[x] = max(f[x], val);
    }
    ll get(int x) {
        ll ret = 0;
        for (x++; x; x -= x & -x)
            ret = max(ret, f[x]);
        return ret;
    }
    int bs(ll val) {
        int lo = 0, hi = MAXN;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (get(mid) >= val) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};

int N, M;
frog f[MAXN];
int p[MAXN], b[MAXN];
fenwick F;
multiset <pii> S;
int c[MAXN];
ll l[MAXN];

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d%I64d", &f[i].x, &f[i].t);
        f[i].id = i;
    }
    for (int i = 0; i < M; i++)
        scanf("%d%d", p + i, b + i);
}

void eat(int pos, pii mosq) {
    multiset <pii> :: iterator it = S.lower_bound(mosq);
    vector <pii> tmp;
    for (; it != S.end() && it -> first <= (ll)f[pos].x + f[pos].t; it++) {
        f[pos].t += (ll)(it -> second);
        tmp.push_back(*it);
        c[f[pos].id]++;
    }
    
    for (int i = 0; i < tmp.size(); i++)
        S.erase(S.find(tmp[i]));
    
    F.update(pos, (ll)f[pos].x + f[pos].t);
}

void solve() {
    sort(f, f + N);
    
    for (int i = 0; i < N; i++) 
        F.update(i, (ll)f[i].x + f[i].t);
        
    for (int i = 0; i < M; i++) {
        int pos = F.bs((ll)p[i]);
        pii curr(p[i], b[i]);
        S.insert(curr);
        if (pos < N && f[pos].x <= p[i]) 
            eat(pos, curr);
    }   
    
    for (int i = 0; i < N; i++)
        l[f[i].id] = f[i].t;
        
    for (int i = 0; i < N; i++)
        printf("%d %I64d\n", c[i], l[i]);
}

int main() {
    load();
    solve();
    return 0;
}