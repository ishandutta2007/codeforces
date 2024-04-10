#include <cstdio>
using namespace std;

const int MAXN = 200005;

int N, M;
int a[MAXN];
int pos[MAXN];

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%d", a + i);
}

void solve() {
    for (int i = 1; i <= N; i++)
        if (a[i] == a[i - 1]) pos[i] = pos[i - 1];
        else pos[i] = i - 1;
    
    while (M--) {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        if (a[r] != x) printf("%d\n", r);
        else if (pos[r] < l) puts("-1");
        else printf("%d\n", pos[r]);
    }
}

int main() {
    load();
    solve();
    return 0;
}