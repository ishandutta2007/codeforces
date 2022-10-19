#include <cstdio>
using namespace std;

typedef long long ll;

const int MAXN = 4000005;
const int MAXW = 4000005;

struct fenwick {
    ll f[MAXW];
    
    fenwick() {
        for (int i = 0; i < MAXW; i++)
            f[i] = 0;
    }
    
    inline void update(int x, ll val) {
        for (; x < MAXW; x += x & -x)
            f[x] += val;
    }
    
    inline void update(int lo, int hi, ll val) {
        update(lo, val);
        update(hi + 1, -val);
    }
    
    inline ll get(int x) {
        ll ret = 0;
        for (; x; x -= x & -x)
            ret += f[x];
        return ret;
    }
};

struct calc {
    fenwick A, B;
    
    inline void update(int lo, int hi, ll val) {
        A.update(lo, hi, val);
        B.update(lo, hi, (ll)(lo - 1) * val); 
        B.update(hi + 1, MAXN - 1, (ll)(lo - hi - 1) * val);
    }
    
    inline ll get(int x) {
        return A.get(x) * (ll)x - B.get(x);
    }
    
    inline ll get(int lo, int hi) {
        return get(hi) - get(lo - 1);
    } 
};

int N, M, W;
int t[MAXW], v[MAXW];
int x1[MAXW], y1[MAXW];
int x2[MAXW], y2[MAXW];
int cntx[MAXN], cnty[MAXN];
calc X, Y;

void load() {
    scanf("%d%d%d", &N, &M, &W);
    for (int i = 0; i < W; i++) {
        scanf("%d%d%d%d%d", t + i, x1 + i, y1 + i, x2 + i, y2 + i);
        if (!t[i]) scanf("%d", v + i);
    }
}

void solve() {
    for (int i = 0; i < W; i++) 
        cntx[x1[i]] = cntx[x2[i]] = cnty[y1[i]] = cnty[y2[i]] = 1;
    
    for (int i = 1; i <= N || i <= M; i++)
        cntx[i] = cnty[i] = i;
    
    ll sum = 0;
    for (int i = 0; i < W; i++) 
        if (t[i]) 
            printf("%I64d\n", X.get(cntx[x1[i]], cntx[x2[i]]) + Y.get(cnty[y1[i]], cnty[y2[i]]) - sum);
        else {
            int lenx = x2[i] - x1[i] + 1;
            int leny = y2[i] - y1[i] + 1;
            X.update(cntx[x1[i]], cntx[x2[i]], (ll)v[i] * leny);
            Y.update(cnty[y1[i]], cnty[y2[i]], (ll)v[i] * lenx);
            sum += (ll)v[i] * (ll)lenx * leny;
        }
}

int main() {
    load();
    solve();
    return 0;
}