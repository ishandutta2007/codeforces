#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=100005;
int n,w,i,j,k,head[N],adj[N*2],nxt[N*2],f[N],g[N],len[N],h[N],id[N],mx1[N],mx2[N],fa[N];
inline void dfs(int x,int dad)
{
    h[++i]=x;
    id[x]=i;
    for(int y=head[x];y;y=nxt[y])
        if(adj[y]!=dad)
        {
        	fa[adj[y]]=x;
		    dfs(adj[y],x);
		}
}
inline int work(int K)
{
    if(f[K]!=-1)
        return f[K];
    f[K]=0;
    memset(mx1,0,sizeof(mx1));
    memset(mx2,0,sizeof(mx2));
    for(int i=n,x,y;i>=1;--i)
    {
        x=h[i];
        //int mx1=0,mx2=0;
        if(mx1[x]+mx2[x]+1>=K)
        	f[K]++,len[x]=0;
        else
        	len[x]=mx1[x]+1;
        if(len[x]>mx1[fa[x]])
        {
        	mx2[fa[x]]=mx1[fa[x]];
        	mx1[fa[x]]=len[x];
        }
        else if(len[x]>mx2[fa[x]])
        	mx2[fa[x]]=len[x];
        /*for(y=head[x];y;y=nxt[y])
            if(id[adj[y]]>id[x])
            {
                if(len[adj[y]]>mx1)
                {
                    mx2=mx1;
                    mx1=len[adj[y]];
                }
                else if(len[adj[y]]>mx2)
                    mx2=len[adj[y]];
                if(mx1+mx2+1>=K)
                    break;
            }
        if(mx1+mx2+1>=K)
            f[K]++;
        if(!y)
            len[x]=mx1+1;
        else
            len[x]=0;*/
    }
    return f[K];
}
inline void dzx(int lt,int rt)
{
    if(lt==rt||lt+1==rt)
    {
        work(lt),work(rt);
        return;
    }
    int mid=lt+rt>>1;
    if(work(mid)==work(lt))
    {
        for(int i=lt;i<=mid;++i)
            f[i]=f[mid];
    }
    else
        dzx(lt,mid);
    if(work(mid)==work(rt))
    {
        for(int i=mid;i<=rt;++i)
            f[i]=f[mid];
    }
    else
        dzx(mid,rt);
}
int main()
{
    scanf("%d",&n);
    for(i=1;i<n;++i)
    {
        scanf("%d%d",&j,&k);
        adj[i*2-1]=k;
        nxt[i*2-1]=head[j];
        head[j]=i*2-1;
        adj[i*2]=j;
        nxt[i*2]=head[k];
        head[k]=i*2;
    }
    i=0;
    dfs(1,-1);
    memset(f,-1,sizeof(f));
    w=min(n,(int)ceil(sqrt(n*1.4)));
    for(i=1;i<=w;++i)
        work(i);
    if(w+1<=n)
        dzx(w+1,n);
    for(i=1;i<=n;++i)
        printf("%d\n",f[i]);
    return 0;
}