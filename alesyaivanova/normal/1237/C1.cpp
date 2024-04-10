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

const int MAXN = 2007;
int x[MAXN];
int y[MAXN];
int z[MAXN];
int n;
bool used[MAXN];
pair<int, pii> d[MAXN * MAXN];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> z[i];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        for (int e = i + 1; e < n; e++)
        {
            d[j].ff = (x[i] - x[e]) * (x[i] - x[e]) + (y[i] - y[e]) * (y[i] - y[e]) + (z[i] - z[e]) * (z[i] - z[e]);
            d[j].ss.ff = i;
            d[j].ss.ss = e;
            j++;
        }
    }
    sort(d, d + j);
    for (int i = 0; i < j; i++)
    {
        int a = d[i].ss.ff;
        int b = d[i].ss.ss;
        if (!used[a] && !used[b])
        {
            cout << a + 1 << " " << b + 1 << "\n";
            used[a] = 1;
            used[b] = 1;
        }
    }
}