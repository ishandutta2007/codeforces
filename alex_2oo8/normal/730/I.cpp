#include <bits/stdc++.h>

#define prev ololo

using namespace std;

const int MX = 3000;

int a[MX], b[MX], dp[MX + 1][MX + 1], prev[MX + 1][MX + 1];
tuple<int, int, int> c[MX];

int main()
{
    int n, p, s;
    scanf("%d %d %d", &n, &p, &s);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < n; i++) scanf("%d", b + i);

    for (int i = 0; i < n; i++) c[i] = make_tuple(a[i], b[i], i + 1);

    sort(c, c + n);
    reverse(c, c + n);

    for (int i = 1; i <= s; i++) dp[0][i] = -1e9;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= s; j++)
            dp[i][j] = -1e9;

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= s; j++) {
            int k = i - j, v = dp[i][j];
            if (k < p) v += get<0>(c[i]);
            if (v > dp[i + 1][j]) {
                dp[i + 1][j] = v;
                prev[i + 1][j] = 0;
            }

            if (j < s) {
                int v = dp[i][j] + get<1>(c[i]);
                if (v > dp[i + 1][j + 1]) {
                    dp[i + 1][j + 1] = v;
                    prev[i + 1][j + 1] = 1;
                }
            }
        }

    vector<int> P, S;
    for (int i = n, j = s; i > 0; i--) {
        if (prev[i][j] == 0) P.push_back(get<2>(c[i - 1]));
        else {
            S.push_back(get<2>(c[i - 1]));
            j--;
        }
    }

    printf("%d\n", dp[n][s]);
    for (int i = P.size() - p; i < P.size(); i++) printf("%d ", P[i]);
    printf("\n");
    for (int x : S) printf("%d ", x);
    printf("\n");

    return 0;
}