#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100007; 
const int INF = (int)1e+9 + 7;
const int MOD = 314000000;

int n, m;
vector <int> minv, maxv;

vector < pair < vector <int>, int > > e[MAXN];
vector < int > c[MAXN];
vector < pair <int, int> > p[MAXN];

priority_queue < pair <int, int> > h;


int dfs(int x)
{
    if (maxv[x] != INF)
        return maxv[x];

//    cout << "\t+" << x << " " << e[x].size() << endl;
    maxv[x] = -2;

    int res = 0;
    for (int i = 0; i < (int)e[x].size(); i++)
    {
        bool flg = true;
        for (int j = 0; flg && j < (int)e[x][i].first.size(); j++)
            flg = minv[e[x][i].first[j]] != -1;
        if (!flg)
            continue;

        int s = e[x][i].second;
        for (int j = 0; j < (int)e[x][i].first.size(); j++)
        {
            int v = dfs(e[x][i].first[j]);
            if (v == -2)
                return maxv[x] = -2;
            s += v;
            if (s >= MOD)
                s = MOD;
        }
//        cout << "\t\ts: " << s << endl;
        if (s > res)
            res = s;
    }
//    cout << "\t-" << x << endl;
    return maxv[x] = res;
}

         
int main()
{
/*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
//*/

    scanf("%d %d", &m, &n);
    minv.resize(n + 1);
    maxv.resize(n + 1);
    for (int i = 0; i <= n; i++)
        minv[i] = maxv[i] = INF;

    for (int i = 1; i <= m; i++)
    {
        int x, k = 0, l;
        scanf("%d %d", &x, &l);
        vector <int> a;

        int ind = e[x].size();

        for (int j = 0; j < l; j++)
        {
            int v;
            scanf("%d", &v);
            if (v == -1)
                k += 1;
            else
            {
                a.push_back(v);
                p[v].push_back(make_pair(x, ind));
            }
        }
        e[x].push_back(make_pair(a, k));
        c[x].push_back(a.size());
        if (a.size() == 0 && k < minv[x])
        {
            minv[x] = k;
            h.push(make_pair(-minv[x], x));
        }
    }

    while (h.size())
    {
        int x = h.top().second, d = -h.top().first;
        h.pop();
        if (minv[x] != d)
            continue;

        for (int i = 0; i < (int)p[x].size(); i++)
        {
            int y = p[x][i].first, ind = p[x][i].second;
//            cout << "\t" << y << " " << ind << " " << c[y][ind] << endl;
            if (--c[y][ind] == 0)
            {
  //              cout << "\t" << y << " " << ind << endl;
                int v = e[y][ind].second;
                for (int j = 0; j < (int)e[y][ind].first.size(); j++)
                {
                    v += minv[e[y][ind].first[j]];
                    if (v >= MOD)
                        v = MOD;
                }
//                cout << v << " " << minv[y] << endl;
                if (v < minv[y])
                {
                    minv[y] = v;
                    h.push(make_pair(-minv[y], y));
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
        if (minv[i] == INF)
            minv[i] = -1;


    for (int i = 1; i <= n; i++)
    {
        if (minv[i] == -1)
        {
            maxv[i] = -1;
            continue;
        }

        if (maxv[i] == INF)
            dfs(i);
    }

    for (int i = 1; i <= n; i++)
        printf("%d %d\n", minv[i], maxv[i]);

    return 0;
}