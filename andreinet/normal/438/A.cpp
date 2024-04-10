#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int Nmax = 1005;

int A[Nmax];
int N, M;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    long long Sol = 0;
    for (int i = 1; i <= M; i++)
    {
        int x, y;
        cin >> x >> y;

        if (A[x] > A[y])
            Sol += A[y];
        else
            Sol += A[x];
    }


    cout << Sol << "\n";
}