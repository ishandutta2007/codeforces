#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=1200;
const int P=1000000007;
int n,m,a[V][V],Q,op,x,y;
int up[V][V],dn[V][V],le[V][V],ri[V][V];
int main()
{
    while(~scanf("%d%d%d",&n,&m,&Q))
    {
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        scanf("%d",&a[i][j]);
        memset(up,0,sizeof(up));
        memset(dn,0,sizeof(dn));
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==1)up[i][j]=up[i-1][j]+1;
            else up[i][j]=0;
        }
        for(int i=n;i>=1;i--)
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==1)dn[i][j]=dn[i+1][j]+1;
            else dn[i][j]=0;
        }
        memset(le,0,sizeof(le));
        memset(ri,0,sizeof(ri));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            if(a[i][j]==1)le[i][j]=le[i][j-1]+1;
            else le[i][j]=0;
            for(int j=m;j>=1;j--)
            if(a[i][j]==1)ri[i][j]=ri[i][j+1]+1;
            else ri[i][j]=0;
        }
        while(Q--)
        {
            scanf("%d%d%d",&op,&x,&y);
            if(op==1)
            {
                a[x][y]^=1;
                for(int i=1;i<=n;i++)
                if(a[i][y]==1)up[i][y]=up[i-1][y]+1;
                else up[i][y]=0;
                for(int i=n;i>=1;i--)
                if(a[i][y]==1)dn[i][y]=dn[i+1][y]+1;
                else dn[i][y]=0;
                for(int j=1;j<=m;j++)
                if(a[x][j]==1)le[x][j]=le[x][j-1]+1;
                else le[x][j]=0;
                for(int j=m;j>=1;j--)
                if(a[x][j]==1)ri[x][j]=ri[x][j+1]+1;
                else ri[x][j]=0;
            }
            else
            {
                int ret=0;
                int mu=up[x][y];
                int md=dn[x][y];
                for(int j=y;j<=m;j++)
                {
                    mu=min(mu,up[x][j]);
                    md=min(md,dn[x][j]);
                    if(mu==0||md==0)break;
                    ret=max(ret,(md+mu-1)*(j-y+1));
                }
                mu=up[x][y];
                md=dn[x][y];
                for(int j=y;j>=1;j--)
                {
                    mu=min(mu,up[x][j]);
                    md=min(md,dn[x][j]);
                    if(mu==0||md==0)break;
                    ret=max(ret,(md+mu-1)*(y-j+1));
                }
                int ml=le[x][y];
                int mr=ri[x][y];
                for(int j=x;j<=n;j++)
                {
                    ml=min(ml,le[j][y]);
                    mr=min(mr,ri[j][y]);
                    if(ml==0||mr==0)break;
                    ret=max(ret,(ml+mr-1)*(j-x+1));
                }
                ml=le[x][y];
                mr=ri[x][y];
                for(int j=x;j>=1;j--)
                {
                    ml=min(ml,le[j][y]);
                    mr=min(mr,ri[j][y]);
                    if(ml==0||mr==0)break;
                    ret=max(ret,(ml+mr-1)*(x-j+1));
                }
                printf("%d\n",ret);
            }
        }
    }
}