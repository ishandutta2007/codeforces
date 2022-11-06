#include <bits/stdc++.h>
using namespace std;

struct edg
{
    int x, w;
};

vector<edg> arr[1010];
int deg[1010];

int f(int x, int p)
{
    if(deg[x] == 1)
        return x;

    for(edg e : arr[x])
    {
        if(e.x == p)
            continue;

        int r = f(e.x, x);
        if(r != -1)
            return r;
    }

    return -1;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i;
    scanf("%d", &n);
    for(i = 0; i < n - 1; i++)
    {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        deg[x]++;
        deg[y]++;
        arr[x].push_back({ y, w });
        arr[y].push_back({ x, w });
    }

    for(i = 1; i <= n; i++)
    {
        if(deg[i] == 2)
        {
            puts("NO");
            return 0;
        }
    }

    puts("YES");

    if(n == 2)
    {
        printf("1\n1 2 %d\n", arr[1][0].w);
        return 0;
    }

    vector<tuple<int, int, int>> res;
    for(i = 1; i <= n; i++)
    {
        for(edg e : arr[i])
        {
            if(deg[e.x] == 1 || deg[i] != 1 && i > e.x)
                continue;

            int x = -1, y = -1;
            for(edg e2 : arr[e.x])
            {
                if(e2.x == i)
                    continue;

                if(x == -1)
                    x = f(e2.x, e.x);
                else
                {
                    y = f(e2.x, e.x);
                    continue;
                }
            }

            assert(y != -1);

            if(deg[i] == 1)
            {
                res.push_back({ i, x, e.w / 2 });
                res.push_back({ i, y, e.w / 2 });
                res.push_back({ x, y, -e.w / 2 });
            }
            else
            {
                int z = -1, w = -1;
                for(edg e2 : arr[i])
                {
                    if(e2.x == e.x)
                        continue;

                    if(z == -1)
                        z = f(e2.x, i);
                    else
                    {
                        w = f(e2.x, i);
                        continue;
                    }
                }

                assert(w != -1);

                res.push_back({ x, z, e.w / 2 });
                res.push_back({ y, w, e.w / 2 });
                res.push_back({ x, y, -e.w / 2 });
                res.push_back({ z, w, -e.w / 2 });
            }
        }
    }

    printf("%d\n", (int)res.size());
    for(auto t : res)
    {
        int x, y, w;
        tie(x, y, w) = t;

        printf("%d %d %d\n", x, y, w);
    }

    return 0;
}