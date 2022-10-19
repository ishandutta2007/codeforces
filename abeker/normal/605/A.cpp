#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

int N;
int pos[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        int x; scanf("%d", &x);
        pos[x] = i;
    }
}

int solve() {
    int len = 0, sol = 0;
    for (int i = 1; i <= N; i++) {
        if (pos[i] < pos[i - 1]) len = 0;
        sol = max(sol, ++len);
    }
    return N - sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}