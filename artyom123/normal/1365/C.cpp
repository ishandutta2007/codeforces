#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (auto &c : a) cin >> c;
        for (auto &c : b) cin >> c;
        vector<int> pos1(n + 1);
        vector<int> pos2(n + 1);
        for (int i = 0; i < n; i++) pos1[a[i]] = i;
        for (int i = 0; i < n; i++) pos2[b[i]] = i;
        map<int, int> cnt;
        for (int i = 1; i <= n; i++) {
            int r = 0;
            if (pos2[i] >= pos1[i]) r = pos2[i] - pos1[i];
            else r = n - (pos1[i] - pos2[i]);
            cnt[r]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) ans = max(ans, cnt[i]);
        cout << ans;
    }
    return 0;
}