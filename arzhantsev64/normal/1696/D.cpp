#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define pt pair<int, int>
#define x first
#define y second

const int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    if (n == 1) {
        cout << 0 << '\n';
        return;
    }

    if (a[1] < a[0]) {
        for (int i = 0; i < n; ++i)
            a[i] = n + 1 - a[i];
    }

    int cur = 0;
    int it = 0;
    int ans = 0;
    int dir = 1;

    vector<bool> was(n + 1);
    int cur_max = n;
    int cur_min = 1;

    while (cur != n - 1) {
        int maxx = cur;
        for (int i = cur + 1; i < n; ++i) {
            if (dir * a[i] < dir * a[cur])
                break;

            if (dir * a[i] > dir * a[maxx])
                maxx = i;

            if ((dir == 1 && a[i] == cur_max) || (dir == -1 && a[i] == cur_min))
                break;
        }

        for (int i = cur; i <= maxx; ++i)
            was[a[i]] = 1;

        if (maxx != n - 1) {
            while (was[cur_max])
                cur_max--;
            while (was[cur_min])
                cur_min++;
        }

        cur = maxx;
        // cout << cur << ' ' << cur_min << ' ' << cur_max << endl;
        ans++;

        dir *= -1;
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
         solve();

    return 0;
}

/*

7 4 8 1 6 10 3 5 2 9
*/