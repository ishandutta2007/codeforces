#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld ;
using namespace std;
const int maxn = (int)5e5 + 10;
const int mod = (int) 1e9 + 7;
int n;
int m;
string table[1010];
string ans[1010];
set<char> sa[2][1010];
set<char> sb[2][1010];
void check() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(ans[i][j] == table[i][j]) continue;
            if(table[i][j] == '0') continue;
            return;
        }
    }
    for(int i = 0; i < n; i++) cout << ans[i] << "\n";
    exit(0);
}
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> table[i];
        ans[i].resize(m);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(table[i][j] != '0') {
                sa[i % 2][j].insert(table[i][j]);
                sb[j % 2][i].insert(table[i][j]);
            }
        }
    }
    vector<int> p(4);
    for(int i = 0; i < 4; i++) {
        p[i] = i + 1;
    }
    do {
        for(int i = 0; i < n; i++) {
            char x = '0', y = '0';
            if(i % 2 == 0) {
                if(sb[0][i].count(p[0] + '0') || sb[1][i].count(p[1] + '0')) {
                    x = p[0] + '0';
                    y = p[1] + '0';
                } else {
                    x = p[1] + '0';
                    y = p[0] + '0';
                }
            }
            else {
                if(sb[0][i].count(p[2] + '0') || sb[1][i].count(p[3] + '0')) {
                    x = p[2] + '0';
                    y = p[3] + '0';
                } else {
                    x = p[3] + '0';
                    y = p[2] + '0';
                }
            }
            for(int j = 0; j < m; j++) {
                if(j % 2 == 0) ans[i][j] = x;
                else ans[i][j] = y;
            }
        }
        check();
        for(int j = 0; j < m; j++) {
            char x = '0', y = '0';
            if(j % 2 == 0) {
                if(sa[0][j].count(p[0] + '0') || sa[1][j].count(p[1] + '0')) {
                    x = p[0] + '0';
                    y = p[1] + '0';
                } else {
                    x = p[1] + '0';
                    y = p[0] + '0';
                }
            }
            else {
                if(sa[0][j].count(p[2] + '0') || sa[1][j].count(p[3] + '0')) {
                    x = p[2] + '0';
                    y = p[3] + '0';
                } else {
                    x = p[3] + '0';
                    y = p[2] + '0';
                }
            }
            for(int i = 0; i < n; i++) {
                if(i % 2 == 0) ans[i][j] = x;
                else ans[i][j] = y;
            }
        }

        check();
    } while(next_permutation(p.begin(), p.end()));
    cout << 0 << "\n";
}
int main() {
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}