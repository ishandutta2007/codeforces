#include <bits/stdc++.h>

using namespace std;

const int MAXN = 101;

vector <int> d;

string dp[MAXN][8];

int main() {
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        for (int mod = 0; mod < 8; mod++) {
            if (mod != 0 && dp[i][mod] == "") {
                continue;
            }
            if ((dp[i][mod][0] != '0' || dp[i][mod] == "0")) {
                dp[i + 1][mod] = dp[i][mod];
            }
            if (dp[i][mod][0] != '0') {
                dp[i + 1][(mod * 10 + (s[i] - '0')) % 8] = dp[i][mod] + s[i];  
            }
        }
    }
    if (dp[n][0] != "") {
        cout << "YES" << endl;
        cout << dp[n][0] << endl;
    } else {
        cout << "NO" << endl;
    }
}