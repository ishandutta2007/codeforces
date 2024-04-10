 #include <bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define ll long long 
#define mp make_pair

const long long INFLL = 1e18;
const int INF = 1e9 + 1;

int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &c : a) cin >> c;
        vector<string> ans(n);
        ans[0] = "1";
        vector<int> usd(n);
        for (int i = 1; i < n; i++) {
            if (a[i] == 1) {
                ans[i] = ans[i - 1] + ".1";
                continue;
            }
            for (int j = i - 1; j >= 0; j--) {
                if (usd[j]) continue;
                usd[j] = 1;
                if (a[i] == a[j] + 1) {
                    ans[i] = ans[j];
                    while (ans[i].size() && ans[i].back() != '.') {
                        ans[i].pop_back();
                    }
                    ans[i] += to_string(a[i]);
                    break;
                }
            }
        }
        for (auto &c : ans) cout << c << "\n";
    }
    return 0;
}