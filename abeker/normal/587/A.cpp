#include <cstdio>
using namespace std;

const int MAXN = 2000005;

int N;
int cnt[MAXN];

void load() {
    scanf("%d", &N);
    while (N--) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
}

int solve() {
    int sol = 0;
    for (int i = 0; i < MAXN; i++) {
        sol += cnt[i] % 2;
        cnt[i + 1] += cnt[i] / 2;
    }
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}