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
        int n;
        ll ans = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> arr[i];
        for (int i = 1; i <= n; ++i)
            for (int j = i; j <= n; ++j)
                for (int k = i; k <= j; ++k)
                    if (arr[k] == 0)
                        ans += 2;
                    else
                        ++ans;
        cout << ans << "\n";
    }
}