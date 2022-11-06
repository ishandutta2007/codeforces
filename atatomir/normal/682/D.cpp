#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>


using namespace std;


#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 1024

int n, m, i, j, k;
char a[maxN], b[maxN];
int dp[maxN][maxN];

int main() {
    
    scanf("%d%d%d", &n, &m, &k);
    scanf("\n%s\n%s", a + 1, b + 1);
    
    for (int step = 1; step <= k; step++) {
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
                if (a[i] == b[j])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
                dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
    }
    
    printf("%d", dp[n][m]);
    
    
    return 0;
}