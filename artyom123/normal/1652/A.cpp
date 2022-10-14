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
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    sort(all(a));
    cout << a[n - 1] + a[n - 2] << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}