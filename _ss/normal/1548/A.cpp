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
int cnt[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; ++i)
    {
        cin >> u >> v;
        cnt[min(u, v)]++;
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) res += (cnt[i] == 0);
    cin >> q;
    for (int i = 1, t, u, v; i <= q; ++i)
    {
        cin >> t;
        if (t == 3)
        {
            cout << res << "\n";
            continue;
        }
        cin >> u >> v;
        u = min(u, v);
        if (t == 1)
        {
            res -= (cnt[u] == 0);
            cnt[u]++;
        }
        else
        {
            cnt[u]--;
            res += (cnt[u] == 0);
        }
    }
    return 0;
}