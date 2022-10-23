#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N = 1e5 + 10;
int mark[N], n, k;
pii a[N];
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
        for (int i = 1; i <= 2 * n; ++i) mark[i] = 0;
        for (int i = 1; i <= k; ++i) cin >> a[i].fi >> a[i].se, mark[a[i].fi] = mark[a[i].se]= 1;
        int j = 0, cnt = 0;
        while (cnt <= n - k)
        {
            j++;
            while (mark[j]) ++j;
            cnt++;
        }
        for (int i = 1; i <= 2 * n; ++i)
            if (!mark[i])
            {
                a[++k] = mp(i, j);
                mark[i] = mark[j] = 1;
                while (j <= 2 * n && mark[j]) ++j;
            }
        int res = 0;
        for (int i = 1; i <= n; ++i)
            if (a[i].fi > a[i].se) swap(a[i].fi, a[i].se);
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
                if (a[j].se > a[i].se && a[j].fi < a[i].se) res++;
        cout << res << "\n";
    }
    return 0;
}