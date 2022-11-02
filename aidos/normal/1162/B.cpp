#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long long ull;
const int maxn = (int)5e5 + 100;
const ll inf = (1ll<<60);
const int mod2 = (int)998244353;
const int mod = (int)1e9 + 7;
string s;
int n, m;
int a[55][55];
int b[55][55];
void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] > b[i][j]) {
                swap(a[i][j], b[i][j]);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i > 0 && (a[i-1][j] >= a[i][j] || b[i-1][j] >= b[i][j])) {
                cout << "Impossible\n";
                return;
            }
            if(j > 0 && (a[i][j-1] >= a[i][j] || b[i][j-1] >= b[i][j])) {
                cout << "Impossible\n";
                return;
            }
        }
    }
    cout << "Possible\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}