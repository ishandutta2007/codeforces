#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int brr[100005];

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pii> arr;
        for (int i = 1; i <= n; ++i) {
            int x, cnt = 1;
            cin >> x;
            while (x % m == 0)
                x /= m, cnt *= m;
            if (!arr.empty() && arr.back().X == x)
                arr.back().Y += cnt;
            else
                arr.pb(pii(x, cnt));
        }
        int k;
        cin >> k;
        for (int i = 1; i <= k; ++i) {
            cin >> brr[i];
        }
        int flag = 1, j = 0;
        for (int i = 1; i <= k; ++i) {
            if (j == SZ(arr)) {
                flag = 0;
                break;
            }
            if (brr[i] % arr[j].first != 0) {
                flag = 0;
                break;
            }
            int f = brr[i] / arr[j].first, cnt = 1;
            while (f % m == 0)
                f /= m, cnt *= m;
            if (f > 1) {
                flag = 0;
                break;
            }
            if (arr[j].second < cnt) {
                flag = 0;
                break;
            }
            arr[j].second -= cnt;
            if (arr[j].second == 0) 
                ++j;
        }
        if (flag && j == SZ(arr))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}