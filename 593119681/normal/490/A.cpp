#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair <int, int> Pii;
#define x first
#define y second
#define mp make_pair
#define N 100000 + 5

int n, A[N], Head[N], Next[N], Size[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d", A + i);
        Next[i] = Head[A[i]];
        Head[A[i]] = i;
        Size[A[i]] ++;
    }
    int Min = min(Size[1], min(Size[2], Size[3]));
    printf("%d\n", Min);
    int u, v, w;
    for (int i = 1; i <= Min; i ++)
    {
        u = Head[1], v = Head[2], w = Head[3];
        printf("%d %d %d\n", u, v, w);
        Head[1] = Next[u], Head[2] = Next[v], Head[3] = Next[w];
    }
    return 0;
}