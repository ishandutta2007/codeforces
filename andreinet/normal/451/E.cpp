#include <iostream>
#include <cstdio>

using namespace std;

const int MOD = 1000000007;

long long A[25];
int N;

int CountBites(int x)
{
    int ret = 0;

    while (x)
    {
        x &= (x - 1);
        ret++;
    }

    return ret;
}

int Pow(int x, int y)
{
    int ret = 1;

    for (; y; y >>= 1)
    {
        if (y & 1) ret = 1LL * ret * x % MOD;
        x = 1LL * x * x % MOD;
    }

    return ret;
}

int Comb(long long S)
{
    const int K = N - 1;

    if (K > S || S < 0) return 0;

    int Up = 1, Down = 1;

    for (long long i = S - K + 1; i <= S; i++)
        Up = 1LL * Up * (i % MOD) % MOD;

    for (int i = 1; i <= K; i++)
        Down = 1LL * Down * i % MOD;

    return 1LL * Up * Pow(Down, MOD - 2) % MOD;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif

    long long S;

    cin >> N >> S;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    int Sol = 0;

    for (int conf = 0; conf < (1 << N); conf++)
    {
        long long S1 = S;

        for (int i = 0; i < N; i++)
        {
            if ((1 << i) & conf)
                S1 -= A[i] + 1;
        }

        int x = Comb(S1 + N - 1);

        if (CountBites(conf) & 1)
        {
            Sol -= x;
            if (Sol < 0) Sol += MOD;
        }
        else
        {
            Sol += x;
            if (Sol >= MOD) Sol -= MOD;
        }
    }

    cout << Sol << "\n";
}