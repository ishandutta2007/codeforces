#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define X first
#define Y second

int input[4000][4000], pre[4001][4001], n;
lli dp[2][4001];

int ask(int x1, int y1, int x2, int y2) {
    return pre[x2][y2] - pre[x1][y2] - pre[x2][y1] + pre[x1][y1];
}

void search(int l, int r, int L, int R, int state) { // l, rL ~ Rstate
    if (r == l) return;
    int mid = l + r >> 1;
    int now = -1;
    dp[state][mid] = INT_MAX;
    for (int i = L; i < R; ++i) {
        if (i >= mid) break;
        if (dp[state][mid] > dp[state ^ 1][i] + ask(i, i, mid, mid)) {
            dp[state][mid] = dp[state ^ 1][i] + ask(i, i, mid, mid);
            now = i;
        }
    }
    assert(now != -1);
    search(l, mid, L, now + 1, state);
    search(mid + 1, r, now, R, state);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    char c;
    cin >> n >> k;
    fop (i,0,n) fop (j,0,n) cin >> c, input[i][j] = c - '0';
    fop (i,0,n+1) {
        int now = 0;
        fop (j,0,n+1) {
            if (!i or !j) pre[i][j] = 0;
            else pre[i][j] = pre[i-1][j] + (now += input[i-1][j-1]);
        }
    }
    fop (i,0,n+1) dp[0][i] = i ? INT_MAX : 0;
    fop (i,1,k+1) {
        search(i, n + 1, i - 1, n, i & 1);
    }
    printf("%d\n", dp[k & 1][n] / 2);
}