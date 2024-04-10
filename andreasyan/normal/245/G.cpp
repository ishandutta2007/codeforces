#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 10004;

int n;
map<string, int> mp;
string rmp[N];

vector<int> a[N];

int q[N];

void solv()
{
    int m;
    cin >> m;
    while (m--)
    {
        string x, y;
        cin >> x >> y;
        if (mp.find(x) == mp.end())
        {
            mp[x] = ++n;
            rmp[n] = x;
        }
        if (mp.find(y) == mp.end())
        {
            mp[y] = ++n;
            rmp[n] = y;
        }
        a[mp[x]].push_back(mp[y]);
        a[mp[y]].push_back(mp[x]);
    }
    cout << mp.size() << endl;
    for (int x = 1; x <= n; ++x)
    {
        for (int i = 1; i <= n; ++i)
            q[i] = 0;
        q[x] = -N;
        for (int i = 0; i < a[x].size(); ++i)
        {
            int h = a[x][i];
            q[h] = -N;
            for (int j = 0; j < a[h].size(); ++j)
            {
                int hh = a[h][j];
                ++q[hh];
            }
        }
        int maxu = -N;
        for (int i = 1; i <= n; ++i)
            maxu = max(maxu, q[i]);
        int ans = 0;
        if (maxu >= 0)
        {
            for (int i = 1; i <= n; ++i)
            {
                if (q[i] == maxu)
                    ++ans;
            }
        }
        cout << rmp[x] << ' ' << ans << endl;
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}