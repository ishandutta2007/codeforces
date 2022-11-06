#include<bits/stdc++.h>
using namespace std;

vector<int> redg[1000010];
int deg[1000010];
bool chk[1000010];
int cnt[1000010];

int main()
{
    int n, m, s, t;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        redg[y].push_back(x);
        deg[x]++;
    }
    scanf("%d%d", &s, &t);

    queue<int> q;
    q.push(t);
    chk[t] = 1;
    for(int i = 0; i < n; i++)
    {
        vector<int> v;
        while(!q.empty())
        {
            int x = q.front();
            q.pop();

            if(x == s)
            {
                printf("%d\n", i);
                return 0;
            }

            for(int y : redg[x])
            {
                if(chk[y])
                    continue;

                cnt[y]++;
                if(cnt[y] == deg[y])
                {
                    chk[y] = 1;
                    q.push(y);
                }
                else if(cnt[y] == 1)
                    v.push_back(y);
            }
        }

        for(int x : v)
        {
            if(!chk[x])
            {
                chk[x] = 1;
                q.push(x);
            }
        }
    }

    puts("-1");
    return 0;
}