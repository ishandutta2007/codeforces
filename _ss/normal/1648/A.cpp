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
vi a[N];
int n, m;

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    map<int, int> cnt2;
    map<int, ll> sum;
    ll res = 0;
    for (int i = 1; i <= n; ++i)
    {
        a[i].resize(m + 1);
        map<int, int> cnt;
        for (int j = 1; j <= m; ++j) cin >> a[i][j], cnt[a[i][j]]++;
        for (pii p : cnt)
        {
            res += ((ll)i * cnt2[p.fi] - sum[p.fi]) * p.se;
            cnt2[p.fi] += p.se;
            sum[p.fi] += (ll)p.se * i;
        }
    }
    cnt2.clear();
    sum.clear();
    for (int i = 1; i <= m; ++i)
    {
        map<int, int> cnt;
        for (int j = 1; j <= n; ++j) cnt[a[j][i]]++;
        for (pii p : cnt)
        {
            res += ((ll)i * cnt2[p.fi] - sum[p.fi]) * p.se;
            cnt2[p.fi] += p.se;
            sum[p.fi] += (ll)p.se * i;
        }
    }
    cout << res;
    return 0;
}