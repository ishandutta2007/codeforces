#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 200005;

int N;
int a[MAXN];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) 
        scanf("%d", a + i);
    sort(a, a + N);
    int sol = (int)2e9, len = N / 2;
    for (int i = 0; i + len < N; i++)
        sol = min(sol, a[i + len] - a[i]);
    printf("%d\n", sol);
    return 0;
}