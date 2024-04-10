#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

const int Nmax = 300005;

int A[Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; ++i) {
        scanf("%d", &A[i]);
    }

    sort(A + 1, A + N + 1);
    long long S = 0;

    for (int i = N; i; --i)
        S += 1LL * A[i] * (min(N - 1, i) + 1);

    cout << S << '\n';
}