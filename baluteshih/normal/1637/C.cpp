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

int arr[100005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, flag = 0;
        ll ans = 0;
        cin >> n >> arr[1];
        for (int i = 2; i < n; ++i) {
            cin >> arr[i];
            if (arr[i] & 1) {
                ans += (arr[i] + 1) / 2;
            }
            else {
                ans += arr[i] / 2;
            }
            if (arr[i] > 1)
                flag = 1;
        }
        cin >> arr[n];
        if (n == 3 && (arr[2] & 1))
            cout << "-1\n";
        else if (!flag)
            cout << "-1\n";
        else
            cout << ans << "\n";
    }
}