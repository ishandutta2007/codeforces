#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,q,t;
int w[100002];
vector<int> vec;
inline int calc(LL x,int y)
{
	return x<y? x:(x%y)+y;
}
inline LL Pow(LL a,int b,int mod)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=Pow(a,(b>>1),mod);
	c=calc(c*c,mod);
	if(b&1)c=calc(c*a,mod);
	return c;
}
inline int query(int l,int r,int x)
{
	if(x>=vec.size())return 1;
	if(l==r)return calc(w[l],vec[x]);
	return Pow(w[l],query(l+1,r,x+1),vec[x]);
}
int main()
{
	for(scanf("%d%d",&n,&m);m>1;m=t)
	{
		vec.push_back(t=m);
		for(int i=2;i*i<=m;++i)if(!(m%i))for(t=t/i*(i-1);!(m%i);m/=i);
		if(m>1)t=t/m*(m-1);
	}
	for(int i=1;i<=n;++i)scanf("%d",&w[i]);
	scanf("%d",&q);
	for(int l,r;q--;)scanf("%d%d",&l,&r),printf("%lld\n",query(l,r,0)%(vec.empty()? 1:vec[0]));
	return 0;
}