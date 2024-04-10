#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

using namespace std;

const int maxn = 1e5 + 9;
int a[maxn];
int len1[maxn];
int len2[maxn];
int pref[maxn];
bool ok[maxn];
int n;

void solve() {
    len1[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        len1[i] = 1;
        if (a[i + 1] < a[i])
            len1[i] = len1[i + 1] + 1;
    }
    len2[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        len2[i] = 1;
        if (a[i + 1] > a[i])
            len2[i] = len2[i + 1] + 1;
    }
    pref[0] = 1;
    for (int i = 1; i < n; i++) {
        pref[i] = 1;
        if (a[i - 1] < a[i])
            pref[i] = pref[i - 1] + 1;
    }
    int ma = 0;
    for (int i = n - 2; i >= 0; i--) {
        ma = max(ma, len2[i + 1]);
        if (i + 2 < n && a[i + 1] > a[i + 2] && a[i + 1] > a[i])
            ma = max(ma, len1[i + 1]);
        if (ma >= max(pref[i], len1[i])) {
            ok[i] = 0;
            continue;
        }
        int j = i + len1[i] - 1;
        if (len1[i] % 2 == 0 && pref[i] <= max(len1[i], len2[j])) {
            ok[i] = 0;
            continue;
        }
        j--;
        if (j > i && len1[i] % 2 == 1 && pref[i] <= len1[i] - 1) {
            ok[i] = 0;
            continue;
        }
    }
//    for (int i = 0; i < n; i++)
//        cout << ok[i] << " ";
//    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        ok[i] = 1;
    solve();
    reverse(a, a + n);
    reverse(ok, ok + n);
    solve();
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += ok[i];
    cout << ans;
}