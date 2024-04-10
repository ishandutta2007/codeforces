#include <bits/stdc++.h>

using namespace std;

int dp[200005][3];
int inf = 1e9;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    map < char, int > T;
    T['G'] = 0;
    T['R'] = 1;
    T['B'] = 2;
    map < int, char > W;
    W[0] = 'G';
    W[1] = 'R';
    W[2] = 'B';
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < 3; ++j) dp[i][j] = inf;
    }
    for (int j = 0; j < 3; ++j){
        if (W[j] == s[0]) dp[0][j] = 0;
        else dp[0][j] = 1;
    }
    for (int i = 1; i < n; ++i){
        for (int j = 0; j < 3; ++j){
            for (int p = 0; p < 3; ++p){
                if (p == j) continue;
                if (W[j] == s[i]) dp[i][j] = min(dp[i][j], dp[i - 1][p]);
                else dp[i][j] = min(dp[i][j], dp[i - 1][p] + 1);
            }
        }
    }
    cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2])) << endl;
    int ind = n - 1, pos = 0;
    for (int j = 0; j < 3; ++j){
        if (dp[ind][j] < dp[ind][pos]) pos = j;
    }
    string s2 = "";
    while (ind > 0){
        s2 += W[pos];
        for (int p = 0; p < 3; ++p){
            if (p == pos) continue;
            if (W[pos] == s[ind]){
                if (dp[ind][pos] == dp[ind - 1][p]){
                    pos = p;
                    break;
                }
            }
            else{
                if (dp[ind][pos] == dp[ind - 1][p] + 1){
                    pos = p;
                    break;
                }
            }
        }
        ind -= 1;
    }
    s2 += W[pos];
    for (int i = n - 1; i >= 0; --i) cout << s2[i];
    return 0;
}