#include <cstdio>
#include <algorithm>

using namespace std;


const int MAXL = 101;

int n, m;
int a[MAXL];

int main()
{
/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//*/
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        for (int j = m; j <= x; j++)
            a[j] += x / j;
    }
    
    int ans = 0;
    for (int i = m; i < MAXL; i++)
        ans = max(ans, i * a[i]);
    printf("%d\n", ans);
    
    return 0;
}