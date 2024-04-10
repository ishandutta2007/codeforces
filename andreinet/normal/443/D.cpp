#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif

    ios :: sync_with_stdio(false);

    int N;
    cin >> N;

    vector<double> P(N);
    for (int i = 0; i < N; i++)
        cin >> P[i];

    sort(P.rbegin(), P.rend());

    double Sol = 0;
    for (int i = 0; i < N; i++)
    {
        double p1 = P[i], p2 = 1 - P[i];
        Sol = max(Sol, p1);

        for (int j = i + 1; j < N; j++)
        {
            p1 = p1 * (1 - P[j]) + p2 * P[j];
            p2 = p2 * (1 - P[j]);

            Sol = max(Sol, p1);
        }
    }

    cout << setprecision(10) << fixed;
    cout << Sol << "\n";
}