#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

const int N = 100005;

int a[N], p[20][N], lg[N];
int dp[N];

int query(int l, int r) {
    int logg = lg[r - l + 1];
    return min(p[logg][l], p[logg][r - (1 << (logg)) + 1]);
}

main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int n, c;
    cin >> n >> c;
    lg[1] = 0;
    for (int i = 2; i < N; i++) {
        lg[i] = lg[i / 2] + 1;
    }
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        p[0][i] = a[i];
    }
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            if (j + (1 << (i - 1)) >= N) continue;
            p[i][j] = min(p[i - 1][j], p[i - 1][j + (1 << (i - 1))]);
        }
    }
    for (int i = c; i <= n; i++) {
        dp[i] = max(dp[i - 1], dp[i - c] + query(i - c + 1, i));
    }
    cout << sum - dp[n];
    return 0;
}