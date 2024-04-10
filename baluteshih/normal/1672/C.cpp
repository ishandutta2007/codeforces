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

int arr[200005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> arr[i];
        int z = 0, ans = 0;
        for (int i = n; i > 1; --i) {
            arr[i] -= arr[i - 1];
            if (arr[i] == 0)
                ++z;
        }
        for (int i = 2; i < n; ++i)
            if (arr[i] == 0 && z > 1) {
                arr[i] = 1, --z;
                if (arr[i + 1] != 0)
                    ++z;
                arr[i + 1] = 0;
                if (i + 2 <= n && arr[i + 2] == 0)
                    arr[i + 2] = 1, --z;
                ++ans;
            }
        cout << ans << "\n";
    }
}