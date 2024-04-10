#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit(x) __builtin_popcount(x)

const int N = (int) 1e5 + 7;
const int INF = (int) 1e9 + 7;
int x[N], y[N];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int t(char c) {
    if (c == 'L') {
        return 2;
    } else if (c == 'R') {
        return 3;
    } else if (c == 'U') {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n;
    string s;
    cin >> s;
    n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        x[i] = x[i + 1] + dx[t(s[i])];
        y[i] = y[i + 1] + dy[t(s[i])];
    }
    int ans = INF;
    if ((abs(x[0]) + abs(y[0])) % 2 == 0) {
        ans = min(ans, (abs(x[0]) + abs(y[0])) / 2);
    }
    int cx = 0, cy = 0;
    for (int i = 0; i < n; i++) {
        cx += dx[t(s[i])], cy += dy[t(s[i])];
        if ((abs(cx + x[i + 1]) + abs(cy + y[i + 1])) % 2 == 0) {
            ans = min(ans, (abs(cx + x[i + 1]) + abs(cy + y[i + 1])) / 2);
        }
    }
    if (ans == INF) {
        puts("-1");
    } else {
        cout << ans << '\n';
    }
}