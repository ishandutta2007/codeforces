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

vector<pii> solve(int n)
{
    if (n == 0) return {};
    int d = n * 3 - 1;
    int m = n * 2 - 1;
    int x = d - 2 * n + 1;
    vector<pii> res;
    for (int i = m; i; --i)
    {
        res.eb(i, x);
        x = x % m + 1;
    }
    return res;
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int m = (n + 1) / 3;
    vector<pii> vt = solve(m);
    m = m * 3 - 1;
    m = max(m, 0);
    for (int i = m + 1; i <= n; ++i) vt.eb(i, i);
    cout << vt.size() << "\n";
    for (pii pa : vt) cout << pa.fi << " " << pa.se << "\n";
    return 0;
}