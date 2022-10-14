#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const ll INF = 2e18 + 1;

const int MAXN = 20;

map<ll, int> v[MAXN][MAXN];

int n, m, half;
ll k;

ll a[MAXN][MAXN];
ll ans = 0;

void calc1(int i, int j, ll now, int cnt) {
    now ^= a[i][j];
    if (cnt == half) {
        v[i][j][now]++;
        return;
    }
    if (i + 1 < n) calc1(i + 1, j, now, cnt + 1);
    if (j + 1 < m) calc1(i, j + 1, now, cnt + 1);
}

void calc2(int i, int j, ll now, int cnt) {
    if (cnt == n + m - 2 - half) {
        ans += v[i][j][k ^ now];
        return;
    }
    if (i > 0) calc2(i - 1, j, now ^ a[i][j], cnt + 1);
    if (j > 0) calc2(i, j - 1, now ^ a[i][j], cnt + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    half = (n + m - 2) / 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    calc1(0, 0, 0, 0);
    calc2(n - 1, m - 1, 0, 0);
    cout << ans;
    return 0;
}