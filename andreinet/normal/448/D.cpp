#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif

    long long N, M, K;

    cin >> N >> M >> K;

    long long st = 1, dr = N * M;
    long long Sol = 0;

    while (st <= dr)
    {
        long long mid = (st + dr) / 2;

        long long S = 0, S2 = 0;

        for (int i = 1; i <= N; i++)
        {
            S += min(mid / i, M);
            S2 += min(mid / i - (mid % i == 0), M);
        }

        if (S >= K && S2 < K)
        {
            Sol = mid;
            break;
        }

        if (S2 >= K) dr = mid - 1;
        else st = mid + 1;
    }

    cout << Sol << "\n";
}