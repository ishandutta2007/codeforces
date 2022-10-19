#include <cstdio>
using namespace std;

typedef long double ld;

const int MAXN = 1005;

int N;
ld p[MAXN][MAXN];
ld sum[MAXN];
ld prod[MAXN];
ld exp[MAXN];
bool bio[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            int x; scanf("%d", &x);
            p[i][j] = (ld)x / 100;
        }
}

ld solve() {
    for (int i = 0; i < N; i++)
        prod[i] = 1;
        
    bio[N - 1] = true;
    int last = N - 1;
    for (int i = 1; i < N; i++) {
        int pos = -1;
        for (int j = 0; j < N; j++) {
            if (bio[j]) continue;
            sum[j] += prod[j] * p[j][last] * exp[last];
            prod[j] *= 1 - p[j][last];
            exp[j] = (sum[j] + 1) / (1 - prod[j]);
            if (pos == -1 || exp[j] < exp[pos]) pos = j;
        }
        bio[pos] = true;
        last = pos;
    }
    
    return exp[0];
}

int main() {
    load();
    printf("%.15lf\n", (double)solve());
    return 0;
}