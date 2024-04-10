#include <iostream>

using namespace std;

const int NMAX = 4000 + 5;

int n;
int b[NMAX];

int dp[NMAX][NMAX];

int last[1000005];

int main()
{
    cin >> n;
    if (n <= 2) {
        cout << n << '\n';
        return 0;
    }

    for (int i = 1; i <= n; ++ i)
        cin >> b[i];

    int best = 1;
    for (int p = 1; p <= n; ++ p) {
        for (int q = 1; q <= p; ++ q)
            last[b[q]] = 0;

        for (int q = 1; q < p; ++ q) {
            dp[p][q] = 2;
            if (last[b[p]])
                dp[p][q] = 1 + dp[q][last[b[p]]];
            last[b[q]] = q;
            best = max(best, dp[p][q]);
        }
    }

    cout << best << '\n';
    return 0;
}