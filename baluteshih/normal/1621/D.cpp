#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int mp[505][505];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll sum = 0;
        cin >> n;
        for (int i = 1; i <= 2 * n; ++i)
            for (int j = 1; j <= 2 * n; ++j)
                cin >> mp[i][j];
        for (int i = n + 1; i <= 2 * n; ++i)
            for (int j = n + 1; j <= 2 * n; ++j)
                sum += mp[i][j];
        cout << sum + min({mp[2 * n][1], mp[1][2 * n], mp[1][n + 1], mp[n][n + 1], mp[n][2 * n], mp[n + 1][1], mp[n + 1][n], mp[2 * n][n]}) << "\n";
    }
}