#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000005;
const int LOG = 21;

int N, M, K, D;
char s[MAXN], nxt[MAXN];
int f[MAXN][LOG];
int idx[MAXN];

void load() {
    scanf("%d%d", &K, &D);
}

int get(int x) {
    int res = 0;
    for (int i = LOG - 1; i >= 0; i--)
        if (f[x][i] != K) {
            res |= 1 << i;
            x = f[x][i];
        }
    return res;
}

int iter(int x, int y) {
    for (int i = 0; i < LOG; i++)
        if (y >> i & 1) x = f[x][i];
    return x;
}

bool cmp(const int &l, const int &r) {
    if (l % D == r % D) return l < r;
    return l % D < r % D;
}

void solve() {
    for (int i = 0; i < K; i++)
        idx[i] = i;
    sort(idx, idx + K, cmp);
    
    f[0][0] = f[K][0] = K;
    for (int i = 1; i < K; i++)     
        f[idx[i]][0] = i - 1;
    
    for (int j = 1; j < LOG; j++)
        for (int i = 0; i <= K; i++)
            f[i][j] = f[f[i][j - 1]][j - 1];
    
    for (int i = 0; i < K; i++) {
        int tmp = get(i);
        int pos = tmp > N - K + 1 ? N - K + iter(i, N - K + 1) + 1 : tmp;
        nxt[pos] = s[i];
    }
    
    int val = get(K - 1);
    for (int i = K; i < N; i++) {
        int pos = val > N - i ? N - K + iter(K - 1, N - i) + 1 : i + val - K + 1;
        nxt[pos] = s[i];
    }
    
    for (int i = 0; i < N; i++) {
        s[i] = nxt[i];
        putchar(s[i]);
    }
    puts("");
}

int main() {
    scanf("%s%d", s, &M);
    N = strlen(s);
    while (M--) {
        load();
        solve();
    }
    return 0;
}