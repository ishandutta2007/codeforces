#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

vector<ll> high[65];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        ll x;
        cin >> x;
        high[__lg(x)].pb(x);
    }
    vector<ll> ans;
    ll nw = 0;
    while (SZ(ans) < n) {
        int flag = 0;
        for (int i = 0; i < 60; ++i)
            if (!(nw >> i & 1) && !high[i].empty()) {
                ans.pb(high[i].back());
                nw ^= high[i].back(); 
                high[i].pop_back();
                flag = 1;
                break;
            }
        if (!flag)
            return cout << "No\n", 0;
    }
    cout << "Yes\n";
    for (int i = 0; i < n; ++i)
        cout << ans[i] << " \n"[i + 1 == n];
    exit(0);
    ll lst = 0;
    for (int i = 0; i < n; ++i)
        cout << (lst ^= ans[i]) << " \n"[i + 1 == n];
}