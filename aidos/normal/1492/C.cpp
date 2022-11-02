#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = (int)1e6 + 100;
const ll inf = (1ll<<60);
int n, m;
string s, t;
void solve() {
    cin >> n >> m >> s >> t;
    vector<int> a;
    int j = 0;
    for(int i = 0; i < m; i++) {
        while(s[j] != t[i]) j++;
        a.push_back(j);
        j++;
    }
    j = n-1;
    int ans = 0;
    for(int i = m-1; i > 0; i--) {
        while(s[j] != t[i]) j--;
        ans = max(ans, j - a[i-1]);
        j--;
    }
    cout << ans << "\n";
}
int main() {
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}