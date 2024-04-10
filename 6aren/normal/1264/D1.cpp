#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define count fjkadkdfbadkjdk

const int MOD = 998244353;
const int N = 2005;

string s;
int n;
int dp[N][N];
int Count[N];

int power(int x, int y) {
    if (y == 0) return 1;
    int temp = power(x, y / 2);
    temp = 1LL * temp * temp % MOD;
    if (y % 2) temp = 1LL * temp * x % MOD;
    return temp;
}

int solve(int l, int r) {
    if (l >= r) {
        return (dp[l][r] = 0);
    }
    if (dp[l][r] != -1) return dp[l][r];
    #define get(l, r) (Count[r] - Count[l - 1])
    int res = 0;
    if (s[l] != '(') res = (res + solve(l + 1, r)) % MOD;
    if (s[r] != ')') res = (res + solve(l, r - 1)) % MOD;
    if (s[l] != '(' && s[r] != ')') res = ((res - solve(l + 1, r - 1)) % MOD + MOD) % MOD;
    if (s[l] != ')' && s[r] != '(') {
        res = (res + solve(l + 1, r - 1)) % MOD;
        res = (res + power(2, get(l + 1, r - 1))) % MOD;
    }
    return (dp[l][r] = res);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    n = s.size();
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        Count[i] = Count[i - 1] + (s[i] == '?');
        //cout << i << ' ' << Count[i] << endl;
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(1, n) << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            //cout << i << ' ' << j << ' ' << dp[i][j] << endl;
        }
    }
    return 0;
}