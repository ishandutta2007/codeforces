#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N = 1e5 + 10;

int query(vi vt)
{
    cout << "? ";
    for (int x : vt) cout << x << " ";
    cout << endl;
    int w;
    cin >> w;
    return w;
}
int mark[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    int n, k;
    cin >> n >> k;
    vi vt;
    for (int i = 1; i <= n; ++i) vt.eb(i);
    if ((n & 1) && (k & 1) == 0)
    {
        cout << -1;
        return 0;
    }
    int res  = 0;
    if (n % k == 0)
    {
        for (int i = 1; i <= n / k; ++i)
        {
            vi tmp;
            for (int j = i * k - k + 1; j <= i * k; ++j) tmp.eb(j);
            res ^= query(tmp);
        }
        cout << "! " << res << endl;
        return 0;
    }
    int mx = 2 * k - 2 * max(k - (n - k), 0);
    if (k & 1)
    {
        if (n & 1)
        {
            vi tmp;
            for (int i = 1; i <= k; ++i)
            {
                tmp.eb(vt.back());
                vt.pop_back();
            }
            res ^= query(tmp);
        }
        while (!vt.empty())
        {
            int l = min(mx, (int)vt.size()) / 2;
            vi vt1, vt2;
            for (int i = 1; i <= l; ++i)
            {
                vt1.eb(vt.back());
                vt.pop_back();
            }
            for (int i = 1; i <= l; ++i)
            {
                vt2.eb(vt.back());
                vt.pop_back();
            }
            for (int x : vt1) mark[x] = 1;
            for (int x : vt2) mark[x] = 1;
            for (int i = 1; i <= n && (int)vt1.size() < k; ++i)
                if (!mark[i]) vt1.eb(i), vt2.eb(i);
            for (int x : vt1) mark[x] = 0;
            for (int x : vt2) mark[x] = 0;
            res ^= query(vt1) ^ query(vt2);
        }
    }
    else
    {
        while ((int)vt.size() >= max(k, mx))
        {
            vi tmp;
            for (int i = 1; i <= k; ++i)
            {
                tmp.eb(vt.back());
                vt.pop_back();
            }
            res ^= query(tmp);
        }
        while (!vt.empty())
        {
            int l = min(mx, (int)vt.size()) / 2;
            vi vt1, vt2;
            for (int i = 1; i <= l; ++i)
            {
                vt1.eb(vt.back());
                vt.pop_back();
            }
            for (int i = 1; i <= l; ++i)
            {
                vt2.eb(vt.back());
                vt.pop_back();
            }
            for (int x : vt1) mark[x] = 1;
            for (int x : vt2) mark[x] = 1;
            for (int i = 1; i <= n && (int)vt1.size() < k; ++i)
                if (!mark[i]) vt1.eb(i), vt2.eb(i);
            for (int x : vt1) mark[x] = 0;
            for (int x : vt2) mark[x] = 0;
            res ^= query(vt1) ^ query(vt2);
        }
    }
    cout << "! " << res << endl;
    return 0;
}