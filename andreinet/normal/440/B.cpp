#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

const int Nmax = 50005;

long long A[Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif

    int N;
    cin >> N;

    long long s = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
        s += A[i];
    }

    s /= N;
    long long sol = 0;
    for (int i = 1; i < N; i++)
    {
        if (A[i] < s)
        {
            sol += s - A[i];
            A[i + 1] -= (s - A[i]);
            A[i] = s;
        }
        else
        {
            A[i + 1] += A[i] - s;
            sol += A[i] - s;
            A[i] = s;
        }
    }

    cout << sol << "\n";
}