#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 100 + 10;

int a[MAXN], b[MAXN], cnt[2];

void solve() {
    int n;
    cin >> n;
    int ans1 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        ans1 += (a[i] ^ b[i]);
        cnt[b[i]] = max(0, cnt[b[i]] - 1);
    }
    cout << min(ans1, cnt[0] + cnt[1] + 1) << '\n';
    cnt[0] = cnt[1] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}