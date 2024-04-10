#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

const int N = 1000005;

int n, m;
string s[N];
vi dp[N];
vi dp2[N];
int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1, 0, 1, -1, 0, 1, -1};

bool check(int k) {
    queue <ii> q;
    for (int i = 0; i <= n+1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            dp2[i][j] = -1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dp[i][j] >= k) {dp2[i][j] = 1; q.push({i, j});} 
        }
    }
    while (!q.empty()) {
        ii pp = q.front();
        q.pop();
        if (dp2[pp.x][pp.y] == k) continue;
        for (int i = 0; i < 8; i++) {
            int u = pp.x + dx[i];
            int v = pp.y + dy[i];
            if (u < 0 || u > n + 1 || v < 0 || v > m + 1) continue;
            if (dp2[u][v] == -1) {
                dp2[u][v] = dp2[pp.x][pp.y] + 1;
                q.push({u, v});
            }
        }
    }
    for (int i = 0; i <= n+1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            if (dp2[i][j] != -1 && s[i][j] == '.') return 0;
            if (dp2[i][j] == -1 && s[i][j] == 'X') return 0;
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    dp[0].resize(m + 3);
    dp2[0].resize(m + 3);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = "." + s[i];
        s[i] = s[i] + ".";
        dp[i].resize(m + 3);
        dp2[i].resize(m + 3);
    }
    dp2[n + 1].resize(m + 3);
    dp[n + 1].resize(m + 3);
    for (int i = 1; i <= m + 2; i++) {
        s[0] += ".";
        s[n + 1] += ".";
    }
    queue<ii> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '.') continue;
            for (int k = 0; k < 8; k++) {
                int u = i + dx[k];
                int v = j + dy[k];
                if (s[u][v] == '.') {
                    dp[i][j] = 1;
                    q.push({i, j});
                    break;
                }
            }
        }
    }
    while (!q.empty()) {
        ii pp = q.front();
        //cout << pp.x << ' ' << pp.y << endl;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int u = pp.x + dx[i];
            int v = pp.y + dy[i];
            //cout << u << ' ' << v << ' ' << dp[u][v] << ' ' << s[u][v] << endl;
            if (dp[u][v] == 0 && s[u][v] == 'X') {
                dp[u][v] = dp[pp.x][pp.y] + 1;
                q.push({u, v});
            }
        }
    }
    int r = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            r = max(r, dp[i][j]);
        }
    }
    int l = 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else r = mid;
    }
    int t = 0;
    for (int i = l; i <= r; i++) {
        if (check(i)) t = i;
    }
    cout << t - 1 << '\n';
    //cout << check(2) << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dp[i][j] >= t) cout << 'X';
            else cout << '.';
        }
        cout << '\n';
    }
    return 0;
}