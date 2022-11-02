#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 3e6 + 123;
const int mod = 1e9 + 9;
int n;
int a[1010][1010];
string s;
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < n; j++) {
            a[i][j] = s[j] - '0';
        }
    }
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < n; j++) {
            a[i][j] ^= s[j] - '0';
        }
    }
    for(int i = 1; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if(a[i][j] != a[0][j])++cnt;
        }
        if(cnt == 0 || cnt == n) {
            continue;
        }
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}
int main() {
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }

    return 0;
}