#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define pb push_back

typedef long long LL;

const int N=200005;

int n,b[N],t[N],c[N];
struct data{int x,y;}a[N];
std::vector<int> vec[N];
bool vis[N];

bool cmp(data a,data b)
{
	return a.y<b.y||a.y==b.y&&a.x<b.x;
}

LL get(int x)
{
	return (LL)x*(x+1)/2; 
}

void ins(int x,int y)
{
	while (x<=n) c[x]+=y,x+=x&(-x);
}

int find(int x)
{
	int ans=0;
	while (x) ans+=c[x],x-=x&(-x);
	return ans;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	std::sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++) t[i]=a[i].x;
	std::sort(t+1,t+n+1);
	for (int i=1;i<=n;i++) a[i].x=std::lower_bound(t+1,t+n+1,a[i].x)-t;
	for (int i=1;i<=n;i++) t[i]=a[i].y;
	std::sort(t+1,t+n+1);
	for (int i=1;i<=n;i++) a[i].y=std::lower_bound(t+1,t+n+1,a[i].y)-t;
	for (int i=1;i<=n;i++) vec[a[i].y].pb(a[i].x);
	LL ans=0;
	for (int i=n;i>=1;i--)
	{
		if (!vec[i].size()) continue;
		int tot=0;
		for (int j=0;j<vec[i].size();j++) b[++tot]=vec[i][j];
		for (int j=1;j<=tot;j++) if (!vis[b[j]]) vis[b[j]]=1,ins(b[j],1);
		ans+=get(find(n));
		ans-=get(find(b[1]-1));
		ans-=get(find(n)-find(b[tot]));
		for (int j=1;j<tot;j++) ans-=get(find(b[j+1]-1)-find(b[j]));
	}
	printf("%lld\n",ans);
	return 0;
}