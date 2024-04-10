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

    int N;
    cin >> N;

    for (int i = 1; i < N; i++)
    {
        int x;
        cin >> x;

        A[x] = 1;
    }

    for (int i = 1; i <= N; i++)
    {
        if (!A[i])
            cout << i << "\n";
    }
}