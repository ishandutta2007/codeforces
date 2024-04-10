#include <cstdio>

using namespace std;

const int MAXN = 101;

int n, x, y;
int a[MAXN];

int main()
{
/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//*/
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &a[i]);
        a[i] += a[i - 1];
    }
    scanf("%d %d", &x, &y);
    printf("%d\n", a[y] - a[x]);
    return 0;
}