#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=400005;
struct node
{
    int len,fa,ch[26];
}a[N];
int n,i,j,k,lst,num,head[N],adj[N],nxt[N],f[N],tp[N],pos[N],root[N],ch[N*60][2],sum[N*60],cnt,ans;
char s[N];
bool ed[N];
int query(int o,int l,int r,int x,int y)
{
    if(!o)
        return 0;
    if(l>=x&&r<=y)
        return sum[o];
    int mid=l+r>>1,rtn=0;
    if(x<=mid)
        rtn=query(ch[o][0],l,mid,x,y);
    if(y>mid)
        rtn+=query(ch[o][1],mid+1,r,x,y);
    return rtn;
}
int merge(int o1,int o2,int l,int r)
{
    if(!o2)
        return o1;
    if(!o1)
        return o2;
	int c=++cnt;
    if(l==r)
    {
    	sum[c]=sum[o1]+sum[o2];
    	return c;
    }
    int mid=l+r>>1;
    ch[c][0]=merge(ch[o1][0],ch[o2][0],l,mid);
    ch[c][1]=merge(ch[o1][1],ch[o2][1],mid+1,r);
    sum[c]=sum[ch[c][0]]+sum[ch[c][1]];
	//printf("%d %d %d %d %d\n",o1,o2,l,r,query(root[3],0,n,2,3));
    //printf("%d %d %d %d\n",o1,l,r,sum[cnt]);
	return c;
}
void built(int &o,int l,int r,int x)
{
    o=++cnt;
    if(l==r)
    {
        sum[o]=1;
        return;
    }
    int mid=l+r>>1;
    if(x<=mid)
        built(ch[o][0],l,mid,x);
    else
        built(ch[o][1],mid+1,r,x);
    sum[o]=sum[ch[o][0]]+sum[ch[o][1]];
    //printf("%d %d %d\n",l,r,sum[o]);
}
void Dfs(int x)
{
    for(int y=head[x];y;y=nxt[y])
    {
        Dfs(adj[y]);
        if(!pos[x])
        	pos[x]=pos[adj[y]];
    }
    for(int y=head[x];y;y=nxt[y])
	{
		root[x]=merge(root[x],root[adj[y]],0,n);
		//printf("%d %d %d %d\n",x,adj[y],5,query(root[5],0,n,4,9));
	}
	//printf("%d %d\n",3,query(root[3],0,n,2,3));
}
void dfs(int x)
{
    for(int y=head[x];y;y=nxt[y])
    {
        //printf("%d %d %d   %d %d %d\n",x,tp[x],adj[y],pos[adj[y]]-a[adj[y]].len+a[tp[x]].len,pos[adj[y]],query(root[tp[x]],0,n,pos[adj[y]]-a[adj[y]].len+a[tp[x]].len,pos[adj[y]]));
        if(x==1||query(root[tp[x]],0,n,pos[adj[y]]-a[adj[y]].len+a[tp[x]].len,pos[adj[y]])>=2)
            f[adj[y]]=f[x]+1,tp[adj[y]]=adj[y];
        else
            f[adj[y]]=f[x],tp[adj[y]]=tp[x];
		//printf("%d %d\n",adj[y],f[adj[y]]);
        dfs(adj[y]);
    }
}
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    lst=num=1;
    for(i=1;i<=n;++i)
    {
        j=s[i]-'a';
        int p,np;
        p=lst;
        np=lst=++num;
        pos[num]=i;
        a[np].len=a[p].len+1;
        for(;p&&!a[p].ch[j];p=a[p].fa)
            a[p].ch[j]=np;
        if(!p)
            a[np].fa=1;
        else
        {
            int q=a[p].ch[j];
            if(a[q].len==a[p].len+1)
                a[np].fa=q;
            else
            {
                int nq=++num;
                a[nq]=a[q];
                a[nq].len=a[p].len+1;
                a[np].fa=a[q].fa=nq;
                for(;p&&a[p].ch[j]==q;p=a[p].fa)
                    a[p].ch[j]=nq;
            }
        }
        built(root[lst],0,n,pos[lst]);
        ed[lst]=true;
    }
	/*for(i=1;i<=n;++i)
	{
		for(j=i,k=1;j<=n;++j)
		{
			k=a[k].ch[s[j]-'a'];
			printf("%d %d %d   %d\n",i,j,k,pos[k]);
		}
	}*/
    for(i=1;i<=num;++i)
    	if(!ed[i])
    		built(root[i],0,n,0);
    for(i=2;i<=num;++i)
    {
        adj[i-1]=i;
        nxt[i-1]=head[a[i].fa];
        head[a[i].fa]=i-1;
    }
    Dfs(1);
    tp[1]=1,f[1]=0;
    dfs(1);
    for(i=1;i<=num;++i)
        ans=max(ans,f[i]);
    printf("%d",ans);
    return 0;
}