
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

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n = 1000000;
    vector <ll> dp(n + 1);
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            dp[i] = dp[i / 2] * 2 + (i / 2) * (ll) (i / 2);
        }
        else
        {
            dp[i] = dp[i / 2] + dp[i / 2 + 1] + (i / 2) * (ll) (i / 2 + 1);
        }
    }
    int k;
    cin >> k;
    int x = k;
    string ans = "";
    int ch = 0;
    while (k)
    {
        if (dp[n] <= k)
        {
            for (int i = 0; i < n; i++) ans += (ch + 'a');
            ch++;
            k -= dp[n];
        }
        else
        {
            n--;
        }
    }
    if (x == 0)
    {
        ans = "a";
    }
    cout << ans << '\n';
}