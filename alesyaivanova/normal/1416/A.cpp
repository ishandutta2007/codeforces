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

const int maxn = 3e5 + 9;
int a[maxn];
int n;
int d[maxn];
int lst[maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        d[i] = -1;
        lst[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        int x = a[i];
        d[x] = max(d[x], i - lst[x]);
        lst[x] = i;
    }
    for (int i = 0; i < n; i++) {
        if (lst[i] != -1)
            d[i] = max(d[i], n - lst[i]);
    }
    vector<pii> ok;
    for (int i = n - 1; i >= 0; i--) {
        //cout << "! " << i << " " << d[i] << "\n";
        if (d[i] == -1)
            continue;
        while (!ok.empty() && ok.back().ss >= d[i])
            ok.pop_back();
        ok.pb(i, d[i]);
    }
    int pt = -1;
    for (int i = 1; i <= n; i++) {
        while (pt + 1 < (int)ok.size() && ok[pt + 1].ss <= i)
            pt++;
        if (pt == -1)
            cout << "-1 ";
        else
            cout << ok[pt].ff + 1 << " ";
    }
    cout << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}