#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;
const int maxn = 1e6, INF = 1e9;
using ld = double;
#define x first
#define y second

ll sy, a, b, n, l[maxn], r[maxn], q, p[maxn];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> sy >> a >> b >> n;
    l[n + 1] = r[n + 1] = INF + 1;
    for(int i = 1; i <= n; i++) cin >> l[i] >> r[i];
    for(int i = 1; i <= n + 1; i++) p[i] = p[i - 1] + r[i] - l[i];
    cin >> q;
    cout.precision(7);
    while(q--) {
        int x, y; cin >> x >> y;
        ld x1 = ld(a*y - x*sy) / (y - sy);
        ld x2 = ld(b*y - x*sy) / (y - sy);
        ld k = (b - a) / (x2 - x1);
        int lf = 0, rg = n + 1;
        while(lf < rg) {
            int md = (lf + rg + 1) >> 1;
            if(r[md] <= x1) lf = md;
            else rg = md - 1;
        }
        int L = lf;
        lf = 0, rg = n + 1;
        while(lf < rg) {
            int md = (lf + rg) >> 1;
            if(l[md] >= x2) rg = md;
            else lf = md + 1;
        }
        int R = lf;
        if(L + 1 == R) cout << fixed << ld(0) << '\n';
        else if(L + 2 == R) {
            cout << fixed << k * (min(x2, ld(r[L + 1])) - max(x1, ld(l[L + 1]))) << '\n';
        } else {
            cout << fixed << k * ((min(x2, ld(r[R - 1])) - l[R - 1]) + (r[L + 1] - max(x1, ld(l[L + 1]))) + (L + 2 <= R - 2 ? p[R - 2] - p[L + 1] : 0))  << '\n';
        }
    }
}