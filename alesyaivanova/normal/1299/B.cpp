#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int, int>
#define mp make_pair
#define ff first
#define ss second
#define ld long double
#define matr vector<vector<int> >
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 1e5 + 9;
pii p[maxn];
int n;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i].ff >> p[i].ss;
    if (n % 2 == 1)
    {
        cout << "NO";
        return 0;
    }
    p[n] = p[0];
    bool fl = 1;
    for (int i = 0; i < n / 2; i++)
    {
        if (p[i + 1].ff - p[i].ff != p[i + n / 2].ff - p[i + n / 2 + 1].ff)
            fl = 0;
        if (p[i + 1].ss - p[i].ss != p[i + n / 2].ss - p[i + n / 2 + 1].ss)
            fl = 0;
    }
    if (fl)
        cout << "YES";
    else
        cout << "NO";
}