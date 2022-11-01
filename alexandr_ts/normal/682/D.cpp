#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e3 + 1;
const ll INF = 2e9 + 1;

int d[N][N][12][2];

int main() {
    //freopen("a.in", "r", stdin);
    int n, m, k1;
    cin >> n >> m >> k1;
    string s, t;
    cin >> s >> t;
    fr(i, n)
        fr(j, m)
            fr(k, k1 + 1)
                fr(b, 2) {
                    if (b && !d[i][j][k][b]) continue;
                    d[i][j + 1][k][0] = max(d[i][j + 1][k][0], d[i][j][k][b]);
                    d[i + 1][j][k][0] = max(d[i + 1][j][k][0], d[i][j][k][b]);
                    //d[i + 1][j + 1][k][0] = max(d[i + 1][j + 1][k][0], d[i][j][k][b]);
                    if (s[i] == t[j])
                        if (!b && k < k1)
                            d[i + 1][j + 1][k + 1][1] = max(d[i][j][k][b] + 1, d[i + 1][j + 1][k + 1][1]);
                        else if (b)
                            d[i + 1][j + 1][k][1] = max(d[i][j][k][b] + 1, d[i + 1][j + 1][k][1]);
                }
    int ans = -INF;
    fr(i, n + 1)
        fr(j, m + 1)
            fr(k, k1 + 1)
                fr(b, 2)
                    ans = max(ans, d[i][j][k][b]);
    cout << ans;
}