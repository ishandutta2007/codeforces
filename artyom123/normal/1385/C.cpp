#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;

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
        vector<int> b;
        for (int i = 0; i + 1 < n; i++) {
            if (a[i] < a[i + 1]) b.pb(0);
            if (a[i] > a[i + 1]) b.pb(1);
            if (a[i] == a[i + 1]) b.pb(2);
        }
        int ans = 1;
        bool f = false;
        for (int i = (int)b.size() - 1; i >= 0; i--) {
            if (b[i] == 0) f = true;
            if (b[i] == 2 || b[i] == 0) ans++;
            else {
                if (f) break;
                ans++;
            }
        }
        cout << n - ans << "\n";
    }
    return 0;
}