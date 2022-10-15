#include <cstdio>

using namespace std;

const int MAXN = 111;

int n, m, x;
int a[MAXN];

int main()
{
/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//*/
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (x == m + 1) a[m++] = i + 2001;
    }
    printf("%d\n", m);
    for (int i = 0; i < m; i++)
    {
        if (i) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}