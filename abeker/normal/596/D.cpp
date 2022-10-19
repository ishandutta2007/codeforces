#include <cstdio>
#include <algorithm>
using namespace std;

typedef long double ld;

const int MAXN = 2005;
const int INF = (int)1e9;

int N, H;
ld P;
int x[MAXN];
int l[MAXN], r[MAXN];
ld dp[MAXN][MAXN][2][2];

ld rec(int lo, int hi, int i, int j) {
    ld &ref = dp[lo][hi][i][j];
    if (ref != -1) return ref;
    if (lo > hi) return ref = 0;
    int left = x[lo - 1];
    if (i) left += H;
    int right = x[hi + 1];
    if (!j) right -= H;
    ld a = P * (rec(lo + 1, hi, 0, j) + min(x[lo] - left, H)) +  
          (1 - P) * (rec(r[lo] + 1, hi, 1, j) + min(x[r[lo]] + H, right) - x[lo]);
    ld b = (1 - P) * (rec(lo, hi - 1, i, 1) + min(right - x[hi], H)) + 
            P * (rec(lo, l[hi] - 1, i, 0) + x[hi] - max(left, x[l[hi]] - H));
    return ref = (a + b) / 2;
}

void load() {
    double tmp;
    scanf("%d%d%lf", &N, &H, &tmp);
    P = tmp;
    for (int i = 1; i <= N; i++)
        scanf("%d", x + i);
}

ld solve() {
    sort(x + 1, x + N + 1);
    x[0] = -INF;
    x[N + 1] = INF;
    for (int i = 1; i <= N; i++) {
        int j = i;
        for (; j <= N && x[j + 1] - x[j] < H; j++);
        r[i] = j;
        j = i;
        for (; j && x[j] - x[j - 1] < H; j--);
        l[i] = j;
    }
    
    for (int i = 0; i <= N + 1; i++)
        for (int j = 0; j <= N + 1; j++)    
            for (int k = 0; k < 2; k++)
                for (int l = 0; l < 2; l++) 
                    dp[i][j][k][l] = -1;
    
    return rec(1, N, 0, 1);
}

int main() {
    load();
    printf("%.9lf\n", (double)solve());
    return 0;
}