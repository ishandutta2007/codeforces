#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

const int Nmax = 100005;

int A[Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif

    ios :: sync_with_stdio(false);

    int N, X;
    cin >> N >> X;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    sort(A + 1, A + N + 1);

    long long sol = 0;

    for (int i = 1; i <= N; i++)
    {
        sol += 1LL * X * A[i];
        if (X > 1) X--;
    }

    cout << sol << "\n";
}