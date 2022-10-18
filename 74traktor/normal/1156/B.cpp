#include <bits/stdc++.h>

using namespace std;

int cnt[27];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i){
        string s;
        cin >> s;
        for (int j = 0; j < 26; ++j) cnt[j] = 0;
        for (auto c : s) cnt[c - 'a']++;
        vector < pair < int, char > > Q;
        for (int j = 0; j < 26; ++j) if (cnt[j] != 0) Q.push_back({cnt[j], char('a' + j)});
        string ans = "";
        int j = 0;
        int pos = -1;
        while (j < (int)Q.size() - j - 1){
            for (int k = 0; k < Q[j].first; ++k) ans += Q[j].second;
            if (j == (int)Q.size() - j - 1) break;
            if (abs(Q[j].second - 'a' - (Q[(int)Q.size() - j - 1].second - 'a')) == 1){
                pos = (int)Q.size() - j - 1;
                break;
            }
            for (int k = 0; k < Q[(int)Q.size() - j - 1].first; ++k) ans += Q[(int)Q.size() - j - 1].second;
            ++j;
        }
        if ((int)Q.size() == 2){
            if (Q[0].second - 'a' + 1 == Q[1].second - 'a'){
                cout << "No answer" << '\n';
                continue;
            }
        }
        if ((int)Q.size() == 3){
            if (Q[0].second - 'a' + 1 == Q[1].second - 'a' && Q[1].second - 'a' + 1 == Q[2].second - 'a'){
                cout << "No answer" << '\n';
                continue;
            }
        }
        if ((int)Q.size() % 2 == 1){
            pos = (int)Q.size() / 2;
            if (abs(Q[0].second - 'a' - (Q[pos].second - 'a')) == 1){
                cout << ans;
                for (int k = 0; k < (int)Q[pos].first; ++k) cout << Q[pos].second;
                cout << '\n';
                continue;
            }
        }
        if (pos != -1) for (int k = 0; k < Q[pos].first; ++k) cout << Q[pos].second;
        cout << ans << '\n';
    }
    return 0;
}