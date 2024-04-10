#include <bits/stdc++.h>

using namespace std;

int dp[30];

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    for (int i = 1; i <= n; ++i){
        cin >> s;
        if (i == 1){
            int kol = 1;
            for (int j = 1; j < (int)s.size(); ++j){
                if (s[j] == s[j - 1]) kol++;
                else{
                    dp[s[j - 1] - 'a' + 1] = max(dp[s[j - 1] - 'a' + 1], kol);
                    kol = 1;
                }
            }
            dp[s[(int)s.size() - 1] - 'a' + 1] = max(dp[s[(int)s.size() - 1] - 'a' + 1], kol);
        }
        else{
            bool f = true;
            char c = s[0];
            int kol = 0;
            for (auto key : s) if (key != c) f = false;
            if (f){
                int qq = dp[c - 'a' + 1];
                dp[c - 'a' + 1] = (qq + 1) * (int)s.size() + qq;
                for (int j = 1; j <= 26; ++j){
                    if (char('a' + j - 1) != c) dp[j] = min(dp[j], 1);
                }
                for (int j = 1; j < (int)s.size(); ++j){
                    if (s[j] == s[j - 1]) kol++;
                    else{
                        dp[s[j - 1] - 'a' + 1] = max(dp[s[j - 1] - 'a' + 1], kol);
                        kol = 1;
                    }
                }
                dp[s[(int)s.size() - 1] - 'a' + 1] = max(dp[s[(int)s.size() - 1] - 'a' + 1], kol);
            }
            else{
                char c = s[0], t = s[(int)s.size() - 1];
                int len_pref = 0, len_suf = 0;
                for (int j = 0; j < (int)s.size(); ++j){
                    if (s[j] == c) len_pref++;
                    else break;
                }
                for (int j = (int)s.size() - 1; j >= 0; --j){
                    if (s[j] == t) len_suf++;
                    else break;
                }
                //cout << c << " " << t << " " << len_pref << " " << len_suf << endl;
                if (c == t){
                    if (dp[c - 'a' + 1] != 0) dp[c - 'a' + 1] = len_pref + len_suf + 1;
                    else dp[c - 'a' + 1] = 0;
                    dp[c - 'a' + 1] = max(max(dp[c - 'a' + 1], len_pref + min(dp[c - 'a' + 1], 1)), len_suf + min(dp[t - 'a' + 1], 1));
                }
                else{
                dp[c - 'a' + 1] = len_pref + min(dp[c - 'a' + 1], 1);
                dp[t - 'a' + 1] = len_suf + min(dp[t - 'a' + 1], 1);
                }
                for (int j = 1; j <= 26; ++j){
                    if (char('a' + j - 1) != c && char('a' + j - 1) != t) dp[j] = min(dp[j], 1);
                }
                for (int j = 1; j < (int)s.size(); ++j){
                    if (s[j] == s[j - 1]) kol++;
                    else{
                        dp[s[j - 1] - 'a' + 1] = max(dp[s[j - 1] - 'a' + 1], kol);
                        kol = 1;
                    }
                }
                dp[s[(int)s.size() - 1] - 'a' + 1] = max(dp[s[(int)s.size() - 1] - 'a' + 1], kol);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= 26; ++i) ans = max(ans, dp[i]);
    cout << ans << '\n';
    return 0;
}