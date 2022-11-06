#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

#define pb push_back
#define all(a) a.begin(),a.end()
#define foi(n) for (int i = 0; i < n; i++)
#define foj(n) for (int j = 0; j < n; j++)
#define fo(i, n) for (int i = 0; i < n; i++)
#define vei vector<int>
#define pii pair<int, int>
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

using namespace std;

void solve() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 1; ; i++) {
        ll x = i * (i + 1) + i * (i - 1) / 2;
        if (x > n) {
            break;
        }
        if ((n - x) % 3 == 0) {
            ans++;
        }
    }
    cout << ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}