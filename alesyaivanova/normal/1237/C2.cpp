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

const int MAXN = 100009;
int x[MAXN];
int y[MAXN];
int z[MAXN];
int n;
set<pii> kek[MAXN];
bool used[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<int> xx;
    map<pii, vector<pii> > w;
    for (int i = 0; i < n; i++)
    {
        used[i] = 1;
        cin >> x[i] >> y[i] >> z[i];
        xx.pb(x[i]);
        w[mp(x[i], y[i])].pb(z[i], i);
    }
    for (auto j = w.begin(); j != w.end(); j++)
    {
        vector<pii> cur = (*j).ss;
        sort(all(cur));
        for (int i = (int)cur.size() - 1; i >= 1; i -= 2)
        {
            cout << cur[i].ss + 1 << " " << cur[i - 1].ss + 1 << "\n";
            used[cur[i].ss] = 0;
            used[cur[i - 1].ss] = 0;
        }
    }
    sort(all(xx));
    xx.resize(unique(all(xx)) - xx.begin());
    int m = xx.size();
    for (int i = 0; i < n; i++)
    {
        if (!used[i])
            continue;
        int j = lower_bound(all(xx), x[i]) - xx.begin();
        kek[j].emplace(y[i], i);
    }
    int pt = 0;
    for (int e = 0; e < m; e++)
    {
        if (kek[e].empty())
            continue;
        int i = (*kek[e].begin()).ss;
        kek[e].erase(kek[e].begin());
        while (kek[pt].empty())
            pt++;
        auto j = kek[pt].lower_bound(mp(y[i], 0ll));
        if (j == kek[pt].end())
            j--;
        cout << i + 1 << " " << (*j).ss + 1 << "\n";
        kek[pt].erase(j);
        e--;
    }
}