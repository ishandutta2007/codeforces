#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

const int Nmax = 100005;

int A[Nmax], B[Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int N, M;
    scanf("%d%d", &N, &M);

    for (int i = 1; i <= N; i++)
        scanf("%d", &A[i]);

    for (int i = 1; i <= M; i++)
        scanf("%d", &B[i]);

    sort(A + 1, A + N + 1);
    sort(B + 1, B + M + 1);

    long long S = 0, S1 = 0;
    for (int i = 1; i <= N; i++)
        S += A[i];

    for (int i = 1; i < M; i++)
        S1 += min(S, 1LL * B[i]);

    long long Ans = S + S1;

    S = 0, S1 = 0;

    for (int i = 1; i <= M; i++)
        S += B[i];

    for (int i = 1; i < N; i++)
        S1 += min(S, 1LL * A[i]);

    Ans = min(Ans, S + S1);

    cout << Ans << '\n';
}