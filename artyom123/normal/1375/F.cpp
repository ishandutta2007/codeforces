#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;
const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<ll> a(3);
    cin >> a[0] >> a[1] >> a[2];
    cout << "First\n";
    while (1) {
        ll mx = max({a[0], a[1], a[2]});
        ll y = 3 * mx - a[0] - a[1] - a[2];
        cout << y << endl;
        int i;
        cin >> i;
        i--;
        if (a[i] == mx) {
            a[i] += y;
            continue;
        }
        a[i] += y;
        cout << mx - min({a[0], a[1], a[2]}) << endl;
        cin >> i;
        return 0;
    }
    return 0;
}