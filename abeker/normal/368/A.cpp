#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 105;

int N, D, M;
int a[MAXN];

int main() {
    scanf("%d%d", &N, &D);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
    scanf("%d", &M);
    sort(a, a + N);
    int sol = 0;
    for (int i = 0; i < N && i < M; i++)
        sol += a[i];
    sol -= max(M - N, 0) * D;
    printf("%d\n", sol);
    return 0; 
}