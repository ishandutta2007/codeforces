#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) (x).begin(), (x).end()

const int MAXN = 2e5 + 9;
int f[MAXN];
pii b[MAXN];
int a[MAXN];
int n;
int pr1[MAXN];
int pr2[MAXN];
int dp[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    pii ma(0, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i].ff;
        ma = max(ma, mp(b[i].ff, i));
    }
    bool t = 1;
    for (int i = 0; i < n; i++)
    {
        if (b[i].ff * 2 < ma.ff)
            t = 0;
    }
    if (t)
    {
        for (int i = 0; i < n; i++)
            cout << "-1 ";
        return 0;
    }
    int e = ma.ss;
    for (int i = 0; i < n; i++)
    {
        a[i] = b[(i + e) % n].ff;
        a[i + n] = a[i];
    }
    vector<pii> st;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.back().ff < a[i])
            st.pop_back();
        if (!st.empty())
            pr1[i] = st.back().ss;
        else
            pr1[i] = -1;
        st.pb(a[i], i);
    }
    st.resize(0);
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        int e = lower_bound(all(st), mp(a[i], 0ll)) - st.begin();
        e--;
        if (e < 0)
            pr2[i] = -1;
        else
            pr2[i] = st[e].ss;
        while (!st.empty() && st.back().ff >= 2 * a[i])
            st.pop_back();
        st.pb(2 * a[i], i);
    }
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        //cout << a[i] << " " << pr1[i] << " " << pr2[i] << "\n";
        if (pr2[i] != -1 && (pr2[i] < pr1[i] || pr1[i] == -1))
            dp[i] = pr2[i] - i;
        else if (pr1[i] != -1)
            dp[i] = pr1[i] - i + dp[pr1[i]];
        else
            dp[i] = 2 * n - i;
        //cout << dp[i] << "\n";
    }
    for (int i = 0; i < n; i++)
        cout << dp[(i - e + n) % n] << " ";
}