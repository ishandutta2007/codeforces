#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100000 + 5;
typedef long long int lint;

int N;
int v[NMAX];
lint dp1[NMAX];
int v1[NMAX];
lint dp2[NMAX];
int v2[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> N;

    for (int i = 1; i <= N; ++ i)
        cin >> v[i];

    for (int i = 1; i <= N; ++ i) {
        v1[i] = max(v1[i - 1] + 1, v[i]);
        dp1[i] = dp1[i - 1] + v1[i] - v[i];
    }
    for (int i = N; i; -- i) {
        v2[i] = max(v2[i + 1] + 1, v[i]);
        dp2[i] = dp2[i + 1] + v2[i] - v[i];
    }

    lint best = numeric_limits <lint> :: max();
    for (int i = 1; i <= N; ++ i)
        best = min(best, dp1[i] + dp2[i] - v1[i] - (v2[i] - v[i]) + max(v1[i], v2[i]));

    cout << best << '\n';
    return 0;
}