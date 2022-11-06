#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <iterator>
#include <cmath>

using namespace std;

int n;
bool chk[610];
vector<int> v[2];
vector<int> edg[610];

int query(vector<int> &t)
{
    int sz = t.size();

    if(sz <= 1)
        return 0;

    printf("? %d\n", sz);
    for(int x : t)
        printf("%d ", x);
    printf("\n");
    fflush(stdout);

    int m;
    scanf("%d", &m);

    if(m == -1)
        exit(0);

    return m;
}

int con(vector<int> &s, vector<int> &t)
{
    if(s.empty() || t.empty())
        return 0;

    vector<int> r = s;
    for(int x : t)
        r.push_back(x);

    return query(r) - query(s) - query(t);
}

void f(int x, int d)
{
    int i;
    chk[x] = 1;
    v[d].push_back(x);

    while(1)
    {
        vector<int> cur;
        cur.push_back(x);
        vector<int> nxt;
        for(i = 1; i <= n; i++)
            if(!chk[i])
                nxt.push_back(i);

        int sz = nxt.size();
        if(con(cur, nxt) == 0)
            return;

        int s = 0;
        int g = sz - 1;
        while(s < g)
        {
            int m = (s + g) / 2;

            vector<int> tmp;
            for(i = 0; i <= m; i++)
                tmp.push_back(nxt[i]);

            if(con(cur, tmp))
                g = m;
            else
                s = m + 1;
        }

        s = nxt[s];

        edg[x].push_back(s);
        edg[s].push_back(x);
        f(s, 1 - d);
    }
}

stack<int> res;
bool h(int x, int p, int z)
{
    res.push(x);
    if(x == z)
        return 1;

    for(int y : edg[x])
    {
        if(y != p && h(y, x, z))
            return 1;
    }

    res.pop();
    return 0;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int i;
    scanf("%d", &n);

    f(1, 0);

    int d = -1;
    if(query(v[0]))
        d = 0;
    else if(query(v[1]))
        d = 1;

    if(d == -1)
    {
        printf("Y %d\n", (int)v[0].size());
        for(int x : v[0])
            printf("%d ", x);
        printf("\n");
        fflush(stdout);
    }
    else
    {
        for(int x : v[d])
        {
            vector<int> cur;
            cur.push_back(x);
            vector<int> nxt;
            for(int y : v[d])
                if(x != y)
                    nxt.push_back(y);

            int sz = nxt.size();
            if(con(cur, nxt) == 0)
                continue;

            int s = 0;
            int g = sz - 1;
            while(s < g)
            {
                int m = (s + g) / 2;

                vector<int> tmp;
                for(i = 0; i <= m; i++)
                    tmp.push_back(nxt[i]);

                if(con(cur, tmp))
                    g = m;
                else
                    s = m + 1;
            }

            s = nxt[s];

            bool xx = h(x, x, s);
            assert(xx);

            printf("N %d\n", (int)res.size());
            while(!res.empty())
            {
                printf("%d ", res.top());
                res.pop();
            }
            printf("\n");
            fflush(stdout);

            break;
        }
    }

    return 0;
}