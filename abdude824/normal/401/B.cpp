#include <cstdio>
#include <cstdlib>
#include <cstring>

const int maxn=4005;

int vis[maxn];
int n,k,m,x;

int main()
{
    memset(vis,0,sizeof(vis));
    scanf("%d%d",&k,&n);
    while(n--)
    {
        scanf("%d",&m);
        if(m==2)
        {
            scanf("%d",&x);
            vis[x]=-1;
        }
        else if(m==1)
        {
            scanf("%d",&x);
            vis[x]=-2;
            scanf("%d",&x);
            vis[x]=-1;
        }
    }
    int ans1=0,ans2=0;;
    for(int i=1;i<k;i++)
        if(!vis[i])
        {
            ans2++;
            if(vis[i-1]==2)vis[i]=1;
            else vis[i]=2,ans1++;
        }
    printf("%d %d\n",ans1,ans2);
    return 0;
}