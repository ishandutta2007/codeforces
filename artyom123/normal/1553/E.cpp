#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double
#define mp make_pair
#define ull unsigned long long

const int INF = 1e9 + 1;
const ll INFLL = (ll)1e18 + 1;

int solve(vector<int> a, vector<int> b) {
    int n = a.size();
    vector<int> usd(n);
    vector<int> pos(n);
    for (int i = 0; i < n; i++) pos[b[i]] = i;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (usd[i]) continue;
        cnt++;
        int j = i;
        while (!usd[j]) {
            usd[j] = 1;
            j = pos[a[j]];
        }
    }
    return n - cnt;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (auto &c : a) {
            cin >> c;
            c--;
        }
        vector<int> ans;
        vector<int> cnt(n);
        for (int i = 0; i < n; i++) {
            if (a[i] <= i) cnt[i - a[i]]++;
            else cnt[i + n - a[i]]++;
        }
        for (int k = 0; k < n; k++) {
            if (cnt[k] < n / 3) continue;
            vector<int> now;
            for (int j = n - k; j < n; j++) now.pb(j);
            for (int j = 0; j < n - k; j++) now.pb(j);
            if (solve(a, now) <= m) ans.pb(k);
        }
        cout << ans.size() << " ";
        for (auto &c : ans) cout << c << " ";
        cout << "\n";
    }
    return 0;
}