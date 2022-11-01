#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        vector<int> b(sz(s), 0);
        b[sz(s) - 1] = (s.back() == 'h');
        for(int j = sz(s) - 2; j >= 0; j--) b[j] = b[j + 1] + (s[j] == 'h');
        for(int j = 0; j < sz(s) - 1; j++) if(s[j] == 's') ans += b[j + 1];
        a[i] = {sz(s) - b[0], b[0]};
    }
    sort(all(a), [](pair<int, int> a, pair<int, int> b){ return ll(a.second) * b.first < ll(a.first) * b.second; });
    //for(int i = 0; i < n; i++) cout << a[i].first << ' ' << a[i].second << endl;
    vector<int> b(n, 0);
    b[n - 1] = a[n - 1].second;
    for(int i = n - 2; i >= 0; i--) b[i] = b[i + 1] + a[i].second;
    for(int i = 0; i < n - 1; i++) ans += ll(a[i].first) * b[i + 1];
    cout << ans;
}