#include <bits/stdc++.h>

using namespace std;

const int NMAX = 3000 + 5;

int N;
int p[NMAX];
double dp[NMAX * NMAX];

double get_val(int where) {
    if (where < 0)
        return 0.0;
    else
        return dp[where];
}

int main()
{
    //freopen("data.in", "r", stdin);

    cin >> N;
    int invs = 0;
    for (int i = 1; i <= N; ++ i)
        cin >> p[i];
    for (int i = 1; i <= N; ++ i)
        for (int j = 1; j < i; ++ j)
            if (p[j] > p[i])
                ++ invs;

    if (invs == 0) {
        cout << fixed << setprecision(12) << 0.0 << endl;
        return 0;
    }
    invs -= 1;
    if (invs == 0) {
        cout << fixed << setprecision(12) << 1.0 << endl;
        return 0;
    }

    for (int i = 1; i <= invs; ++ i) {
        if (i == N * (N - 1LL) / 2)
            dp[i] = 2 + dp[i - 2];
        else {
            if (i - 1 == 0)
                dp[i] = 3 + get_val(i - 2);
            else
                dp[i] = 4 + get_val(i - 2);
        }
    }

    cout << fixed << setprecision(12) << 1 + dp[invs] << endl;
    return 0;
}