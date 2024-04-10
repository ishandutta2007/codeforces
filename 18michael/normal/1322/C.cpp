#include<cstdio>
#include<algorithm>
#define Mx 500000
#define LL long long
#define mod 1048081189
using namespace std;
int n,m,t,t1,Test_num;
LL ans;
LL pw[500002];
struct bbb
{
	LL c,s;
}num[500002];
inline bool cmp(bbb a,bbb b)
{
	return a.s<b.s? 1:0;
}
inline void clear()
{
	ans=0;
	for(int i=1;i<=n;++i)num[i].s=0;
}
inline void add_edge(int x,int y)
{
	num[y].s=(num[y].s+pw[x])%mod;
}
inline void init()
{
	pw[1]=1;
	for(int i=2;i<=Mx;++i)pw[i]=(pw[i-1]<<1)%mod;
}
inline LL gcd(LL a,LL b)
{
	return b? gcd(b,a%b):a;
}
int main()
{
	init(),scanf("%d",&Test_num);
	while(Test_num--)
	{
		scanf("%d%d",&n,&m),clear();
		for(int i=1;i<=n;++i)scanf("%lld",&num[i].c);
		for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),add_edge(x,y);
		sort(num+1,num+n+1,cmp);
		for(t=1;t<=n && !num[t].s;++t);
		num[t1=1]=num[t];
		for(int i=t+1;i<=n;++i)
		{
			if(num[i].s==num[t1].s)num[t1].c+=num[i].c;
			else num[++t1]=num[i];
		}
		for(int i=1;i<=t1;++i)ans=gcd(ans,num[i].c);
		printf("%lld\n",ans);
	}
	return 0;
}