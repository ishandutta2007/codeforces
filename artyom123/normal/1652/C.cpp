#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define ld long double
#define pb emplace_back
#define ll long long

const ll INFLL = 1e18;
const int INF = 1e9 + 1;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    multiset<ll> now;
    ll s = 0;
    for (auto &c : a) {
        cin >> c;
        s += c;
    }
    now.insert(s);
    sort(all(a));
    reverse(all(a));
    for (auto &c : a) {
        if (now.empty()) {
            cout << "NO\n";
            return;
        }
        while ((int)now.size() <= n && *now.rbegin() > c) {
            ll x = *now.rbegin();
            now.erase(now.find(x));
            now.insert(x / 2);
            now.insert((x + 1) / 2);
        }
        if (*now.rbegin() < c) {
            cout << "NO\n";
            return;
        }
        if ((int)now.size() > n) {
            cout << "NO\n";
            return;
        }
        now.erase(now.find(c));
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}