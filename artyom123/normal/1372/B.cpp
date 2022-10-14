#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define ld long double

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;
const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ansa = 1, ansb = n - 1;
        ll ans = n - 1;
        for (int i = 2; i * i <= n; i++) {
            if (n % i != 0) continue;
            ansa = n / i, ansb = n - n / i;
            break;
        }
        cout << ansa << " " << ansb << "\n";
    }
    return 0;
}