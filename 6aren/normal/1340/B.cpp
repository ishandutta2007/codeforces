#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 2005;

vector<string> digits = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
string s[N];
bitset<7 * N> dp[N];

int calc(const string &a, const string &b) {
    bool ok = 1;
    int res = 0;
    for (int i = 0; i < 7; i++) {
        if (a[i] == '0' && b[i] == '1') res++;
        if (a[i] == '1' && b[i] == '0') ok = 0;
    }
    return (ok ? res : 1e9);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    dp[n + 1][0] = 1;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= 9; j++) {
            int foo = calc(s[i], digits[j]);
            if (foo == 1e9) continue;
            dp[i] |= (dp[i + 1] << foo);
        }
    }
    if (dp[1][k] == 0) return cout << -1, 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 9; j >= 0; j--) {
            int foo = calc(s[i], digits[j]);
            if (foo > k) continue;
            if (dp[i + 1][k - foo] == 1) {
                cout << j;
                k -= foo;
                break;
            }
        }
    }
    return 0;
}