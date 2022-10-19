#include <cstdio>
using namespace std;

const int MAXN = 105;
const int MAXT = 100005;

typedef long double ld;

int N, M;
int score[MAXN];
ld dp[MAXT][2];
ld pref[MAXT][2];

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", score + i);
}

ld solve() {
    if (M == 1) return 1;
    
    for (int i = 0; i < MAXT; i++) {
        dp[i][0] = 1;
        pref[i][0] = i + 1;
    }
    
    int c = 0;
    for (int i = 0; i < N; i++) {
        c ^= 1;
        dp[0][c] = 0;
        for (int j = 1; j < MAXT; j++) {
            dp[j][c] = pref[j - 1][c ^ 1];
            if (j > M) dp[j][c] -= pref[j - M - 1][c ^ 1];
            if (score[i] <= j) dp[j][c] -= dp[j - score[i]][c ^ 1];
            dp[j][c] /= M - 1;
        }
        pref[0][c] = 0;
        for (int j = 1; j < MAXT; j++)
            pref[j][c] = pref[j - 1][c] + dp[j][c];
    }
    
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += score[i];
    
    return (M - 1) * dp[sum - 1][c] + 1;
}

int main() {
    load();
    printf("%.15lf\n", (double)solve());
    return 0;
}