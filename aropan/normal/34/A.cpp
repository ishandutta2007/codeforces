#include <cstdio>
#include <algorithm>

using namespace std;


const int MAXN = 111;
int a[MAXN];
int n, m;

int main()
{
/*
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
//*/
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    a[n] = a[0];
    m = 0;
    for (int i = 0; i < n; i++)
        if (abs(a[i] - a[i + 1]) < abs(a[m] - a[m + 1]))
            m = i;

    printf("%d %d\n", m + 1, (m + 1) % n + 1);

    return 0;
}