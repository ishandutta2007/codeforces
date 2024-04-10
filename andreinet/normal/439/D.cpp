#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

const int Nmax = 100005;

long long A[Nmax], B[Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif

    ios :: sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i <= M; i++)
        cin >> B[i];

    sort(A + 1, A + N + 1);
    sort(B + 1, B + M + 1);

    int i = 1, j = M;
    long long sol = 0;
    A[N + 1] = (1LL << 60);

    while (A[i] < B[j])
    {
        const long long cost1 = 1LL * i * min(A[i + 1] - A[i], B[j] - A[i]);
        const long long cost2 = 1LL * (M - j + 1) * min(B[j] - B[j - 1], B[j] - A[i]);

        if (i < (M - j + 1))
        {
            sol += cost1;
            i++;
        }
        else
        {
            sol += cost2;
            j--;
        }
    }

    cout << sol << "\n";
}