#include <algorithm>
#include <cstdio>

using namespace std;

const int N=200010;

int a[N], b[N], nxt[N];

int main()
{
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    int n, i, m, tip, x, y, p;
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);
        nxt[i]=i+1;
    }
    //sort(a+1, a+n+1);
    scanf("%d", &m);
    while(m--)
    {
        scanf("%d", &tip);
        if(tip==2)
        {
            scanf("%d", &x);
            printf("%d\n", b[x]);
        }
        else
        {
            scanf("%d%d", &x, &p);
            for(y=x;p&&y<=n;y=nxt[y])
            {
                if(p>a[y]-b[y])
                {
                    p-=a[y]-b[y];
                    b[y]=a[y];
                }
                else
                {
                    b[y]+=p;
                    p=0;
                }
                i=y;
            }
            for(y=x;y!=i;y=p)
            {
                p=nxt[y];
                nxt[y]=i;
            }
        }
    }
}