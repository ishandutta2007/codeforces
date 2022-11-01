#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int Nmax = 2005, MOD = 1000000007;

vector <int> Divs[Nmax];

int Dp[Nmax][Nmax];

void Get_divs(const int N)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
                Divs[i].push_back(j);
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif

    cin.sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    Get_divs(N);
    Dp[0][1] = 1;

    for (int i = 1; i <= K; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (auto k: Divs[j])
            {
                Dp[i][j] = (Dp[i][j] + Dp[i - 1][k]) % MOD;
            }
        }
    }

    int Sol = 0;
    for (int i = 1; i <= N; i++)
        Sol = (Sol + Dp[K][i]) % MOD;

    cout << Sol << "\n";
}