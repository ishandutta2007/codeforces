#include <bits/stdc++.h>

using namespace std;

int t, n, m;

void solve(){
    int type = -1;
    cin >> n >> m;
    bool bad = false;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        if(bad) continue;

        for (int j = 0; j < m; ++j) {
            if(str[j] == '.') continue;
            bool newType = (str[j] == 'W') ^ ((i + j) & 1);
            if(type == -1) type = newType;
            else if(type != newType) bad = true;
        }
    }
    if(bad){
        cout << "NO\n";
        return;
    }
    if(type == -1) type = 0; // All blank

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << ((type ^ ((i + j) & 1)) ? 'W' : 'R');
        }
        cout << '\n';
    }
}

int main(){
    cin >> t;
    while(t--){
        solve();
    }
}