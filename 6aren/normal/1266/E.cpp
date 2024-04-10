#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

const int N = 200005;

int n, a[N], q;
map<ii, int> mp;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n ;i++) {
        cin >> a[i];
        ans += a[i];
    }
    cin >> q;
    while (q--) {
        int s, t, u;
        cin >> s >> t >> u;
        if (mp[{s, t}] == 0) {
            if (u == 0) {
                cout << ans << '\n';
                continue;
            }
            mp[{s, t}] = u;
            a[u]--;
            if (u != 0) if (a[u] >= 0) ans--;
        } else {
            int uu = mp[{s, t}];
            mp[{s, t}] = u;
            a[uu]++;
            if (a[uu] > 0) ans++;
            a[u]--;
            if (u != 0 && a[u] >= 0) ans--;
        }
        cout << ans << '\n';
    }
    return 0;
}