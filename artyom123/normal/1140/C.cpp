#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb emplace_back
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector <pair<int, int>> a(n);
    for (auto &c : a) {
        cin >> c.se >> c.fi;
    }
    sort(all(a));
    multiset<int> s;
    long long sum = 0;
    long long ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s.size() < k) {
            s.insert(a[i].se);
            sum += a[i].se;
            ans = max(ans, sum * a[i].fi);
            continue;
        }
        if (*s.begin() >= a[i].se) continue;
        sum -= *s.begin();
        sum += a[i].se;
        s.insert(a[i].se);
        s.erase(s.begin());
        ans = max(ans, sum * a[i].fi);
    }
    cout << ans;
    return 0;
}