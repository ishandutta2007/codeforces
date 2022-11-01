#include <cstdio>
using namespace std;

const int N=100003;

int a[N], v[N], sol[N];

int main()
{
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    int n, m, i, x;
    scanf("%d%d", &n, &m);
    for(i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);
    }
    for(i=n;i;i--)
    {
        if(!v[a[i]])
        {
            v[a[i]]=1;
            sol[i]=sol[i+1]+1;
        }
        else sol[i]=sol[i+1];
    }
    while(m--)
    {
        scanf("%d", &x);
        printf("%d\n", sol[x]);
    }
}