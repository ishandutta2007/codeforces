#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=200005;
int n,i,j,k,d,x,y,z,head[N],adj[N*2],nxt[N*2],size[N],son[N],ed[N],dep[N],p[N][20];
void dfs(int x,int dad)
{
    size[x]=1,ed[x]=x;
    for(int y=head[x];y;y=nxt[y])
        if(adj[y]!=dad)
        {
            dep[adj[y]]=dep[x]+1;
            p[adj[y]][0]=x;
            dfs(adj[y],x);
            size[x]+=size[adj[y]];
            if(!son[x]||size[adj[y]]>size[son[x]])
                son[x]=adj[y],ed[x]=ed[adj[y]];
        }
}
int main()
{
    cin>>n;
    for(i=1;i<n;++i)
    {
        cin>>j>>k;
        adj[i*2-1]=k;
        nxt[i*2-1]=head[j];
        head[j]=i*2-1;
        adj[i*2]=j;
        nxt[i*2]=head[k];
        head[k]=i*2;
    }
    dfs(1,-1);
    for(i=1;(1<<i)<n;++i)
        for(j=1;j<=n;++j)
            if(p[j][i-1])
                p[j][i]=p[p[j][i-1]][i-1];
    i=1;
    cout<<'d'<<' '<<1<<endl;
    cout.flush();
    cin>>d;
    while(1)
    {
        cout<<'d'<<' '<<ed[i]<<endl;
        cout.flush();
        cin>>j;
        z=k=(j-d+dep[ed[i]])/2;
        for(x=0,y=ed[i];k;k>>=1,++x)
            if(k&1)
                y=p[y][x];
        if(z==j)
        {
        	i=y;
        	break;
        }
        if(i!=y)
        	i=y;
        else
        {
        	cout<<'s'<<' '<<i<<endl;
        	cout.flush();
        	cin>>i;
        }
    }
    cout<<'!'<<' '<<i<<endl;
    cout.flush();
    return 0;
}