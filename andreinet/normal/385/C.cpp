#include <cstdio>
#include <bitset>

using namespace std;

const int N=10000005;

bitset <N> v;
unsigned int cnt[N], nr[N];

int main()
{
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    int n, m, i, j, x, y;
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
        scanf("%d", &x);
        cnt[x]++;
        if(x%2==0) nr[2]++;
    }
    for(i=3;i<N;i+=2)
    {
        if(!v[i])
        {
            for(j=i;j<N;j+=i)
            {
                v[j]=1;
                nr[i]+=cnt[j];
            }
            v[i]=0;
        }
    }
    for(i=1;i<N;i++) nr[i]+=nr[i-1];
    scanf("%d", &m);
    while(m--)
    {
        scanf("%d%d", &x, &y);
        if(y>=N) y=N-1;
        if(x>=N) x=N-1;
        printf("%d\n", nr[y]-nr[x-1]);
    }
}