#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100005;

int dp[maxn];
int p[maxn];
int a[maxn];
int n;
int dd[maxn];

int main()
{
    for (int i = 1; i < maxn; i++)
        p[i] = i;
    for (int i = 2; i*i < maxn; i++)
    {
        if (p[i] == i)
        {
            for (int j = i; j < maxn; j += i)
            {
                p[j] = i;
            }
        }
    }
    
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    for (int i = 0; i*i < maxn; i++)
        dp[i] = 0;
    int curr_max = 0;
    for (int i = 0; i < n; i++)
    {
        int m = 0;
        int dcnt = 0;
        
        while (a[i] != 1)
        {
            dd[dcnt++] = p[a[i]];
            m = max(m, dp[p[a[i]]]);
            a[i] /= p[a[i]];
        }
        
        m++;
        
        curr_max = max(curr_max, m);
        
        for (int j = 0; j < dcnt; j++)
        {
            dp[dd[j]] = max(dp[dd[j]], m);
        }
    }
    printf("%d", curr_max);
}