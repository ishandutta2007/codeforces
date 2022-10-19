#include <cstdio>
#include <algorithm> 
using namespace std;

const int MAXN = 100005;    
const int LOG = 18;
const int MAXM = 10;

int N, M, K;
int a[MAXN][MAXM];
int sol[MAXM];
int sparse[MAXN][LOG][MAXM];
int exp[MAXN];

void load() {
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++) 
            scanf("%d", a[i] + j);
}

int query(int lo, int hi, int x) {
    if (lo == hi) return 0;
    int e = exp[hi - lo];
    return max(sparse[lo][e][x], sparse[hi - (1 << e)][e][x]);
}

bool check(int lo, int hi) {
    int sum = 0;
    for (int j = 0; j < M; j++) { 
        sum += query(lo, hi, j);
        if (sum > K) return false;
    }
    return true;
}

int bs(int x) {
    int lo = x, hi = N;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(x, mid + 1)) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

void init() {
    for (int i = 2; i <= N; i++) 
        exp[i] = exp[i / 2] + 1;
    for (int k = 0; k < M; k++) 
        for (int j = 0; j < LOG; j++)
            for (int i = 0; i < N; i++) 
                if (j) 
                    sparse[i][j][k] = max(sparse[i][j - 1][k], (i + (1 << j - 1) < N ? sparse[i + (1 << j - 1)][j - 1][k] : -1));
                else 
                    sparse[i][j][k] = a[i][k]; 
}

void solve() {
    int maks = 0;
    for (int i = 0; i < N; i++) {
        int pos = bs(i);
        if (pos - i < maks) continue;
        maks = pos - i;
        for (int j = 0; j < M; j++) 
            sol[j] = query(i, pos, j);
    }
    for (int i = 0; i < M; i++) 
        printf("%d ", sol[i]);
    puts("");
}

int main() {
    load();
    init();
    solve();
    return 0;
}