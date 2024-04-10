#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,invn,invm,b,g,d;
LL t,ans=0;
int _B[100002],_G[100002];
vector<int> B[100002],G[100002];
unordered_map<int,int> mp;
unordered_map<int,int>::iterator it;
typedef pair<int,int> P;
vector<P> vec;
inline int gcd(int x,int y)
{
	return y? gcd(y,x%y):x;
}
inline LL Pow(int a,int b,int mod)
{
	if(!b)return 1;
	LL c=Pow(a,(b>>1),mod);
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
inline int phi(int x)
{
	int res=x;
	for(int i=2;i*i<=x;++i)if(!(x%i))for(res=res/i*(i-1);!(x%i);x/=i);
	if(x>1)res=res/x*(x-1);
	return res;
}
inline LL calc(int n,int m,int inv,vector<int> &B,vector<int> &G)
{
	mp.clear();
	for(int i=0;i<G.size();++i)mp[G[i]]=G[i];
	if(mp.size()==m)return -1;
	for(int i=0;i<B.size();++i)
		if(!mp.count(B[i]%m))
		{
			mp[B[i]%m]=B[i];
			if(mp.size()==m)return B[i];
		}
	for(vec.clear(),it=mp.begin();it!=mp.end();++it)vec.push_back(P(((LL)(*it).first*inv)%m,(*it).second));
	sort(vec.begin(),vec.end()),t=0;
	for(int i=0;i<vec.size();++i)t=max(t,(LL)(vec[(i+1)%vec.size()].first-vec[i].first-1+(i+1==vec.size()? m:0))*n+vec[i].second);
	return t;
}
int main()
{
	scanf("%d%d%d",&n,&m,&b),d=gcd(n,m),n/=d,m/=d,invn=Pow(n,phi(m)-1,m),invm=Pow(m,phi(n)-1,n);
	for(int i=0;i<b;++i)scanf("%d",&_B[i]);
	scanf("%d",&g);
	for(int i=0;i<g;++i)scanf("%d",&_G[i]);
	if(d>b+g)return 0&puts("-1");
	sort(_B,_B+b),sort(_G,_G+g);
	for(int i=0;i<b;++i)B[_B[i]%d].push_back(_B[i]/d);
	for(int i=0;i<g;++i)G[_G[i]%d].push_back(_G[i]/d);
	for(int i=0;i<d;++i)
	{
		if(!B[i].size() && !G[i].size())return 0&puts("-1");
		ans=max(ans,max(calc(n,m,invn,B[i],G[i]),calc(m,n,invm,G[i],B[i]))*d+i);
	}
	return 0&printf("%lld",ans);
}