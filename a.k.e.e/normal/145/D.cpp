#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
const int MAXN=100005,MAXM=1005;
inline bool lucky(int x)
{
	for(;x;x/=10)
		if(x%10!=7 && x%10!=4)
			return 0;
	return 1;
}
inline ll calc(ll x){return x*(x+1)/2;}
inline ll cn3(ll x){return x*(x+1)*(x+2)/6;}
inline ll cbt(ll x,ll y){return cn3(x)-cn3(x-y-1);}

int n,m,a[MAXM],p[MAXM],pre[MAXN],las[MAXN];
ll pos[MAXM];
bool vis[MAXM];
set<int> s;
inline int getpre(int x)
	{auto i=s.lower_bound(x);--i;return *i;}
inline int getnxt(int x)
	{auto i=s.upper_bound(x);return *i;}
ll work(int r)
{
	ll ans=0,cur=cbt(n-pos[r],pos[r+1]-pos[r]-1);
	s.clear();s.insert(r);s.insert(m+1);
	memset(vis,0,sizeof(vis));
	for(int l=r;l;--l)
	{
		int u=a[l];
		if(!vis[u])
		{
			vis[u]=1;
			for(int i=las[u];i>r;i=pre[i])
			{
				int x=getpre(i),y=getnxt(i);
				if(x==r)cur+=cbt(pos[i]-pos[x]-1,pos[r+1]-pos[r]-1)
					+calc(pos[y]-pos[i]-1)*(pos[r+1]-pos[r])
					-cbt(pos[y]-pos[x]-1,pos[r+1]-pos[r]-1);
				else cur+=(calc(pos[i]-pos[x]-1)+calc(pos[y]-pos[i]-1)
					-calc(pos[y]-pos[x]-1))*(pos[r+1]-pos[r]);
				s.insert(i);
			}
		}
		ans+=cur*(pos[l]-pos[l-1]);
	}
	return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    ll ans=0;
    int x;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&x);
    	if(lucky(x))
		{
			++m;
			p[m]=a[m]=x;
			pos[m]=i;
		}
    }
    sort(p+1,p+m+1);
    for(int i=1;i<=m;i++)
    {
    	a[i]=lower_bound(p+1,p+m+1,a[i])-p;
    	pre[i]=las[a[i]];
    	las[a[i]]=i;
    }
    pos[m+1]=n+1;
    for(int i=0;i<=m;i++)
    	for(int j=pos[i]+1;j<pos[i+1];j++)
    		ans+=(j-pos[i])*calc(n-j);
    for(int i=1;i<=m;i++)
    	ans+=work(i);
    cout<<ans<<endl;
    return 0;
}