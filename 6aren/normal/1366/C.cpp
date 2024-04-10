#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 100;

int a[N][N];
int cnt1[N];
int cnt0[N];

void solve() {
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt0, 0, sizeof(cnt0));
    memset(a, 0, sizeof(a));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) cnt1[i + j]++;
            else cnt0[i + j]++;
        }
    }
    int ans = 0;
    for (int i = 0; i <= (n + m - 2) / 2; i++) {
        int j = (n + m - 2) - i;
        if (i == j) continue;
        int c0 = cnt0[i] + cnt0[j];
        int c1 = cnt1[i] + cnt1[j];
        ans += min(c0, c1);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) solve();
    return 0;
}