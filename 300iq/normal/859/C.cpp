
/*
    !  !!!
   
   
   
   
   
   
   
   
   
   
   
*/

#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 50 + 1;

ll dp[N][2];
int a[N];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            for (int t = 0; t < 2; t++)
            {
                if (t == 0)
                {
                    dp[i][t] = a[i];
                }
                else
                {
                    dp[i][t] = -a[i];
                }
            }
        }
        else
        {
            for (int t = 0; t < 2; t++)
            {
                if (t == 0)
                {
                    dp[i][t] = max(dp[i + 1][t ^ 1] + a[i], dp[i + 1][t] - a[i]);
                }
                else
                {
                    dp[i][t] = min(dp[i + 1][t ^ 1] - a[i], dp[i + 1][t] + a[i]);
                }
            }
        }
    }
    cout << (sum - (dp[0][0] + sum) / 2) << ' ' << (dp[0][0] + sum) / 2 << '\n';
}