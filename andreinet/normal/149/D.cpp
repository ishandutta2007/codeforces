#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
const int Nmax = 705, Mod = 1e9 + 7;

string S;
int Pair[Nmax];
int dp[Nmax][Nmax][5];

int solve(int left, int right, int c = 0) {
    if (left > right) {
        if (c == 0) return 1;
        return 0;
    }
    if (dp[left][right][c] != -1) return dp[left][right][c];
    int& ans = dp[left][right][c];
    ans = 0;

    if (c == 0) {
        for (int i = 1; i < 3; ++i)
            ans = (ans + solve(left, right, i)) % Mod;
        int p = Pair[right];
        int add = 0;
        add = (add + 1LL * (solve(left, p - 1, 0) - solve(left, p - 1, 1)) * (solve(p + 1, right - 1, 0) - solve(p + 1, right - 1, 3))) % Mod;
        add = (add + 1LL * (solve(left, p - 1, 0) - solve(left, p - 1, 2)) * (solve(p + 1, right - 1, 0) - solve(p + 1, right - 1, 4))) % Mod;
        ans = (ans + add) % Mod;
        if (ans < 0) ans += Mod;
    } else {
        int p = Pair[right], l = Pair[left];
        if (c == 1) {
            ans = 1LL * (solve(left, p - 1, 0)) * (solve(p + 1, right - 1, 0) - solve(p + 1, right - 1, 1)) % Mod;
            if (ans < 0) ans += Mod;
        } else if (c == 2) {
            ans = 1LL * (solve(left, p - 1, 0)) * (solve(p + 1, right - 1, 0) - solve(p + 1, right - 1, 2)) % Mod;
            if (ans < 0) ans += Mod;
        } else if (c == 3) {
            ans = 1LL * (solve(left + 1, l - 1, 0) - solve(left + 1, l - 1, 3)) * (solve(l + 1, right, 0)) % Mod;
            if (ans < 0) ans += Mod;
        } else if (c == 4) {
            ans = 1LL * (solve(left + 1, l - 1, 0) - solve(left + 1, l - 1, 4)) * (solve(l + 1, right, 0)) % Mod;
            if (ans < 0) ans += Mod;
        }
    }
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    cin >> S;
    S.insert(S.begin(), 0);

    int N = S.length() - 1;
    vector<int> stk;
    for (int i = 1; i <= N; ++i) {
        if (S[i] == '(') stk.push_back(i);
        else {
            Pair[i] = stk.back();
            Pair[stk.back()] = i;
            stk.pop_back();
        }
    }
    
    memset(dp, -1, sizeof dp);
    cout << solve(1, N) << '\n';

    cerr << solve(1, 4, 1) << '\n';
}