#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

pair<ii, ii> giao(pair<ii, ii> a, pair<ii, ii> b) {
    return {{max(a.x.x, b.x.x), max(a.x.y, b.x.y)}, {min(a.y.x, b.y.x), min(a.y.y, b.y.y)}};
}

const int N = 150000;

pair<ii, ii> pref[N], suff[N], a[N];
int n;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y, xx, yy;
        cin >> x >> y >> xx >> yy;
        a[i] = {{x, y}, {xx, yy}};
    }
    pref[0] = {{-1e9, -1e9}, {1e9, 1e9}};
    for (int i = 1; i <= n; i++) {
        pref[i] = giao(pref[i - 1], a[i]);
    }
    suff[n + 1] = {{-1e9, -1e9}, {1e9, 1e9}};
    for (int i = n; i >= 1; i--) {
        suff[i] = giao(suff[i + 1], a[i]);
    }
    for (int i = 1; i <= n; i++) {
        pair<ii, ii> foo = giao(pref[i - 1], suff[i + 1]);
        if (foo.x.x <= foo.y.x && foo.x.y <= foo.y.y) {
            return cout << foo.x.x << ' ' << foo.x.y << '\n', 0;
        }
    }
    return 0;
}