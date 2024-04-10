#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN=200005,INF=1<<30;

int n,a[MAXN],nxt[MAXN],cur[MAXN],pos[MAXN];
int c[MAXN];
bool vis[MAXN];
void add(int x,int d){for(;x<=2*n;x+=(x&-x))c[x]+=d;}
int query(int x){int ans=0;for(;x;x-=(x&-x))ans+=c[x];return ans;}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++)
    {
    	scanf("%d",&a[i]);
    	if(vis[a[i]])a[i]+=n;
    	else vis[a[i]]=1;
    	cur[a[i]]=2*n+1;
    }
    for(int i=2*n;i>0;i--)
    {
    	nxt[i]=cur[a[i]];
    	cur[a[i]]=i;
    }
    int cnt=0;
    for(int i=1;i<=2*n;i++)
    {
    	if(pos[i])continue;
    	int u=a[i]>n?a[i]-n:a[i];
    	pos[cur[u]]=++cnt;
    	pos[cur[u+n]]=++cnt;
    	cur[u]=nxt[cur[u]];
    	cur[u+n]=nxt[cur[u+n]];
    }
    ll ans=0;
    for(int i=1;i<=2*n;i++)
    {
    	ans+=query(2*n)-query(pos[i]);
    	add(pos[i],1);
    }
    cout<<ans<<endl;
    return 0;
}