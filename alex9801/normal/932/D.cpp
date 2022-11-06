#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>

using namespace std;

int dis[400010];
int wei[400010];
long long sum[400010];

int nex[400010][20];

int anc(int x, int h)
{
    if(h == 0)
        return x;

    //printf("xht %d %d %d\n", x, h, h & -h);

    int t = __builtin_ctz(h);
    return anc(nex[x][t], h - (1 << t));
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int q, i, j;
    scanf("%d", &q);

    int cnt = 1;
    int last = 0;

    for(j = 0; j < 20; j++)
        nex[1][j] = 1;

    for(i = 0; i < q; i++)
    {
        int ty;
        long long p, q;
        scanf("%d%lld%lld", &ty, &p, &q);

        p ^= last;
        q ^= last;

        if(ty == 1)
        {
            int r, w;
            r = p;
            w = q;

            cnt++;

            wei[cnt] = w;

            if(wei[anc(r, dis[r])] < w)
            {
                for(j = 0; j < 20; j++)
                    nex[cnt][j] = cnt;

                dis[cnt] = 0;
                sum[cnt] = w;
            }
            else
            {
                int s = 0;
                int g = dis[r];
                while(s < g)
                {
                    int m = (s + g) / 2;
                    if(wei[anc(r, m)] < w)
                        s = m + 1;
                    else
                        g = m;
                }
                s = anc(r, s);
                for(j = 0; j < 20; j++)
                    nex[cnt][j] = anc(s, (1 << j) - 1);

                dis[cnt] = dis[s] + 1;
                sum[cnt] = sum[s] + w;
            }
        }
        else
        {
            int r;
            long long x;
            r = p;
            x = q;
            if(sum[r] <= x)
                last = dis[r] + 1;
            else
            {
                int s = 0;
                int g = dis[r];
                while(s < g)
                {
                    int m = (s + g + 1) / 2;
                    if(sum[r] - sum[anc(r, m)] <= x)
                        s = m;
                    else
                        g = m - 1;
                }

                last = s;
            }

            printf("%d\n", last);
        }
    }
    return 0;
}