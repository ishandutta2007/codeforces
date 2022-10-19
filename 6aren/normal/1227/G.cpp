#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

const int N = 1005;

int n, a[N];
bool res[N][N], ans[N][N];
ii p[N];

bool cmp(ii x, ii y) {
    return x.x > y.x;
}

void solve(int l, int r) {
    if (l > r) return;
    if (a[l] == r - l + 1) {
        res[l][l] = 0;
        for (int i = l + 1; i <= r + 1; i++) {
            res[i][l] = 1;
        }
        for (int i = l + 1; i <= r; i++) {
            if (a[i] == a[l]) {
                a[i]--;
                res[l][i] = 1;
            }
        }
        solve(l + 1, r);
    } else {
        for (int i = r + 1; i >= r + 2 - a[r]; i--) {
            res[i][r] = 1;
        }
        solve(l, r - 1);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = {a[i], i};
    }
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        a[i] = p[i].x;
    }
    solve(1, n);
    int cnt = 0;
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= n; j++) {
            ans[i][p[j].y] = res[i][j];
        }
    }
    cout << n + 1 << '\n';
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
    return 0;
}