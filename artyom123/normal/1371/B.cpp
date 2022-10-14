#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, r;
        cin >> n >> r;
        if (r <= n - 1) {
            cout << r * (r + 1) / 2 << "\n";
            continue;
        }
        ll lol = n * (n - 1) / 2;
        r -= n - 1;
        cout << lol + 1 << "\n";
    }
    return 0;
}