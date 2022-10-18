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

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        map<pii, int> mp;
        pii mi = pii(-1, -1);
        pii mx = pii(-1, -1);
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            int l, r, c;
            cin >> l >> r >> c;
            if (mp.find(pii(l, r)) != mp.end())
                mp[pii(l, r)] = min(mp[pii(l, r)], c);
            else
                mp[pii(l, r)] = c;
            if (mi.X == -1 || mi.X > l)
                mi.X = l, mi.Y = c;
            else if (mi.X == l)
                mi.Y = min(mi.Y, c);
            if (mx.X == -1 || mx.X < r)
                mx.X = r, mx.Y = c;
            else if (mx.X == r)
                mx.Y = min(mx.Y, c);
            if (mp.find(pii(mi.X, mx.X)) != mp.end())
                cout << min(mi.Y + mx.Y, mp[pii(mi.X, mx.X)]) << "\n";
            else
                cout << mi.Y + mx.Y << "\n";
        }
    }
}