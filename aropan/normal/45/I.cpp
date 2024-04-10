#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 111;

int n, k, m, z;
int a[MAXN], b[MAXN];
int ans[MAXN];

int main()
{
/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//*/
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        if (x > 0) a[k++] = x; else
        if (x < 0) b[m++] = x; else
            z++;
    }
    sort(a, a + k);
    sort(b, b + m);
    
    for (int i = 0; i < m - 1; )
    {
        a[k++] = b[i++];
        a[k++] = b[i++];
    }
    
    if (k == 0)
    {
        if (z)
            a[k++] = 0;
        else
            a[k++] = b[m - 1];
    }
    
    for (int i = 0; i < k; i++)
    {
        if (i) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}