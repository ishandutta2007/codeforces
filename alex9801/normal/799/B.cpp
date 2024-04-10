#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

struct str
{
    int p, i;
    bool operator <(const str &a) const
    {
        return p > a.p;
    }
};

int p[200000];
int a[200000];
int b[200000];
priority_queue<str> pq[3];
bool chk[200000];

int main()
{
    int n, m, x, i, j;
    scanf("%d", &n);
    for(i = 0; i<n; i++)
        scanf("%d", &p[i]);
    for(i = 0; i<n; i++)
        scanf("%d", &a[i]);
    for(i = 0; i<n; i++)
        scanf("%d", &b[i]);

    for(i = 0; i<n; i++)
        for(j = 1; j<=3; j++)
            if(a[i] == j || b[i] == j)
                pq[j].push({ p[i], i });

    scanf("%d", &m);
    for(i = 0; i<m; i++)
    {
        scanf("%d", &x);
        while(!pq[x].empty() && chk[pq[x].top().i])
            pq[x].pop();

        if(pq[x].empty())
            printf("-1 ");
        else
        {
            printf("%d ", pq[x].top().p);
            chk[pq[x].top().i] = 1;
            pq[x].pop();
        }
    }

    return 0;
}