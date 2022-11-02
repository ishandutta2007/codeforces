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

const int maxn = 1e4 + 9;
int a[maxn];
int n;

void solve() {
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % n != 0) {
        cout << "-1\n";
        return;
    }
    sum /= n;
    int j = -1;
    for (int i = n - 1; i >= 1; i--) {
        if (a[i] >= i + 1) {
            j = i;
            break;
        }
    }
    vector<pair<pii, int> > ans;
    if (j != -1) {
        ans.pb(mp(j, 0), 1);
        a[j] -= j + 1;
        a[0] += j + 1;
        for (int e = j; e >= 1; e--) {
            if (a[e] % (e + 1) != 0) {
                int x = (e + 1) - a[e] % (e + 1);
                ans.pb(mp(0, e), x);
                a[0] -= x;
                a[e] += x;
            }
            ans.pb(mp(e, 0), a[e] / (e + 1));
            a[0] += a[e];
            a[e] = 0;
        }
    } else {
        j = 0;
    }
    vector<pii> kek;
    for (int e = j + 1; e < n; e++) {
        kek.pb((e + 1) - a[e], e);
    }
    sort(all(kek));
    for (auto x : kek) {
        if (a[0] >= x.ff) {
            ans.pb(mp(0, x.ss), x.ff);
            ans.pb(mp(x.ss, 0), 1);
            a[0] += a[x.ss];
            a[x.ss] = 0;
        } else {
            cout << "-1\n";
            return;
        }
    }
    for (int i = 1; i < n; i++) {
        ans.pb(mp(0, i), sum);
    }
    if ((int)ans.size() > 3 * n) {
        cout << "-1\n";
        return;
    }
    cout << ans.size() << "\n";
    for (auto x : ans)
        cout << x.ff.ff + 1 << " " << x.ff.ss + 1 << " " << x.ss << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}