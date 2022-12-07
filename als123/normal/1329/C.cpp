#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const LL N=5000005;
LL T; 
LL h,g;
LL n;
LL a[N];
LL get (LL x)
{
//	printf("get:%lld %lld\n",x,a[x]);
	if (a[x]==0) return 0;
	LL s1=x*2,s2=x*2+1;
	if (a[s1]>a[s2]) return get(s1)+1;
	else return get(s2)+1;
}
void del (LL x)
{
	if (a[x]==0) return ;
	LL s1=x*2,s2=x*2+1;
	if (a[s1]>a[s2]) {a[x]=a[s1];del(s1);}
	else {a[x]=a[s2];del(s2);}
}
vector<LL> vec;
LL ans=0;
void solve (LL x,LL dep)
{
	if (a[x]==0) return ;
//	printf("%lld %lld\n",x,dep);
	while (dep+get(x)-1>g) 	{ans-=a[x];vec.push_back(x);del(x);}
	solve(x*2,dep+1);solve(x*2+1,dep+1);
}
int main()
{
	scanf("%lld",&T);
	while (T--)
	{
		scanf("%lld%lld",&h,&g);
		n=(1<<h)-1;ans=0;vec.clear();
		//printf("%lld\n",n);
		for (LL u=1;u<=n;u++) 
		{
			scanf("%lld",&a[u]);
			ans+=a[u];
		}
		for (LL u=n+1;u<=n*2+1;u++) a[u]=0;
		solve(1,1);
		printf("%lld\n",ans);
		LL siz=vec.size();
		for (LL u=0;u<siz;u++) printf("%lld ",vec[u]);
		printf("\n");
	}
	return 0;
}