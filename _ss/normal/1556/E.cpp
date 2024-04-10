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

struct RMQ1
{
    ll spr[20][N], lg[N];

    void build(ll a[], int n)
    {
        for (int i = 1; i <= n; ++i)
        {
            spr[0][i] = a[i];
            int x = i;
            while (x > 1) lg[i]++, x >>= 1;
        }
        for (int i = 1; i <= lg[n]; ++i)
            for (int j = 1; j <= n - (1 << i) + 1; ++j)
                spr[i][j] = min(spr[i - 1][j], spr[i - 1][j + (1 << (i - 1))]);
    }

    ll rmq(int l, int r)
    {
        int k = lg[r - l + 1];
        return min(spr[k][l], spr[k][r - (1 << k) + 1]);
    }
} tab1;

struct RMQ2
{
    ll spr[20][N], lg[N];

    void build(ll a[], int n)
    {
        for (int i = 1; i <= n; ++i)
        {
            spr[0][i] = a[i];
            int x = i;
            while (x > 1) lg[i]++, x >>= 1;
        }
        for (int i = 1; i <= lg[n]; ++i)
            for (int j = 1; j <= n - (1 << i) + 1; ++j)
                spr[i][j] = max(spr[i - 1][j], spr[i - 1][j + (1 << (i - 1))]);
    }

    ll rmq(int l, int r)
    {
        int k = lg[r - l + 1];
        return max(spr[k][l], spr[k][r - (1 << k) + 1]);
    }
} tab2;

ll ps[N], n, q, a[N], b[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 1; i <= n; ++i) ps[i] = ps[i - 1] + b[i] - a[i];
    tab1.build(ps, n);
    tab2.build(ps, n);
    for (int i = 1, l, r; i <= q; ++i)
    {
        cin >> l >> r;
        ll mn = tab1.rmq(l, r) - ps[l - 1];
        ll mx = tab2.rmq(l, r) - ps[l - 1];
        if (mn < 0 || ps[r] - ps[l - 1] != 0) cout << "-1\n";
        else cout << mx << "\n";
    }
    return 0;
}