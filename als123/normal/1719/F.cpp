#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=200005;
vector<LL> vec[N];
vector<LL> p;
vector<LL> p1[N];
LL a[N];
struct qq
{
	priority_queue<LL> p,q;
	void reg ()
	{
	//	printf("YES");
		while (!q.empty()&&p.top()==q.top()) {p.pop();q.pop();}
	//	printf("NO");
	}
	LL top ()	  {reg();return p.top();}
	void push (LL x) 	{p.push(x);}
	void del  (LL x)	{q.push(x);}
	void clear ()
	{
		while (!q.empty()) q.pop();
		while (!p.empty()) p.pop();
	}
}S;
bool in[N];
int main()
{
	memset(in,true,sizeof(in));
	for (int u=2;u<=200000;u++)
	for (int i=u+u;i<=200000;i+=u)
	in[i]=false;
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	LL T;
	scanf("%lld",&T);
	while (T--)
	{
		S.clear();p.clear();
		LL n,ans=0,q;
		scanf("%lld%lld",&n,&q);
		for (LL u=1;u<=n;u++) scanf("%lld",&a[u]);
		for (LL u=1;u<n;u++) if (n%u==0&&in[n/u])
		{
			p.push_back(u);
			p1[u].resize(u);
			for (LL i=0;i<u;i++)  p1[u][i]=0;
			for (LL i=1;i<=n;i++) p1[u][i%u]=p1[u][i%u]+a[i];
			for (LL i=0;i<u;i++)  S.push(p1[u][i]*u);
		}
		printf("%lld\n",S.top());
		while (q--)
		{
			LL id,x;
			scanf("%lld%lld",&id,&x);
			for (auto xx:p)
			{
				S.del(p1[xx][id%xx]*xx);
				p1[xx][id%xx]-=a[id];
				p1[xx][id%xx]+=x;
				S.push(p1[xx][id%xx]*xx);
			}
			a[id]=x;
			printf("%lld\n",S.top());
		}
	}
	return 0;
 }