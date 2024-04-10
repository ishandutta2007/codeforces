#include <bits/stdc++.h>

using namespace std;

const int NMAX = 5000 + 5;

int N;
int a[NMAX];
int cost[NMAX][NMAX];
int best[NMAX][NMAX];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; ++ i)
        cin >> a[i];

    for (int i = N; i; -- i) {
        cost[i][i] = best[i][i] = a[i];
        for (int j = i + 1; j <= N; ++ j) {
            cost[i][j] = cost[i + 1][j] ^ cost[i][j - 1];
            best[i][j] = max(cost[i][j], max(best[i + 1][j], best[i][j - 1]));
        }
    }

    int q = 0;
    cin >> q;
    while (q --) {
        int l, r;
        cin >> l >> r;
        cout << best[l][r] << '\n';
    }
    return 0;
}