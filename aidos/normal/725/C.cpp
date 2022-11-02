#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = (int)2e5 + 10;
int n;
string s, t;
int was[26];
string c[2];
bool ok() {
    for(int i = 1; i < s.size(); i++) {
        int cnt =  0;
        for(int x = 0; x < 2;x++) {
            for(int y = 0; y < 13; y++) {
                if(c[x][y] == s[i] && c[x^1][y] == s[i-1]) cnt++;
                if(c[x][y] == s[i-1] && c[x^1][y] == s[i]) cnt++;
                if(y == 0) continue;
                if(c[x][y] == s[i] && c[x][y-1] == s[i-1]) cnt++;
                if(c[x][y] == s[i-1] && c[x][y-1] == s[i]) cnt++;
                if(c[x][y] == s[i] && c[x^1][y-1] == s[i-1]) cnt++;
                if(c[x][y] == s[i-1] && c[x^1][y-1] == s[i]) cnt++;
            }
        }
        if(cnt == 0) return 0;
    }
    return 1;
}
void solve() {
    cin >> s;
    was[s[0] - 'A'] = 1;
    int x = -1;
    for(int i = 1; i < s.size(); i++) {
        if(was[s[i] - 'A']) {
            x = s[i] - 'A';
        }
        was[s[i] - 'A'] = 1;
        if(s[i] == s[i-1]) {
            cout << "Impossible\n";
            return;
        }
    }

    int pos = 25;
    while(s[pos] != x + 'A') pos--;
    t = s;
    t.erase(t.begin() + pos);
    t += t;
    for(int i = 0; i < 26; i++) {
        c[0] = "";
        c[1] = "";
        for(int j = 0; j < 26; j++) {
            if(j < 13) c[0] += t[i+j];
            else c[1] = t[i + j] + c[1];
        }
        if(ok()) {
            cout << c[0] << "\n";
            cout << c[1] << "\n";
            return;
        }
    }

    cout << "Impossible\n";
}
int main() {
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}