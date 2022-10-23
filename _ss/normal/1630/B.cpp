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

const int N = 2e5 + 10;
int n, cnt[N], k, a[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cnt[i] = 0;
        for (int i = 1, x; i <= n; ++i) cin >> x, cnt[x]++, a[i] = x;
        pii best = mp(1, n + 1);
        for (int l = 1, r = 1, s = 0; l <= n; ++l)
        {
            while (r <= n && s - (n - s) < k) s += cnt[r++];
            if (s - (n - s) < k) break;
            if (r - l < best.se - best.fi) best = mp(l, r);
            s -= cnt[l];
        }
        best.se--;
        cout << best.fi << " " << best.se << "\n";
        int l = 0;
        for (int i = 1; i < k; ++i)
        {
            int s = 0, prv = l;
            while (s <= 0)
            {
                l++;
                if (best.fi <= a[l] && a[l] <= best.se) s++;
                else s--;
            }
            cout << prv + 1 << " " << l << "\n";
        }
        cout << l + 1 << " " << n << "\n";
    }
    return 0;
}