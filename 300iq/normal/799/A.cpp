/*

 
$












 
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int n, t, k, d;
    cin >> n >> t >> k >> d;
    int sum = 0;
    int cur = 0;
    while (sum < n)
    {
        sum += k;
        cur += t;
    }
    int res_a = cur;
    sum = 0;
    cur = 0;
    int sum_b = 0;
    int res_b = 0;
    int cnt = 0;
    for (int cur = 0; ; cur++)
    {
        int re_a = cur / t * k;
        int re_b = max(0, (cur - d)) / t * k;
        if (re_a + re_b >= n)
        {
            res_b = cur;
            break;
        }
    }
    if (res_b < res_a)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}