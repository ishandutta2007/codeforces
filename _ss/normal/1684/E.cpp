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
        int n, k;
        map<int, int> cnt;
        cin >> n >> k;
        for (int i = 1, x; i <= n; ++i) cin >> x, cnt[x]++;
        int mex = 0;
        while (mex < n && (cnt.count(mex) > 0 || k > 0))
        {
            if (cnt.count(mex) == 0) k--;
            mex++;
        }
        int slot = mex;
        vi vt;
        for (pii pa : cnt)
            if (pa.fi < mex) slot--;
            else vt.eb(pa.se);
        sort(all(vt));
        int res = vt.size();
        for (int x : vt)
            if (x <= slot)
            {
                slot -= x;
                res--;
            }
        cout << res << "\n";
    }
    return 0;
}