#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld ;
using namespace std;
const int maxn = (int)5e5 + 10;
const int mod = (int) 1e9 + 7;
int n;
int m;
string table[400];
int L[444][444];
int R[444][444];
int D[444][444];
int U[444][444];
int check(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= m) return 0;
    if(table[x][y] == '1') return 0;
    return 1;
}
void solve() {
    cin >> n >> m;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> table[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            L[i][j] = j;
            R[i][j] = j;
            D[i][j] = i;
            U[i][j] = i;
            while(L[i][j] >= 0 && table[i][L[i][j]] == '0') L[i][j]--;
            while(D[i][j] >= 0 && table[D[i][j]][j] == '0') D[i][j]--;
            while(L[i][j] < m && table[i][R[i][j]] == '0') R[i][j]++;
            while(U[i][j] < n && table[U[i][j]][j] == '0') U[i][j]++;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(table[i][j] == '0') {
                int len = 1;
                while(i - len >= 0 && j + len < m && table[i-len][j + len] == '0') {
                    if(D[i][j + len] <= i - len && L[i][j + len] <= j) ans++;
                    if(U[i-len][j] >= i && R[i-len][j] >= j + len) ans++;
                    len++;
                }
                len = 1;
                while(i - len >= 0 && j - len >= 0 && table[i-len][j - len] == '0') {
                    if(D[i][j - len] <= i - len && R[i][j - len] >= j) ans++;
                    if(U[i-len][j] >= i && L[i-len][j] <= j - len) ans++;
                    len++;
                }
                len = 1;
                while(len + i < n && j + len < m && j - len >= 0 && table[i+len][j - len] == '0' && table[i + len][j + len] == '0') {
                    if(R[len + i][j - len] >= j + len) ans++;
                    len++;
                }
                len = 1;
                while(i - len >= 0 && j + len < m && j - len >= 0 && table[i-len][j - len] == '0' && table[i - len][j + len] == '0') {
                    if(R[i - len][j - len] >= j + len) ans++;
                    len++;
                }

                len = 1;
                while(len + j < m && i + len < n && i - len >= 0 && table[i-len][j + len] == '0' && table[i + len][j + len] == '0') {
                    if(U[i - len][j + len] >= i + len) ans++;
                    len++;
                }
                len = 1;
                while(j - len >= 0 && i + len < n && i - len >= 0 && table[i-len][j - len] == '0' && table[i + len][j - len] == '0') {
                    if(U[i - len][j - len] >= i + len) ans++;
                    len++;
                }
            }
        }
    }
    cout << ans << "\n";
}
int main() {
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}