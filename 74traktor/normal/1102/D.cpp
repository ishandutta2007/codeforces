#include <bits/stdc++.h>

using namespace std;

int dp[3];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (auto c : s) dp[c - '0']++;
    int what = n / 3;
    if (dp[0] >= what){
        if (dp[1] >= what){
            int Q = what - dp[2];
            int R1 = dp[0] - what, R2 = dp[1] - what;
            for (int i = n - 1; i >= 0; --i){
                if (Q == 0) break;
                if (s[i] != '2'){
                    if (s[i] == '0' && R1 == 0) continue;
                    if (s[i] == '1' && R2 == 0) continue;
                    if (s[i] == '0') R1--;
                    if (s[i] == '1') R2--;
                    s[i] = '2';
                    Q--;
                }
            }
        }
        else if (dp[2] >= what){
            int Q = what - dp[1];
            for (int i = 0; i < n; ++i){
                if (Q == 0) continue;
                if (s[i] == '2' && dp[2] > what){
                    s[i] = '1';
                    dp[2]--;
                    Q--;
                }
            }
            for (int i = n - 1; i >= 0; --i){
                if (Q == 0) continue;
                if (s[i] == '0' && dp[0] > what){
                    s[i] = '1';
                    dp[0]--;
                    Q--;
                }
            }
        }
        else{
            int Q = what - dp[2];
            for (int i = n - 1; i >= 0; --i){
                if (Q == 0) break;
                if (s[i] == '0'){
                    s[i] = '2';
                    Q--;
                }
            }
            Q = what - dp[1];
            for (int i = n - 1; i >= 0; --i){
                if (Q == 0) break;
                if (s[i] == '0'){
                    s[i] = '1';
                    Q--;
                }
            }
        }
    }
    else if (dp[1] >= what){
        if (dp[2] >= what){
            int Q = what - dp[0];
            for (int i = 0; i < n; ++i){
                if (Q == 0) break;
                if (s[i] != '0'){
                    if (s[i] == '1'){
                        if (dp[1] == what) continue;
                        dp[1]--;
                    }
                    else if (s[i] == '2'){
                        if (dp[2] == what) continue;
                        dp[2]--;
                    }
                    s[i] = '0';
                    Q--;
                }
            }
        }
        else{
            int Q = what - dp[0];
            for (int i = 0; i < n; ++i){
                if (Q == 0) break;
                if (s[i] == '1' && dp[0] != what){
                    s[i] = '0';
                    dp[0]++;
                    Q--;
                }
            }
            Q = what - dp[2];
            for (int i = n - 1; i >= 0; --i){
                if (Q == 0) break;
                if (s[i] == '1' && dp[2] != what){
                    s[i] = '2';
                    dp[2]++;
                    Q--;
                }
            }
        }
    }
    else{
        int Q = what - dp[0];
        for (int i = 0; i < n; ++i){
            if (Q == 0) continue;
            if (s[i] == '2' && dp[0] != what){
                s[i] = '0';
                dp[0]++;
                Q--;
            }
        }
        Q = what - dp[1];
        for (int i = 0; i < n; ++i){
            if (Q == 0) continue;
            if (s[i] == '2' && dp[1] != what){
                s[i] = '1';
                dp[1]++;
                Q--;
            }
        }
    }
    cout << s << '\n';
    return 0;
}