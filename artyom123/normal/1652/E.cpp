#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define ld long double
#define pb emplace_back
#define ll long long

const ll INFLL = 1e18;
const int INF = 1e9 + 1;
const int K = 350;
const int MAXN = 8e7 + 10;
const int MAXK = 1e5 + 10;

int cnt[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    int ans = n;
    for (int x = -K; x <= K; x++) {
        for (int i = 0; i < n; i++) {
            cnt[a[i] - i * x + K * n]++;
            ans = min(ans, n - cnt[a[i] - i * x + K * n]);
        }
        for (int i = 0; i < n; i++) {
            cnt[a[i] - i * x + K * n] = 0;
        }
    }
    vector<int> id;
    for (int i = 0; i < n; i++) {
        for (int j = max(0, i - K); j < min(n, i + K); j++) {
            if (i == j) continue;
            if ((a[j] - a[i]) % (j - i) != 0) continue;
            cnt[(a[j] - a[i]) / (j - i) + MAXK]++;
            id.pb((a[j] - a[i]) / (j - i) + MAXK);
        }
        for (auto &c : id) {
            ans = min(ans, n - cnt[c] - 1);
            cnt[c] = 0;
        }
        id.clear();
    }
    cout << ans;
    return 0;
}