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

int arr[20005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, z, ans = 0;
        cin >> n >> z;
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
            ans = max(ans, z | arr[i]);
        }
        cout << ans << "\n";
    }
}