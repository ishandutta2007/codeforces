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

const int maxn = 1e5 + 9;
int a[maxn];
int b[maxn];
int n;

void solve() {
    cin >> n;
    set<int> pos;
    set<int> used;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        used.insert(i);
    }
    for (int i = 0; i < n; i++) {
        int e = (i + n - 1) % n;
        b[i] = __gcd(a[e], a[i]);
        if (b[i] == 1)
            pos.insert(i);
    }
    int cur = 0;
    vector<int> ans;
    while (!pos.empty()) {
        auto j = pos.upper_bound(cur);
        if (j == pos.end())
            j = pos.begin();
        int e = (*j);
        used.erase(e);
        pos.erase(e);
        ans.pb(e);
        if ((int)used.size() <= 1)
            break;
        auto nxt = used.lower_bound(e);
        if (nxt == used.end())
            nxt = used.begin();
        auto pr = nxt;
        if (pr == used.begin())
            pr = used.end();
        pr--;
        pos.erase(*nxt);
        int new_gcd = __gcd(a[*pr], a[*nxt]);
        b[*nxt] = new_gcd;
        if (new_gcd == 1) {
            pos.insert(*nxt);
        }
        cur = *nxt;
    }
    if ((int)used.size() == 1 && a[*used.begin()] == 1)
        ans.pb(*used.begin());
    cout << ans.size() << " ";
    for (int e : ans) {
        cout << e + 1 << " ";
    }
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}