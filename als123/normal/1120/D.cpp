#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const LL N=200005;
LL n;
LL a[N];
vector<LL> vec[N];
bool ok[N];
LL ans=0;
LL ff[N],id[N];
LL find_fa (LL x)	{return ff[x]==x?x:ff[x]=find_fa(ff[x]);}
void dfs (LL x,LL fa)
{
	if (fa!=0&&vec[x].size()==1)	{id[x]=x;return ;}
	LL siz=vec[x].size();
	for (LL u=0;u<siz;u++)
	{
		LL y=vec[x][u];
		if (y==fa) continue;
		dfs(y,x);
	}
	LL pos=-1,cnt=0;
	for (LL u=0;u<siz;u++)
	{
		LL y=vec[x][u];
		if (y==fa) continue;
		if (pos==-1) pos=id[y];
		else if (a[id[y]]>a[pos])	pos=id[y],cnt=0;
		if (a[id[y]]==a[pos]) cnt++;
	}
	for (LL u=0;u<siz;u++)
	{
		LL y=vec[x][u];
		if (y==fa||id[y]==pos) continue;
		ok[id[y]]=true;ans=ans+a[id[y]];
	}
	//if (pos==10) printf("YES:%lld %lld %lld\n",pos,x,cnt);
	if (cnt>1)	ok[pos]=true;
	if (a[pos]<a[x]) id[x]=pos;
	else if (a[pos]==a[x])	
	{
		if (cnt==1&&ok[find_fa(pos)]==false) ff[find_fa(pos)]=x;
		id[x]=x;
	}
	else id[x]=x;
}
int main()
{
	scanf("%lld",&n);
	for (LL u=1;u<=n;u++) scanf("%lld",&a[u]);
	for (LL u=1;u<=n;u++) ff[u]=u;
	for (LL u=1;u<n;u++)
	{
		LL x,y;
		scanf("%lld%lld",&x,&y);
		vec[x].push_back(y);vec[y].push_back(x);
	}
	dfs(1,0);
	ok[id[1]]=true;ans=ans+a[id[1]];
	LL cnt=0;for (LL u=1;u<=n;u++) cnt=cnt+ok[find_fa(u)];
	printf("%lld %lld\n",ans,cnt);
	for (LL u=1;u<=n;u++) if (ok[find_fa(u)]) printf("%lld ",u);
	return 0;
}