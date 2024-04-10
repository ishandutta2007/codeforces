#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 5005;

int n, m, k, ans;

int main()
{
/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//*/
    scanf("%d %d %d", &n, &m, &k);
    
    ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if ((i + j) & 1) continue;
            
            int 
                x = min(min(i, n - i - 1), min(j, m - j - 1)) + 1;
            ans += x == k;
        }
    printf("%d\n", ans);
    return 0;
}