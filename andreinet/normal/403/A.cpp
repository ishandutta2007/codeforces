#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif

    ios :: sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--)
    {
        int N, P;
        cin >> N >> P;

        int M = 2 * N + P, i = 1, j = 2;
        while (M--)
        {
            cout << i << " " << j << "\n";
            j++;
            if (j == N + 1)
                i++, j = i + 1;
        }
    }
}