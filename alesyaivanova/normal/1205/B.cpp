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

const int MAXN = 100009;
int a[MAXN];
const int LG = 60;
vector<int> kek[MAXN];
int n;
int b[MAXN];
bool used[MAXN];
int dist[MAXN];
int inf = 1e9;
int pr[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        for (int e = 0; e < LG; e++)
        {
            if (a[i] & (1ll << e))
            {
                kek[e].pb(i);
                if ((int)kek[e].size() == 3)
                {
                    cout << 3;
                    return 0;
                }
            }
        }
    }
    set<int> lol;
    for (int e = 0; e < LG; e++)
    {
        if ((int)kek[e].size() <= 1)
            continue;
        for (int u : kek[e])
            lol.insert(u);
    }
    int m = 0;
    for (int u : lol)
    {
        b[m] = a[u];
        m++;
    }
    int ans = inf;
    for (int i = 0; i < m; i++)
    {
        for (int e = 0; e < m; e++)
        {
            used[e] = false;
            dist[e] = inf;
        }
        dist[i] = 0;
        used[i] = true;
        pr[i] = i;
        queue<int> q;
        q.push(i);
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (int e = 0; e < m; e++)
            {
                if ((b[e] & b[v]) == 0 || e == v)
                    continue;
                if (!used[e])
                {
                    used[e] = true;
                    dist[e] = dist[v] + 1;
                    pr[e] = v;
                    q.push(e);
                }
                /*else if (dist[e] >= dist[v] && dist[v] + dist[e] + 1 >= 3)
                {
                    //cout << i << " " << v << " " << e << " " << dist[v] << " " << dist[e] << "\n";
                    ans = min(ans, dist[v] + dist[e] + 1);
                }*/
            }
        }
        for (int e = 0; e < m; e++)
        {
            //cout << dist[e] << " ";
            for (int v = e + 1; v < m; v++)
            {
                if ((b[v] & b[e]) && v != pr[e] && e != pr[v] && dist[e] + dist[v] + 1 >= 3)
                    ans = min(ans, dist[e] + dist[v] + 1);
            }
        }
        //cout << "\n";
    }
    if (ans == inf)
        cout << -1;
    else
        cout << ans;
}