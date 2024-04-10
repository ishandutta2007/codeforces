#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    multiset<int, greater<int>> ms;
    int n;
    cin >> n;
    for (int i = 1; i <= n * n; i++) {
        int u; cin >> u;
        ms.insert(u);
    }
    vector<int> res;
    for (int rep = 1; rep <= n; rep++) {
        auto u = *ms.begin();
        for (int e : res) {
            int foo = __gcd(u, e);
            ms.erase(ms.lower_bound(foo));
            ms.erase(ms.lower_bound(foo));
        }
        ms.erase(ms.lower_bound(u));
        res.pb(u);
    }
    for (int e : res) cout << e << ' ';
    return 0;
}