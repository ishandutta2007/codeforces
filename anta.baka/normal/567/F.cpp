#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()

int n, k;
ll dp[70][35];
string s[100];
int h1[100], h2[100];

bool ok(int a, int b, int l, int r) { //     a  b.       [l..r]  ?
    for(int i = 0; i < k; i++) {
        int p1 = h1[i], p2 = h2[i];
        string rel = s[i];
        if(p1 == p2) { if(rel != "=" && rel != "<=" && rel != ">=") return false; continue; }
        if(p1 == a && p2 == b || p1 == b && p2 == a) { if(rel != "=" && rel != "<=" && rel != ">=") return false; }
        else if(p1 == a || p1 == b) {
            if(l <= p2 && p2 <= r) { if(rel != "<" && rel != "<=") return false; }
            else if(rel != ">" && rel != ">=") return false;
        } else if(p2 == a || p2 == b) {
            if(l <= p1 && p1 <= r) { if(rel != ">" && rel != ">=") return false; }
            else if(rel != "<" && rel != "<=") return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        cin >> h1[i] >> s[i] >> h2[i]; h1[i]--; h2[i]--;
    }
    for(int i = 0; i < 2 * n - 1; i++) dp[i][n - 1] = ok(i, i + 1, i, i + 1);
    for(int x = n - 2; x >= 0; x--)
        for(int i = 0; ; i++) {
                int j = i + 2 * (n - x) - 1;
                if(j >= 2 * n) break;
                if(ok(i, i + 1, i, j)) dp[i][x] += dp[i + 2][x + 1];
                if(ok(i, j, i, j)) dp[i][x] += dp[i + 1][x + 1];
                if(ok(j - 1, j, i, j)) dp[i][x] += dp[i][x + 1];
        }
    cout << dp[0][0];
}