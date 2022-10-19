#include <bits/stdc++.h>
using namespace std;

#define int long long
//#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
//#define _USE_MATH_DEFINES
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    set<int> s;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            s.insert(a[j]-a[i]);
        }
    }
    cout << s.size() << '\n';
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}