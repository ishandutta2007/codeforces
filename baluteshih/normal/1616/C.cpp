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

int arr[105];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, ans = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        if (n == 1) {
            cout << "0\n";
            continue;
        }
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j) {
                int tmp = 0;
                for (int k = j + 1; k <= n; ++k)
                    if (arr[k] * (j - i) == (arr[j] - arr[i]) * (k - i) + arr[i] * (j - i))
                        ++tmp;
                ans = max(ans, tmp + 2);
            }
        cout << n - ans << "\n";
    }
}