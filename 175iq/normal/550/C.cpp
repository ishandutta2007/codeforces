#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) (int) x.size()
#define all(a) a.begin(), a.end()
#define prev sadasdjksgjkasjdklaj
 
const int MAXN = 105;
 
string s;
int n;
bool dp[MAXN][8];
int prev[MAXN][8];
 
int main() {
 
    getline(cin, s);
    n = sz(s);
 
    memset(prev, -1, sizeof(prev));
 
    dp[0][(s[0] - '0') % 8] = true;
 
    for (int i = 1; i < n; i++) {
        dp[i][(s[i] - '0') % 8] = true;
 
        for (int j = 0; j < 8; j++) {
            if (dp[i - 1][j]) {
                dp[i][( (j*2)%8 + (s[i]-'0')%8 ) % 8] = true;
                prev[i][( (j*2)%8 + (s[i]-'0')%8 ) % 8] = j;
 
                dp[i][j] = true;
                prev[i][j] = j;
            }
        }
    }
 
    for (int i = 0; i < n; i++) {
        if (dp[i][0]) {
            string ans = "";
            int curI = i, curJ = 0;
 
            while (true) {
                if (prev[curI][curJ] == -1 || prev[curI][curJ] != curJ) {
                    ans.append(1, s[curI]);
                }
 
                if (prev[curI][curJ] == -1) break;
 
                curJ = prev[curI][curJ];
                curI--;
            }
 
            puts("YES");
            reverse(all(ans));
            cout << ans << endl;
            return 0;
        }
    }
 
    puts("NO");
 
    return 0;
}