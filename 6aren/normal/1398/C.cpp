#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

void solve() {
    int n; cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + (s[i] - '0');
    for (int i = 1; i <= n; i++) sum[i] -= i;
    map<int, int> cnt;
    long long ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += cnt[sum[i]];
        cnt[sum[i]]++;
    }
    cout << ans << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) solve();
    return 0;
}