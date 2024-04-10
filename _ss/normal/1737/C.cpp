#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;

const int N = 1e5 + 10;

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        vi r(3), c(3);
        cin >> n >> r[0] >> c[0] >> r[1] >> c[1] >> r[2] >> c[2] >> x >> y;
        int cnt = 0;
        for (int v : r)
            if (v == 1 || v == n) cnt++;
        for (int v : c)
            if (v == 1 || v == n) cnt++;
        if (cnt == 4) {
            int cnt2 = 0, cnt3 = 0;
            for (int v : r)
                if (v == x) cnt2++;
            for (int v : c)
                if (v == y) cnt3++;
            if (cnt2 == 2 || cnt3 == 2) cout << "YES\n";
            else cout << "NO\n";
        }
        else {
            vi vt(4);
            for (int i = 0; i < 3; ++i) vt[(r[i] & 1) | ((c[i] & 1) << 1)] = 1;
            vt[(x & 1) | ((y & 1) << 1)] = 1;
            cnt = 0;
            for (int i = 0; i < 4; ++i) cnt += vt[i];
            if (cnt != 4) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}