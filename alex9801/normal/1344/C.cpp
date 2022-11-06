#include <bits/stdc++.h>
using namespace std;

vector<int> edg1[200010];
vector<int> edg2[200010];
int deg[200010];
int mem1[200010];
int mem2[200010];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        edg1[x].push_back(y);
        edg2[y].push_back(x);
        deg[y]++;
    }

    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(deg[i] == 0)
            q.push(i);

    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        if(q.empty())
        {
            puts("-1");
            return 0;
        }

        int x = q.front();
        q.pop();

        v.push_back(x);
        for(int y : edg1[x])
        {
            deg[y]--;
            if(deg[y] == 0)
                q.push(y);
        }
    }

    for(int i = 0; i < n; i++)
    {
        int x = v[i];
        mem1[x] = 1e9;
        for(int y : edg2[x])
            mem1[x] = min({ mem1[x], mem1[y], y });
    }

    for(int i = n - 1; i >= 0; i--)
    {
        int x = v[i];
        mem2[x] = 1e9;
        for(int y : edg1[x])
            mem2[x] = min({ mem2[x], mem2[y], y });
    }

    int r = 0;
    string s;
    for(int i = 1; i <= n; i++)
    {
        if(i < min(mem1[i], mem2[i]))
        {
            r++;
            s.push_back('A');
        }
        else
            s.push_back('E');
    }

    printf("%d\n%s\n", r, s.c_str());
    return 0;
}