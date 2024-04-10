#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
const int MOD = 1000000009;

int dad[MAXN];
int sol[MAXN];

int find(int x) {
    return dad[x] == x ? x : dad[x] = find(dad[x]);
}

bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return 1;
    if (rand() & 1) swap(x, y);
    dad[x] = y;
    return 0;
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M); 
    for (int i = 1; i <= N; i++)
        dad[i] = i;
    for (int i = 1; i <= M; i++)
        sol[i] = (2 * sol[i - 1] + 1) % MOD;
    int cnt = 0;
    while (M--) {
        int a, b;
        scanf("%d%d", &a, &b);
        cnt += join(a, b);
        printf("%d\n", sol[cnt]);
    }
    return 0;
}