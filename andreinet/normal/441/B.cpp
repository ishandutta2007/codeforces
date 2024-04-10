#include <iostream>
#include <cstdio>

using namespace std;

const int Nmax = 3005;

int A[Nmax];

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
    {
        int x, y;
        cin >> x >> y;

        A[x] += y;
    }

    int Sol = 0;
    for (int i = 1; i <= 3001; i++)
    {
        int x = M;

        if (x > A[i - 1])
        {
            Sol += A[i - 1];

            x -= A[i - 1];
            A[i - 1] = 0;
        }
        else
        {
            Sol += x;

            A[i - 1] -= x;
            x = 0;
        }

        if (x > A[i])
        {
            Sol += A[i];

            x -= A[i];
            A[i] = 0;
        }
        else
        {
            Sol += x;

            A[i] -= x;
            x = 0;
        }
    }

    cout << Sol << "\n";
}