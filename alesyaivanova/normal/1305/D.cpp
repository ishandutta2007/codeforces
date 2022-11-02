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
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 2007;
vector<int> g[maxn];
int n;
bool used[maxn];

int dfs(int v, int pr)
{
    used[v] = 0;
    int ans = 1;
    for (int to : g[v])
    {
        if (to != pr && used[to])
            ans += dfs(to, v);
    }
    return ans;
}

signed main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 0; i < n; i++)
        used[i] = 1;
    int cnt = n;
    while (cnt >= 3)
    {
        for (int i = 0; i < n; i++)
        {
            if (!used[i])
                continue;
            vector<int> kek;
            for (int to : g[i])
            {
                if (used[to])
                    kek.pb(to);
            }
            if ((int)kek.size() >= 2)
            {
                cout << "? " << kek[0] + 1 << " " << kek[1] + 1 << endl;
                int v;
                cin >> v;
                v--;
                if (v == kek[0])
                    cnt -= dfs(i, kek[0]);
                else if (v == i)
                {
                    cnt -= dfs(kek[0], i);
                    cnt -= dfs(kek[1], i);
                }
                else
                    cnt -= dfs(i, kek[1]);
                break;
            }
        }
    }
    if (cnt == 2)
    {
        vector<int> kek;
        for (int i = 0; i < n; i++)
        {
            if (used[i])
                kek.pb(i);
        }
        cout << "? " << kek[0] + 1 << " " << kek[1] + 1 << endl;
        int v;
        cin >> v;
        cout << "! " << v << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (used[i])
            {
                cout << "! " << i + 1 << endl;
                return 0;
            }
        }
    }
}