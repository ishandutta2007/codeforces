#include <cstdio>
#include <set>
using namespace std;

const int MAXN = 100005;

int N, M;
int a[MAXN];
int ans[MAXN];
set <int> S;

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%d", a + i);
    for (int i = N; i; i--) {
        S.insert(a[i]);
        ans[i] = S.size();
    }
    while (M--) {
        int l;
        scanf("%d", &l);
        printf("%d\n", ans[l]);
    }
    return 0;
}