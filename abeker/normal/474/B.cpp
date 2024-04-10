#include <cstdio>
using namespace std;

int N, M;
int label[1000005];

void load() {
    scanf("%d", &N);
    int curr = 1;
    for (int i = 1; i <= N; i++) {
        int x; scanf("%d", &x);
        while (x--) label[curr++] = i;
    }
}

void solve() {
    scanf("%d", &M);
    while (M--) {
        int x; scanf("%d", &x);
        printf("%d\n", label[x]);
    }
}

int main() {
    load();
    solve();
    return 0;
}