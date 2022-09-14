#include <bits/stdc++.h>
#define fs first
#define sc second

using namespace std;

const int MAXN = 200000;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m, k;
    vector<int> edge[MAXN];
    cin >> n >> m >> k;
    int c[MAXN];
    for (int i = 0; i < n; i++)
        c[i] = 0;
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        c[a - 1] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    set< pair<double, int> > s;
    int p[MAXN], q[MAXN];
    int l = 0;
    int x[MAXN];
    for (int i = 0; i < n; i++)
    {
        p[i] = 0, q[i] = 0;
        x[i] = 0;
        for (int j = 0; j < (int)edge[i].size(); j++)
        {
            if (c[edge[i][j]] == 0)
                p[i]++;
            q[i]++;
        }
        if (c[i] == 0)
        {
            x[i] = 1;
            l++;
            if (q[i] != 0)
                s.insert(make_pair((double)p[i] / q[i], i));
            else
                s.insert(make_pair((double)0, i));
        }
    }
    int u = 0;
    double v = 0;
    pair<double, int> t;
    int w;
    for (int i = 0; i < l; i++)
    {
        t = *(s.upper_bound(make_pair(-1, -1)));
        if (v < t.fs)
        {
            v = t.fs;
            u = i;
        }
        w = t.sc;
        s.erase(t);
        x[w] = 0;
        for (int j = 0; j < (int)edge[w].size(); j++)
            if (x[edge[w][j]] == 1)
            {
                int y = edge[w][j];
                t = make_pair((double)p[y] / q[y], y);
                s.erase(t);
                p[y]--;
                t = make_pair((double)p[y] / q[y], y);
                s.insert(t);
            }
    }

    l = 0;
    for (int i = 0; i < n; i++)
    {
        p[i] = 0, q[i] = 0;
        x[i] = 0;
        for (int j = 0; j < (int)edge[i].size(); j++)
        {
            if (c[edge[i][j]] == 0)
                p[i]++;
            q[i]++;
        }
        if (c[i] == 0)
        {
            x[i] = 1;
            l++;
            if (q[i] != 0)
                s.insert(make_pair((double)p[i] / q[i], i));
            else
                s.insert(make_pair((double)0, i));
        }
    }

    for (int i = 0; i < u; i++)
    {
        t = *(s.upper_bound(make_pair(-1, -1)));
        w = t.sc;
        s.erase(t);
        x[w] = 0;
        for (int j = 0; j < (int)edge[w].size(); j++)
            if (x[edge[w][j]] == 1)
            {
                int y = edge[w][j];
                t = make_pair((double)p[y] / q[y], y);
                s.erase(t);
                p[y]--;
                t = make_pair((double)p[y] / q[y], y);
                s.insert(t);
            }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (x[i] == 1)
            ans++;
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++)
    {
        if (x[i] == 1)
            cout << i + 1 << " ";
    }
    cout << endl;
    return 0;
}