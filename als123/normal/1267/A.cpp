#include<cstdio>
#include<iostream>
#include<algorithm>
#include<iostream>
#include<set>
using namespace std;
typedef long long LL;
const LL N=400005;
LL n;
struct qq
{
	LL l,r,t,d;
}a[N];
struct qy
{
	LL x;
	LL op;
	LL id;
}b[N];LL nn;
bool cmp (qy x,qy y)	{return x.x<y.x;}
multiset<LL> s;
multiset<LL> d;
multiset<LL> :: iterator it;
LL R;
int main()
{
	scanf("%lld",&n);R=0;
	for (LL u=1;u<=n;u++) 
	{
		scanf("%lld%lld%lld",&a[u].l,&a[u].r,&a[u].t);
		a[u].d=a[u].l+a[u].t;
		R=max(R,a[u].r);
		b[++nn].x=a[u].l;b[nn].op=0;b[nn].id=u;
		b[++nn].x=a[u].r-a[u].t+1;b[nn].op=1;b[nn].id=u;
		d.insert(a[u].d);
	}
	d.insert(R+1);	s.insert(R+1);
	sort(b+1,b+1+nn,cmp);
	LL x=0,ans=0;
	LL now=0;
	while (x<=R)
	{
		LL t=*s.begin();
		LL x1=x+t;
		LL x2=*(d.begin());
		if (min(x1,x2)>R) break;
		if (x1<=x2)
		{
			LL lim=b[now+1].x;
			LL tt,tt1;
			
			tt=(lim-x)/t;
			if (x+t*tt<lim) tt++;
			tt1=(x2-x1)/t+1;
			tt=min(tt,tt1);
			
			x=x+t*tt;
			ans+=tt;
			while (now<nn&&b[now+1].x<=x)
			{
				now++;
				LL xx=b[now].id,o=b[now].op;
				if (o==0)
				{
					it=d.find(a[xx].d);d.erase(it);
					s.insert(a[xx].t);
				}
				else
				{
					it=s.find(a[xx].t);
					s.erase(it);
				}
			}
		}
		else
		{
			ans++;
			x=x2;
			while (now<nn&&b[now+1].x<=x)
			{
				now++;
				LL xx=b[now].id,o=b[now].op;
				if (o==0)
				{
					it=d.find(a[xx].d);	d.erase(it);
					s.insert(a[xx].t);
				}
				else
				{
					it=s.find(a[xx].t);
					s.erase(it);
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}