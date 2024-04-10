#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = (int)2e5 + 10;
int n, k;
int dp[111][211][55][2];
int u[111][211][55][2];
string s;
int get(int pos, int x, int c, int dir) {
    if(c < 0) return -1e9;
    if(pos == n) {
        if(c%2 == 0) return abs(x);
        return -1e9;
    }
    int &res = dp[pos][x + n][c][dir];
    if(u[pos][x + n][c][dir]) {
        return res;
    }
    u[pos][x + n][c][dir] = 1;
    int val = dir? -1: 1;
    res = -1e9;
    if(s[pos] == 'F') {
        res = max(res, get(pos + 1, x + val, c, dir));
        res = max(res, get(pos + 1, x, c-1, dir^1));
    } else {
        res = max(res, get(pos + 1, x + val, c-1, dir));
        res = max(res, get(pos + 1, x, c, dir^1));
    }
    return res;
}
void solve() {
    cin >> s >> k;
    n = s.size();
    cout << get(0, 0, k, 0) << "\n";
}
int main() {
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}