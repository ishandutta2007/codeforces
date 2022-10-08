#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
const int M = 1000000007;

int main()
{
    int n, p;
    cin >> n >> p;

    vector<int> a(n);
    unordered_set<int> S;
    vector<int> dp(p + 1);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        S.insert(a[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        int bits = 0;
        {
            int b = a[i];
            while (b)
            {
                ++bits;
                b /= 2;
            }
        }

        bool ok = true;
        {
            int b = a[i];
            while (b > 0)
            {
                if (b % 2 == 1)
                {
                    b /= 2;
                }
                else if (b % 4 == 0)
                {
                    b /= 4;
                }
                else
                {
                    break;
                }

                if (S.find(b) != S.end())
                {
                    ok = false;
                    break;
                }
            }
        }
        if (ok && bits <= p)
        {
            ++dp[bits];
        }
    }

    int ret = 0;
    for (int i = 1; i <= p; ++i)
    {
        if (i + 1 <= p)
        {
            dp[i + 1] = (dp[i] + dp[i + 1]) % M;
        }
        if (i + 2 <= p)
        {
            dp[i + 2] = (dp[i] + dp[i + 2]) % M;
        }
        if (i > 0)
        {
            ret = (ret + dp[i]) % M;
        }
    }
    cout << ret << endl;

    return 0;
}