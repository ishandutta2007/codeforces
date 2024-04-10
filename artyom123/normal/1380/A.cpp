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
        vector<int> a(n), pos(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i]; a[i]--;
            pos[a[i]] = i;
        }
        vector<int> mn(n);
        mn[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--) mn[i] = min(a[i], mn[i + 1]);
        int l = -1, j = -1, k = -1;
        int pr_mn = a[0];
        for (int i = 1; i + 1 < n; i++) {
            if (a[i] > pr_mn && a[i] > mn[i + 1]) {
                l = pos[pr_mn];
                j = i;
                k = pos[mn[i + 1]];
            }
            pr_mn = min(pr_mn, a[i]);
        }
        if (l != -1) cout << "YES\n" << l + 1 << " " << j + 1 << " " << k + 1 << "\n";
        else cout << "NO\n";
    }

    return 0;
}