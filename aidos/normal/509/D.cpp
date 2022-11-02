#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld ;
using namespace std;
const int maxn = (int)5e5 + 10;
const int mod = (int) 1e9 + 7;
int n, m;
int table[111][111];
int a[111];
int b[111];
set<int> S[111];
void solve() {
    cin >> n >> m;
    int k = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> table[i][j];
            k = max(k, table[i][j] + 1);
            if(j > 0) {
                S[j].insert(table[i][j] - table[i][0]);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        a[i] = table[i][0];
    }
    set<int> B;
    for(int i = 1; i < m; i++) {
        if(S[i].size() > 2) {
            cout << "NO\n";
            return;
        }
        if(S[i].size() == 1) {
            b[i] = *S[i].begin();
        } else {
            B.insert(*(--S[i].end()) - *S[i].begin());
            b[i] = *S[i].begin();
        }
    }
    if(B.size() > 1) {
        cout << "NO\n";
        return;
    }
    if(B.size() == 1) {
        if(k > *B.begin()) {
            cout << "NO\n";
            return;
        }
        k = *B.begin();
    }
    cout << "YES\n";
    cout << k << "\n";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";

    for(int i = 0; i < m; i++) {
        cout << (b[i] % k + k) % k << " ";
    }
    cout << "\n";
}
int main() {
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}