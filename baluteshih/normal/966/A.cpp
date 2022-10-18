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

vector<int> stair, elev;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, cl, ce, v, q;
    cin >> n >> m >> cl >> ce >> v;
    stair.resize(cl), elev.resize(ce);
    for (int &i : stair)
        cin >> i;
    for (int &i : elev)
        cin >> i;
    cin >> q;
    while (q--) {
        int x1, y1, x2, y2;
        int ans = 2e9;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2)  {
            cout << abs(y1 - y2) << "\n";
            continue;
        }
        {
            int lb = lower_bound(ALL(stair), y1) - stair.begin();
            if (lb != 0) {
                ans = min(ans, abs(stair[lb - 1] - y1) + abs(x1 - x2) + abs(stair[lb - 1] - y2));
            }
            if (lb < cl) {
                ans = min(ans, abs(stair[lb] - y1) + abs(x1 - x2) + abs(stair[lb] - y2));
            }
        }
        {
            int lb = lower_bound(ALL(elev), y1) - elev.begin();
            if (lb != 0) {
                ans = min(ans, abs(elev[lb - 1] - y1) + (abs(x1 - x2) - 1) / v + 1 + abs(elev[lb - 1] - y2));
            }
            if (lb < ce) {
                ans = min(ans, abs(elev[lb] - y1) + (abs(x1 - x2) - 1) / v + 1 + abs(elev[lb] - y2));
            }
        }
        cout << ans << "\n";
    }
}