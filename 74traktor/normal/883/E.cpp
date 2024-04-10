#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int t;
    cin >> t;
    vector <int> used_c(26);
    vector <int> used_i(n);
    for(int i = 0; i < n; i++) {
        if(s[i] != '*') {
            used_c[s[i] - 'a'] = 1;
            used_i[i] = 1;
        }
    }
    vector <string> r(t);
    int count_interestring = 0;
    vector <int> sym_inter(26);
    for(int i = 0; i< t; i++) {
        cin >> r[i];
        int fl = 1;
        for(int j = 0; j < n; j++) {
            if(!used_i[j] && used_c[r[i][j] - 'a']) {
                fl = 0;
            }
            if(used_i[j] && r[i][j] != s[j]) {
                fl = 0;
            }
        }
        if (fl) {
            count_interestring++;
            vector <int> used1(26);
            for(int j = 0; j < n; j++) {
                if(!used_i[j] && !used1[r[i][j] - 'a']) {
                    used1[r[i][j] - 'a'] = 1;
                    sym_inter[r[i][j] - 'a']++;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 26; i++) {
        if(sym_inter[i] == count_interestring) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}