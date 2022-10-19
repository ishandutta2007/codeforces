#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 11;

int N;
int a[1 << MAXN];
int sol;

void load() {
    scanf("%d", &N);
    for (int i = 2; i < 1 << N + 1; i++)
        scanf("%d", a + i);
}

int dfs(int x) {
    if (x >= 1 << N) return 0;
    int l = dfs(2 * x) + a[2 * x];
    int r = dfs(2 * x + 1) + a[2 * x + 1];
    sol += abs(l - r);
    return max(l, r);
}

int main() {
    load();
    dfs(1);
    printf("%d\n", sol);
    return 0;
}