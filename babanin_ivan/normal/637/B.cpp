#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof((x)))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp std::make_pair
#define x first
#define y second

typedef std::pair<int, int> PII;
typedef long long ll;
typedef std::pair<ll, ll> PLL;
typedef long double ld;
typedef std::pair<ld, ld> PLD;
typedef std::pair<double, double> PDD;

using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    set<string> s;
    reverse(all(v));
    for (int i = 0; i < n; ++i) {
        if (s.count(v[i])) continue;
        s.insert(v[i]);
        cout << v[i] << "\n";
    }
}



int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}