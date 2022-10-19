#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
const int offset = 1 << 17;
const int INF = 0x3f3f3f3f;
const int LOG = 18;

struct tournament {
    int t[2 * offset];
    
    tournament() {
        memset(t, INF, sizeof t);
    }

    void update(int x, int val) {
        x += offset;
        t[x] = val;
        for (x /= 2; x; x /= 2)
            t[x] = min(t[2 * x], t[2 * x + 1]);
    }
    
    int query(int x, int lo, int hi, int from, int to) {
        if (lo >= to || hi <= from) return INF;
        if (lo >= from && hi <= to) return t[x];
        int mid = (lo + hi) / 2;
        return min(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
    }
    
    int query(int from, int to) {
        if (from >= to) return INF;
        return query(1, 0, offset, from, to);
    }
} T;

int N, S, L;
int a[MAXN];

void load() {
    scanf("%d%d%d", &N, &S, &L);
    for (int i = 0; i < N; i++) 
        scanf("%d", a + i);        
}

int exp[MAXN];
int mini[LOG][MAXN], maks[LOG][MAXN];

void init() {
    for (int i = 2; i <= N; i++) 
        exp[i] = exp[i / 2] + 1;
    
    for (int i = 0; i < N; i++) 
        mini[0][i] = maks[0][i] = a[i];
        
    for (int i = 1; i < LOG; i++) 
        for (int j = 0; j < N; j++) {
            mini[i][j] = min(mini[i - 1][j], j + (1 << i - 1) < N ? mini[i - 1][j + (1 << i - 1)] : INF);
            maks[i][j] = max(maks[i - 1][j], j + (1 << i - 1) < N ? maks[i - 1][j + (1 << i - 1)] : -INF);
        }
            
}

int query_mini(int lo, int hi) {
    int e = exp[hi - lo];
    return min(mini[e][lo], mini[e][hi - (1 << e)]);
}

int query_maks(int lo, int hi) {
    int e = exp[hi - lo];
    return max(maks[e][lo], maks[e][hi - (1 << e)]);
}

int bs(int x) {
    int lo = 0, hi = x + 1, mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (query_maks(mid, x + 1) - query_mini(mid, x + 1) > S) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

int solve() {
    T.update(0, 0);
    for (int i = 0; i < N; i++) 
        T.update(i + 1, T.query(bs(i), i - L + 2) + 1);
        
    int sol = T.query(N, N + 1);
    if (sol >= INF) sol = -1;
    return sol;
}


int main() {
    load();
    init();
    printf("%d\n", solve());
    return 0;
}