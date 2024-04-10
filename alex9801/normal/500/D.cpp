#include <stdio.h>
#include <vector>

std::vector<int> adj[300001];
int arr[300000][3];
int mem[300001];
int par[300001];

void f(int x)
{
    int t,i;
    mem[x]=1;
    for(i=0;i<adj[x].size();i++)
    {
        t=adj[x][i];
        if(t!=par[x])
        {
            par[t]=x;
            f(t);
            mem[x]+=mem[t];
        }
    }
}

int main()
{
    int n,q,t,x,w,i;
    long double r=0,d;
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        scanf("%d%d%d",&arr[i][0],&arr[i][1],&arr[i][2]);
        adj[arr[i][0]].push_back(arr[i][1]);
        adj[arr[i][1]].push_back(arr[i][0]);
    }
    d=1LL*n*(n-1)*(n-2)/6;
    f(1);
    for(i=1;i<n;i++)
    {
        if(par[arr[i][1]]==arr[i][0])
        {
            t=arr[i][0];
            arr[i][0]=arr[i][1];
            arr[i][1]=t;
        }
        t=mem[arr[i][0]];
        r+=1LL*arr[i][2]*t*(n-t)*(n-2)/d;       
    }
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d%d",&x,&w);
        t=mem[arr[x][0]];
        r-=1LL*(arr[x][2]-w)*t*(n-t)*(n-2)/d;
        arr[x][2]=w;
        printf("%.12Lf\n",r);
    }
    return 0;
}