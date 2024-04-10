#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

long long Solve(int N, int M, int K)
{
    if (K + 1 <= N)
        return 1LL * N / (K + 1) * M;

    return M / (K + 2 - N);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif

    ios :: sync_with_stdio(false);

    int N, M, K;
    cin >> N >> M >> K;

    if (N + M - 2 < K)
    {
        cout << "-1\n";
        return 0;
    }

    cout << max(Solve(N, M, K), Solve(M, N, K)) << '\n';
}