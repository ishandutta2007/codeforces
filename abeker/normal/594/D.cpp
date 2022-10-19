#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 200005;
const int MAXM = 1000005;
const int MOD = 1000000007;
const int offset = 1 << 18;

int N, Q;
int a[MAXN];
int p[MAXM], val[MAXM], inv[MAXM];
int last[MAXM];
int sol[MAXN];
vector <int> V[MAXN];
int l[MAXN];
int phi[2 * offset];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

inline int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int pow(int x, int y) {
    int res = 1;
    for (; y; y >>= 1) {
        if (y & 1) res = mul(res, x);
        x = mul(x, x);
    }
    return res;
}

void update(int x, int v) {
    x += offset;
    phi[x] = mul(phi[x], v);
    for (x /= 2; x; x /= 2) 
        phi[x] = mul(phi[2 * x], phi[2 * x + 1]);
}

int query(int x, int lo, int hi, int from, int to) {
    if (lo >= to || hi <= from) return 1;
    if (lo >= from && hi <= to) return phi[x];
    int mid = (lo + hi) / 2;
    return mul(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

void solve() {
    for (int i = 2; i < MAXM; i++) {
        if (p[i]) continue;
        val[i] = mul(i - 1, pow(i, MOD - 2));
        inv[i] = pow(val[i], MOD - 2);
        for (int j = i; j < MAXM; j += i)
            if (!p[j]) p[j] = i;
    }
    
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        int r; 
        scanf("%d%d", l + i, &r);
        l[i]--; r--;
        V[r].push_back(i);
    }
    
    for (int i = 0; i < 2 * offset; i++)
        phi[i] = 1;
        
    memset(last, -1, sizeof last);
    for (int i = 0; i < N; i++) {
        update(i, a[i]);
        for (int x = a[i]; x > 1; x /= p[x]) {
            if (last[p[x]] != -1)   
                update(last[p[x]], inv[p[x]]); 
            update(i, val[p[x]]);
            last[p[x]] = i;
        }
        for (int j = 0; j < V[i].size(); j++)
            sol[V[i][j]] = query(1, 0, offset, l[V[i][j]], i + 1);
    }
    
    for (int i = 0; i < Q; i++)
        printf("%d\n", sol[i]);
}

int main() {
    load();
    solve();
    return 0;
}