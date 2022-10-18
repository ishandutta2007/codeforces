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

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int odd = (n * k + 1) / 2;
        int even = n * k / 2;
        if (odd % k != 0 || even % k != 0) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 0, j = 1; i < odd / k; ++i)
            for (int c = 1; c <= k; j += 2, ++c)
                cout << j << " \n"[c == k];
        for (int i = 0, j = 2; i < even / k; ++i)
            for (int c = 1; c <= k; j += 2, ++c)
                cout << j << " \n"[c == k];
    }
}