#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<map>
using namespace std;
typedef long long LL;
const LL N=200005;
LL n;
struct qq
{
	LL x,y,id;
}s[N];
bool cmp (qq x,qq y)	{return x.x==y.x?x.y<y.y:x.x<y.x;}
LL sta[N],top;
bool check (qq a,qq b,qq c)	{return a.x*(a.y-b.y)*c.y*(c.x-b.x)>c.x*(b.y-c.y)*a.y*(b.x-a.x);}
map<pair<LL,LL> ,LL> mp;
bool ok[N];
int main()
{
	scanf("%lld",&n);
	for (LL u=1;u<=n;u++)
	{
		scanf("%lld%lld",&s[u].x,&s[u].y);
		s[u].id=u;
	}
	sort(s+1,s+1+n,cmp);
	//for (LL u=1;u<=n;u++) printf("%lld %lld %lld\n",s[u].x,s[u].y,s[u].id);
	for (LL u=1;u<=n;u++)
	{
		while (top>=1&&s[sta[top]].y<=s[u].y) top--;
		while (top>=2&&check(s[sta[top-1]],s[sta[top]],s[u])) top--;
		sta[++top]=u;
	}
	memset(ok,false,sizeof(ok));
	for (int u=1;u<=top;u++) mp[make_pair(s[sta[u]].x,s[sta[u]].y)]=1;
	for (LL u=1;u<=n;u++)
		if (mp[make_pair(s[u].x,s[u].y)])
			ok[s[u].id]=true;
	for (LL u=1;u<=n;u++)
		if (ok[u])
			printf("%lld ",u);
	return 0;
}