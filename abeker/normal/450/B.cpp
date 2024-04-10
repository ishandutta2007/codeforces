#include <cstdio>
using namespace std;

const int MOD = 1000000007;
const int CYCLE = 6;

int N;
int f[CYCLE];

void load() {
    scanf("%d%d%d", f, f + 1, &N);
}

int solve() {
    for (int i = 0; i < CYCLE; i++) {
        if (i > 1) f[i] = f[i - 1] - f[i - 2];
        f[i] %= MOD; f[i] += MOD; f[i] %= MOD;
    }
    return f[(N - 1) % CYCLE];
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}