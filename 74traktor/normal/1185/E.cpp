#include <bits/stdc++.h>

using namespace std;

char a[2005][2005];
vector < pair < int, int > > Q[27];
char tmp[2005];

void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cin >> a[i][j];
    for (int j = 0; j < 26; ++j) Q[j] = {};
    int mx = -1;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (a[i][j] == '.') continue;
            mx = max(mx, a[i][j] - 'a');
            Q[a[i][j] - 'a'].push_back({i, j});
        }
    }
    for (int i = 0; i <= mx; ++i){
        if ((int)Q[i].size() <= 1) continue;
        int ok = 0;
        if (Q[i][0].first == Q[i][1].first) ok = 1;
        for (auto key : Q[i]){
            if (ok == 1){
                if (key.first != Q[i][0].first){
                    cout << "NO" << '\n';
                    return;
                }
            }
            else{
                if (key.second != Q[i][0].second){
                    cout << "NO" << '\n';
                    return;
                }
            }
        }
    }
    //cout << "OK" << endl;
    for (int i = 1; i <= n; ++i){
        vector < int > f;
        vector < int > s;
        vector < int > pref;
        for (int j = 0; j < 26; ++j) f.push_back(m + 7), s.push_back(0);
        pref.push_back(0);
        for (int j = 1; j <= m; ++j) pref.push_back(0);
        for (int j = 1; j <= m; ++j){
            pref[j] = pref[j - 1];
            if (a[i][j] != '.') f[a[i][j] - 'a'] = min(f[a[i][j] - 'a'], j), s[a[i][j] - 'a'] = max(s[a[i][j] - 'a'], j);
            else pref[j]++;
        }
        vector < pair < int, int > > check;
        for (int j = 0; j < 26; ++j){
            if (s[j] != 0){
                check.push_back({f[j], 0});
                check.push_back({s[j], 1});
                if (pref[s[j]] - pref[f[j] - 1] != 0){
                    cout << "NO" << '\n';
                    return;
                }
            }
        }
        sort(check.begin(), check.end());
        vector < int > st;
        int bal = 0, last = 0;
        for (auto key : check){
            if (bal != 0){
                for (int g = last; g < key.first; ++g) tmp[g] = a[i][st.back()];
            }
            if (key.second == 0){
                bal++;
                last = key.first;
                if ((int)st.size() != 0 && a[i][st.back()] > a[i][key.first]){
                    cout << "NO" << '\n';
                    return;
                }
                st.push_back(key.first);
            }
            else{
                tmp[key.first] = a[i][st.back()];
                bal--;
                last = key.first + 1;
                if (f[a[i][key.first] - 'a'] != st.back()){
                    cout << "NO" << '\n';
                    return;
                }
                st.pop_back();
            }
        }
        for (int j = 1; j <= m; ++j){
            if (a[i][j] != '.' && a[i][j] != tmp[j]){
                cout << "NO" << '\n';
                return;
            }
        }
    }
    for (int j = 1; j <= m; ++j){
        vector < int > f;
        vector < int > s;
        vector < int > pref;
        for (int i = 0; i < 26; ++i) f.push_back(n + 7), s.push_back(0);
        pref.push_back(0);
        for (int i = 1; i <= n; ++i) pref.push_back(0);
        for (int i = 1; i <= n; ++i){
            pref[i] = pref[i - 1];
            if (a[i][j] != '.') f[a[i][j] - 'a'] = min(f[a[i][j] - 'a'], i), s[a[i][j] - 'a'] = max(s[a[i][j] - 'a'], i);
            else pref[i]++;
        }
        vector < pair < int, int > > check;
        for (int i = 0; i < 26; ++i){
            if (s[i] != 0){
                check.push_back({f[i], 0});
                check.push_back({s[i], 1});
                if (pref[s[i]] - pref[f[i] - 1] != 0){
                    cout << "NO" << '\n';
                    return;
                }
            }
        }
        sort(check.begin(), check.end());
        vector < int > st;
        int bal = 0, last = 0;
        for (auto key : check){
            if (bal != 0){
                for (int i = last; i < key.first; ++i) tmp[i] = a[st.back()][j];
            }
            if (key.second == 0){
                bal++;
                last = key.first;
                if ((int)st.size() != 0 && a[st.back()][j] > a[key.first][j]){
                    cout << "NO" << '\n';
                    return;
                }
                st.push_back(key.first);
            }
            else{
                bal--;
                last = key.first + 1;
                if (f[a[key.first][j] - 'a'] != st.back()){
                    cout << "NO" << '\n';
                    return;
                }
                tmp[key.first] = a[st.back()][j];
                st.pop_back();
            }
        }
        for (int i = 1; i <= n; ++i){
            if (a[i][j] != '.' && a[i][j] != tmp[i]){
                cout << "NO" << '\n';
                return;
            }
        }
    }
    cout << "YES" << '\n';
    cout << mx + 1 << '\n';
    for (int i = 0; i <= mx; ++i){
        if ((int)Q[i].size() == 0){
            cout << Q[mx][0].first << " " << Q[mx][0].second << " " << Q[mx].back().first << " " << Q[mx].back().second << '\n';
        }
        else cout << Q[i][0].first << " " << Q[i][0].second << " " << Q[i].back().first << " " << Q[i].back().second << '\n';
    }
}

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}