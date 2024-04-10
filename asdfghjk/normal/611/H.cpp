#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=200005;
int n,i,j,k,l,g[15][15],cnt,w[25],phh[25],fa[25],p[25],fr[25],to[25],num,head[N],adj[N],nxt[N],flow[N],cap[N],cur[N],q[N],bg,ed,d[N],ans1[N],ans2[N],len;
char s1[15],s2[15];
void addedge(int u,int v,int w)
{
    adj[++l]=v;
    nxt[l]=head[u];
    head[u]=l;
    flow[l]=0;
    cap[l]=w;
    adj[++l]=u;
    nxt[l]=head[v];
    head[v]=l;
    flow[l]=cap[l]=0;
}
bool bfs()
{
    int i;
    for(i=1;i<=2+cnt+num;++i)
        d[i]=1<<30;
    q[bg=ed=1]=cnt+num+1;
    d[q[bg]]=0;
    while(bg<=ed)
    {
        for(i=head[q[bg]];i;i=nxt[i])
            if(flow[i]<cap[i]&&d[q[bg]]+1<d[adj[i]])
            {
                d[adj[i]]=d[q[bg]]+1;
                q[++ed]=adj[i];
            }
        ++bg;
    }
    return d[2+cnt+num]!=(1<<30);
}
int Dfs(int x,int a)
{
    if(x==2+cnt+num||a<=0)
        return a;
    int g,h=0;
    for(;cur[x];cur[x]=nxt[cur[x]])
        if(d[adj[cur[x]]]==d[x]+1&&(g=Dfs(adj[cur[x]],min(a,cap[cur[x]]-flow[cur[x]])))>0)
        {
            flow[cur[x]]+=g;
            flow[cur[x]&1?cur[x]+1:cur[x]-1]-=g;
            a-=g;
            h+=g;
            if(a<=0)
                break;
        }
    return h;
}
int find(int x)
{
    return !fa[x]?x:fa[x]=find(fa[x]);
}
bool dfs(int x,int dzx)
{
    int y,z;
    if(x>num)
    {
    	if(dzx!=cnt-1)
    		return false;
    	for(y=1;y<=cnt;++y)
    		fa[y]=0;
    	for(y=1;y<=dzx;++y)
    		if(find(fr[phh[y]])==find(to[phh[y]]))
    			break;
    		else
    			fa[find(fr[phh[y]])]=find(to[phh[y]]);
    	if(y<=dzx)
    		return false;
        for(y=1;y<=2+cnt+num;++y)
            head[y]=0;
        l=0;
        for(y=1;y<=num;++y)
        {
            addedge(cnt+num+1,y,g[fr[y]][to[y]]);
            addedge(y,num+fr[y],1<<30);
            addedge(y,num+to[y],1<<30);
        }
        for(y=1;y<=cnt;++y)
            addedge(num+y,cnt+num+2,w[y]-w[y-1]-1);
        int dg=0;
        while(bfs())
        {
            for(y=1;y<=2+cnt+num;++y)
                cur[y]=head[y];
            dg+=Dfs(1+cnt+num,1<<30);
        }
        if(dg==n-cnt)
        {
            for(y=1;y<=cnt;++y)
                p[y]=w[y-1]+2;
            for(y=1;y<=num;++y)
            {
                for(z=head[y];z;z=nxt[z])
                    if(adj[z]!=cnt+num+1)
                    {
                        while(flow[z]>0)
                        {
                            ++len;
                            if(adj[z]-num==fr[y])
                            {
                                ans1[len]=w[to[y]-1]+1;
                                ans2[len]=p[fr[y]]++;
                            }
                            else
                            {
                                ans1[len]=w[fr[y]-1]+1;
                                ans2[len]=p[to[y]]++;
                            }
                            --flow[z];
                        }
                    }
            }
            return true;
        }
        return false;
    }
    if(dfs(x+1,dzx))
    	return true;
    if(fr[x]==to[x])
    	return false;
    if(g[fr[x]][to[x]]==0)
    	return false;
    g[fr[x]][to[x]]--;
    g[to[x]][fr[x]]--;
    ++len;
    ans1[len]=w[fr[x]-1]+1,ans2[len]=w[to[x]-1]+1;
    phh[dzx+1]=x;
    if(dfs(x+1,dzx+1))
    	return true;
    g[fr[x]][to[x]]++;
    g[to[x]][fr[x]]++;
    --len;
    return false;
}
int main()
{
    scanf("%d",&n);
    for(i=1;i<n;++i)
    {
        scanf("%s%s",s1,s2);
        j=strlen(s1),k=strlen(s2);
        g[j][k]++;
        if(j!=k)
            g[k][j]++;
    }
    for(i=1,j=9;j<n;++i,j=j*10+9)
        w[i]=j;
    w[cnt=i]=n;
    for(i=1;i<=cnt;++i)
        for(j=i;j<=cnt;++j)
        {
            ++num;
            fr[num]=i,to[num]=j;
        }
    if(!dfs(1,0))
        puts("-1");
    else
    {
        for(i=1;i<=len;++i)
            printf("%d %d\n",ans1[i],ans2[i]);
    }
    return 0;
}