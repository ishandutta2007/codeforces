#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

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
        unordered_map<int, int> cnt;
        int ans = 0;
        for (auto &c : a) {
            cin >> c;
        }
        sort(all(a));
        reverse(all(a));
        for (auto &c : a) {
            if (c % 2 == 1) continue;
            int x = c;
            int d = 0;
            int y = x;
            while (y % 2 == 0) {
                d++;
                y /= 2;
            }
            ans += d;
            while (x <= INF) {
                if (cnt[x]) {
                    ans -= d;
                    break;
                }
                x *= 2;
            }
            cnt[c]++;
        }
        cout << ans << "\n";
    }
    return 0;
}