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
const int N = 2e5 + 10;

struct RMQ
{
    ll spr[20][N], lg[N];

    void build(ll a[], int n)
    {
        for (int i = 1; i <= n; ++i)
        {
            spr[0][i] = a[i];
            int x = i;
            lg[i] = 0;
            while (x > 1) lg[i]++, x >>= 1;
        }
        for (int i = 1; i <= lg[n]; ++i)
            for (int j = 1; j <= n - (1 << i) + 1; ++j)
                spr[i][j] = __gcd(spr[i - 1][j], spr[i - 1][j + (1 << (i - 1))]);
    }

    ll rmq(int l, int r)
    {
        int k = lg[r - l + 1];
        return __gcd(spr[k][l], spr[k][r - (1 << k) + 1]);
    }
} tab;

ll a[N], b[N], n;

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i < n; ++i) b[i] = abs(a[i] - a[i + 1]);
        n--;
        tab.build(b, n);
        int res = 0;
        for (int i = 1, j = 1; i <= n; ++i)
        {
            j = max(j, i);
            while (j <= n && tab.rmq(i, j) > 1) ++j;
            res = max(res, j - i);
        }
        cout << res + 1 << "\n";
    }
    return 0;
}