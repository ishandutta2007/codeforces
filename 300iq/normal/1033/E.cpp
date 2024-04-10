#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>

using namespace std;

typedef long long ll;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 600 + 7;

bool u[N];
int col[N];
vector <int> g[N];

int n;

int gr[N][N];

int cnt = 0;

int ask(vector <int> a)
{
    if (a.empty()) return 0;
    cnt++;
#ifndef ONPC
    cout << "? " << a.size() << endl;
    for (int x : a)
    {
        cout << x + 1 << ' ';
    }
    cout << endl;
    int ret;
    cin >> ret;
    return ret;
#else
    int sum = 0;
    for (int x : a)
    {
        for (int y : a)
        {
            if (y > x)
            {
                sum += gr[x][y];
            }
        }
    }
    return sum;
#endif
}

void dfs(int v)
{
    u[v] = true;
    vector <int> a;
    for (int i = 0; i < n; i++)
    {
        if (!u[i])
        {
            a.push_back(i);
        }
    }
    while (!a.empty())
    {
        auto x = a;
        auto y = a;
        y.push_back(v);
        if (ask(x) == ask(y))
        {
            break;
        }
        else
        {
            int l = -1, r = (int) a.size() - 1;
            while (l < r - 1)
            {
                int m = (l + r) / 2;
                vector <int> x, y;
                for (int i = 0; i <= m; i++) x.push_back(a[i]);
                y = x;
                y.push_back(v);
                if (ask(x) != ask(y))
                {
                    r = m;
                }
                else
                {
                    l = m;
                }
            }
            g[v].push_back(a[r]);
            g[a[r]].push_back(v);
            col[a[r]] = col[v] ^ 1;
            dfs(a[r]);
            a.clear();
            for (int i = 0; i < n; i++)
            {
                if (!u[i])
                {
                    a.push_back(i);
                }
            }
        }
    }
}

vector <int> path;

void zhfs(int v, int need, int pr = -1)
{
    path.push_back(v);
    if (v == need)
    {
        cout << "N " << path.size() << endl;
        for (int v : path)
        {
            cout << v + 1 << ' ';
        }
        cout << endl;
    }
    for (int to : g[v])
    {
        if (to != pr)
        {
            zhfs(to, need, v);
        }
    }
    path.pop_back();
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*
    n = 7;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            gr[i][j] = rnd() % 2;
        }
    }
    */
    cin >> n;
    /*
    n = 4;
    gr[0][1] = 1;
    gr[1][2] = 1;
    gr[0][2] = 1;
    gr[0][3] = 1;
    */
    dfs(0);
    vector <int> x, y; 
    for (int i = 0; i < n; i++)
    {
        if (!col[i]) x.push_back(i);
        else y.push_back(i);
    }
    if (!ask(x) && !ask(y))
    {
        cout << "Y " << x.size() << endl;
        for (int v : x)
        {
            cout << v + 1 << ' ';
        }
        cout << endl;
    }
    else
    {
        if (!ask(x)) x = y;
        int l = -1, r = (int) x.size() - 1;
        while (l < r - 1)
        {
            int m = (l + r) / 2;
            vector <int> p;
            for (int i = 0; i <= m; i++) p.push_back(x[i]);
            if (ask(p))
            {
                r = m;
            }
            else
            {
                l = m;
            }
        }
        int vr = r;
        l = 0, r = vr;
        while (l < r - 1)
        {
            int m = (l + r) / 2;
            vector <int> p;
            for (int i = vr; i >= m; i--)
            {
                p.push_back(x[i]);
            }
            if (ask(p))
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        int u = x[l], v = x[vr];
        zhfs(u, v);
    }
}