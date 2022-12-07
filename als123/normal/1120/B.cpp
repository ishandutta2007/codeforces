#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
typedef long long LL;
const LL N=100005;
char ss[N];
LL a[N],b[N];
LL c[N],d[N];
LL n;
queue<LL> q;
bool check (LL x)
{
	if (c[x]>0&&a[x]<=8&&a[x+1]<=8) return true;
	if (c[x]<0)
	{
		if (a[x]>1&&a[x+1]>=1) return true;
		else if (a[x]==1&&x!=1&&a[x+1]>=1) return true;
	}
	return false;
}
int main()
{
	scanf("%lld",&n);
	scanf("%s",ss+1);
	for (LL u=1;u<=n;u++) a[u]=ss[u]-'0';
	scanf("%s",ss+1);
	for (LL u=1;u<=n;u++) b[u]=ss[u]-'0';
	for (LL u=1;u<=n;u++) d[u]=a[u];
	for (LL u=1;u<n;u++)	{c[u]=b[u]-d[u];d[u+1]=d[u+1]+c[u];}
	if (d[n]!=b[n])	{printf("-1\n");return 0;}
	LL ans=0;for (LL u=1;u<n;u++) ans=ans+abs(c[u]);
	printf("%lld\n",ans);
	for (LL u=1;u<n;u++)
		if (check(u))
			q.push(u);
	LL cnt=0;
	while (!q.empty()&&cnt<100000)
	{
		LL x=q.front();q.pop();
		if (!check(x)) continue;
		cnt++;
		if (c[x]>0)
		{
			a[x]++;a[x+1]++;c[x]--;
			if (check(x)) q.push(x);
			if (x+1<n&&check(x+1)) q.push(x+1);
			if (x-1>=1&&check(x-1)) q.push(x-1);
			printf("%lld 1\n",x);
		}
		if (c[x]<0)	
		{
			a[x]--;a[x+1]--;c[x]++;
			printf("%lld -1\n",x);
			if (check(x)) q.push(x);
			if (x+1<n&&check(x+1)) q.push(x+1);
			if (x-1>=1&&check(x-1)) q.push(x-1);
		}
	}
	return 0;
}