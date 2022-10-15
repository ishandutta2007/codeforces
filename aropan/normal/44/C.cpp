#include <cstdio>

using namespace std;

const int MAXN = 111;

int n, m;
int x[MAXN];

int main()
{
/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//*/
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        for (int j = a; j <= b; j++)
            x[j]++;
    }
    for (int i = 1; i <= n; i++)
        if (x[i] != 1)
        {
            printf("%d %d\n", i, x[i]);
            return 0;
        }
    puts("OK");
    return 0;
}