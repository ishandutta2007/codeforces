#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr[1010];
int deg[1010];

int qcnt = 0;
int query(int x, int y)
{
    assert(qcnt < n / 2);
    qcnt++;
    printf("? %d %d\n", x, y);
    fflush(stdout);

    int r;
    scanf("%d", &r);
    if(r == -1)
        exit(0);
    return r;
}

void answer(int x)
{
    printf("! %d\n", x);
    exit(0);
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        arr[x].push_back(y);
        arr[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }

    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(deg[i] == 1)
            q.push(i);

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        if(q.empty())
            answer(x);

        int y = q.front();
        q.pop();

        int z = query(x, y);

        if(x == z || y == z)
            answer(z);

        for(int t : arr[x])
        {
            deg[t]--;
            if(deg[t] == 1)
                q.push(t);
        }
        for(int t : arr[y])
        {
            deg[t]--;
            if(deg[t] == 1)
                q.push(t);
        }
    }

    assert(0);
    return 0;
}