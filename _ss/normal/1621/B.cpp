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
using vll = vector<ll>;

const int N = 1e5 + 10;

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int mx = 0, mn = 1e9 + 1, cmx, cmn;
        map<pii, int> best;
        for (int i = 1, l, r, c; i <= n; ++i)
        {
            cin >> l >> r >> c;
            if ((l < mn) || (l == mn && c < cmn))
            {
                mn = l;
                cmn = c;
            }
            if ((r > mx) || (r == mx && c < cmx))
            {
                mx = r;
                cmx = c;
            }
            pii I = mp(l, r);
            if (!best.count(I)) best[I] = c;
            else best[I] = min(best[I], c);
            int res = cmx + cmn;
            I = mp(mn, mx);
            if (best.count(I)) res = min(res, best[I]);
            cout << res << "\n";
        }
    }
    return 0;
}