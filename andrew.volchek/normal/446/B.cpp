#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

const int maxn = 1005;

ll sum[2][maxn];

ll dp[2][maxn * maxn];


int main(int argc, char *argv[])
{   
    //freopen("a.in", "r", stdin);
    
    int n, m, k, p;
    scanf("%d %d %d %d", &n, &m, &k, &p);
    //n = 1000, m = 1000, k = 1000000, p = 100;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            scanf("%d", &x);
            sum[0][i] += x;
            sum[1][j] += x;
        }
    }
    
    int d[2] = {n, m};
    
    for (int g = 0; g < 2; g++)
    {
        priority_queue < ll > q;
        for (int i = 0; i < d[g]; i++)
            q.push(sum[g][i]);
            
        dp[g][0] = 0;
            
        for (int i = 1; i <= k; i++)
        {
            ll curr = q.top();
            dp[g][i] = dp[g][i - 1] + curr;;
            q.pop();
            q.push(curr - (ll)d[1 - g] * p);
        }
    }
    
    ll ans = -1e18;
    
    for (ll i = 0; i <= k; i++)
    {
        ans = max(ans, dp[0][i] + dp[1][k - i] - (i * p * (k - i)));
        ans = max(ans, dp[1][i] + dp[0][k - i] - (i * p * (k - i)));
    }
    
    cout << ans << endl;

    
    return 0;
}