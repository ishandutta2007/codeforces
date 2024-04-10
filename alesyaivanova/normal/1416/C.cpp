#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = (1 << 24);
int a[maxn];
int cnt1[maxn];
int n;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    ll kek = 0;
    for (int j = 30; j >= 6; j--) {
        ll c01 = 0, c10 = 0;
        for (int i = 0; i < n; i++) {
            int x = (a[i] >> j);
            if (x & 1)
                c01 += cnt1[x ^ 1];
            else
                c10 += cnt1[x ^ 1];
            cnt1[x]++;
        }
        for (int i = 0; i < n; i++) {
            int x = (a[i] >> j);
            cnt1[x]--;
        }
        if (c10 > c01)
            ans |= (1 << j);
        kek += min(c01, c10);
    }
    for (int j = 5; j >= 0; j--) {
        map<int, int> cnt;
        ll c01 = 0, c10 = 0;
        for (int i = 0; i < n; i++) {
            int x = (a[i] >> j);
            if (x & 1)
                c01 += cnt[x ^ 1];
            else
                c10 += cnt[x ^ 1];
            cnt[x]++;
        }
        if (c10 > c01)
            ans |= (1 << j);
        kek += min(c01, c10);
    }
    cout << kek << " " << ans;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}