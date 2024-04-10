#include <bits/stdc++.h>
using namespace std;
const int N = 102;

bool stg(int n, int k)
{
    if (k % 3 != 0)
    {
        if (n % 3 == 0)
            return false;
        return true;
    }
    else
    {
        n %= (k + 1);
        if (n == k || n == k - 1 || n == k - 2)
            return true;
        else
        {
            if (n % 3 == 0)
                return false;
            return true;
        }
    }
}

bool dp[N];
int main()
{
    ios_base::sync_with_stdio(false);
    int n, k;
    /*n = 100;
    //cin >> k;
    for (int k = 3; k < N; ++k)
    {
        memset(dp, false, sizeof dp);
        for (int i = 1; i <= n; ++i)
        {
            if (i - 1 >= 0 && dp[i - 1] == false)
                dp[i] = true;
            if (i - 2 >= 0 && dp[i - 2] == false)
                dp[i] = true;
            if (i - k >= 0 && dp[i - k] == false)
                dp[i] = true;
        }
        for (int i = 0; i <= n; ++i)
        {
            if (dp[i] != stg(i, k))
                cout << "WA" << endl;
            //if (!dp[i])
            //    cout << i << endl;
            //cout << dp[i];
            //if ((i + 1) % (fun(k) + 1) == 0)
            //    cout << endl;
        }
        //cout << endl;
    }*/
    int tt;
    cin >> tt;
    while (tt--)
    {
        cin >> n >> k;
        if (stg(n, k))
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
    }
    return 0;
}