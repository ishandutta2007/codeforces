#include <algorithm>
#include <bitset>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int Nmax = 100005;

int A[Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif

    cin.sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    if (K < (N / 2) || (K > 0 && N < 2))
    {
        cout << "-1\n";
        return 0;
    }
    if (K == 0)
    {
        cout << "1\n";
        return 0;
    }

    for (int i = 3; i <= N; i++)
        A[i] = i - 2;

    K -= (N / 2) - 1;
    A[1] = ((N - 2 + ((N - 2) % K > 0)) / K + 1) * K;
    A[2] = A[1] + K;

    for (int i = 1; i <= N; i++)
        cout << A[i] << " ";
    cout << "\n";
}