#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const int INF = 2e9 + 10;
const ld EPS = 1e-9;
const int M = 1e2 + 12;
const int N = 1e6 + 10;

string s[M];
int l[N], r[N];
int d[N][2];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int last = -1;
    fr(i, n) {
        cin >> s[i];
    }
    reverse(s, s + n);
    fr(i, n)
        fr(j, s[i].size())
            if (s[i][j] == '1')
                last = i;
    n = last + 1;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    fill(l, l + n, INF);
    fill(r, r + n, -INF);
    fr(i, n) {
        fr(j, m + 2)
            if (s[i][j] == '1') {
                l[i] = min(l[i], j);
                r[i] = max(r[i], j);
            }
        if (l[i] == INF)
            l[i] = m + 1;
        if (r[i] == -INF)
            r[i] = 0;
    }

    if (n == 1) {
        cout << r[0];
        return 0;
    }

    d[0][0] = 2 * r[0];
    d[0][1] = (m + 1);
    frab(i, 1, n - 1) {
        d[i][0] = min(1 + m + 1 + d[i - 1][1], 1 + d[i - 1][0] + 2 * r[i]);
        d[i][1] = min(1 + m + 1 + d[i - 1][0], 1 + d[i - 1][1] + 2 * (m + 1 - l[i]));
    }
    int ans = 1 + min(d[n - 2][0] + r[n - 1], d[n - 2][1] + (m + 1 - l[n - 1]));
    cout << ans;
}