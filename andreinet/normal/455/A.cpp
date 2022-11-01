#include <iostream>
#include <cstdio>

using namespace std;

const int Nmax = 100005;

int A[Nmax];
long long Dp[Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        int x;
        scanf("%d", &x);

        A[x]++;
    }

    Dp[1] = A[1];
    Dp[2] = max(A[1], 2 * A[2]);

    for (int i = 3; i <= 100000; i++) {
        Dp[i] = max(Dp[i - 1], max(1LL * A[i] * i + Dp[i - 2], 1LL * A[i - 1] * (i - 1) + Dp[i - 3]));
    }

    cout << Dp[100000] << '\n';
}