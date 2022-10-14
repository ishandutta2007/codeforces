#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 1e9 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &c : a) cin >> c;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int r = -1, sum = 0;
            for (int l = 0; l < n; l++) {
                if (r < l) {
                    r = l;
                    sum = a[l];
                } else sum -= a[l - 1];
                while (sum < a[i] && r + 1 < n) {
                    r++;
                    sum += a[r];
                }
                if (sum == a[i] && l != r) {
                    ans++;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}