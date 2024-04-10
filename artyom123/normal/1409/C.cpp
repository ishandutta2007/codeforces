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
const ll INFLL = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        int mx = INF;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((y - x) % (j - i) != 0) continue;
                int d = (y - x) / (j - i);
                vector<int> a(n);
                for (int k = 0; k < n; k++) a[k] = x + (k - i) * d;
                int nowmn = INF, nowmx = -INF;
                for (auto &c : a) {
                    nowmn = min(nowmn, c);
                    nowmx = max(nowmx, c);
                }
                if (nowmn <= 0) continue;
                if (mx > nowmx) {
                    mx = nowmx;
                    ans = a;
                }
            }
        }
        for (auto &c : ans) cout << c << " ";
        cout << "\n";
    }
    return 0;
}