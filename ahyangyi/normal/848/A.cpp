#include <iostream>
#include <array>

using namespace std;

const int N = 800;
long long dp[N + 1];

int main()
{
    dp[1] = 0;
    for (int i = 2; i <= N; ++i)
    {
        dp[i] = -1;
        for (int j = 1; j <= i - j; ++j)
        {
            long long tmp = dp[j] + dp[i - j] + j * (i - j);
            if (dp[i] == -1 || tmp < dp[i])
            {
                dp[i] = tmp;
            }
        }
    }

    int n;
    while (cin >> n)
    {
        int i = N;
        char j = 'a';
        if (n == 0)
        {
            cout << "f";
        }
        while (n)
        {
            while (dp[i] > n)
            {
                --i;
            }
            n -= dp[i];
            for (int k = 0; k < i; ++k)
            {
                cout << j;
            }
            ++j;
        }
        cout << endl;
    }
    
    return 0;
}