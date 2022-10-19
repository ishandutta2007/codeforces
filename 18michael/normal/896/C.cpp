#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,seed,vmax;
LL ans;
struct aaa
{
	int l,r;
	LL val;
	inline bool operator < (const aaa &a) const
	{
		return l==a.l? (r<a.r):(l<a.l);
	}
}p;
vector<aaa> vec;
set<aaa> s;
set<aaa>::iterator it;
inline int rnd()
{
	int ret=seed;
	seed=(seed*7LL+13)%1000000007;
	return ret;
}
inline bool cmp(aaa a,aaa b)
{
	return a.val<b.val;
}
inline LL Pow(int a,int b,int mod)
{
	if(!b)return 1;
	LL c=Pow(a,b>>1,mod);
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
inline void cut(int x)
{
	it=s.lower_bound((aaa){x,0,0});
	if(it!=s.end() && (*it).l==x)return ;
	p=*(--it),s.erase(it),s.insert((aaa){p.l,x-1,p.val}),s.insert((aaa){x,p.r,p.val});
}
inline void split(int l,int r,bool o)
{
	for(cut(l),cut(r+1),vec.clear(),it=s.lower_bound((aaa){l,0,0});it!=s.end() && (*it).r<=r;o? it=s.erase(it):++it)vec.push_back(*it);
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&seed,&vmax);
	for(int i=1;i<=n;++i)s.insert((aaa){i,i,(rnd()%vmax)+1});
	for(int o,l,r,x,y;m--;)
	{
		o=(rnd()%4)+1,l=(rnd()%n)+1,r=(rnd()%n)+1;
		if(l>r)swap(l,r);
		split(l,r,o<=2);
		if(o==3)x=(rnd()%(r-l+1))+1;
		else x=(rnd()%vmax)+1;
		if(o==1)for(int i=0;i<vec.size();++i)vec[i].val+=x,s.insert(vec[i]);
		else if(o==2)s.insert((aaa){l,r,x});
		else if(o==3)
		{
			sort(vec.begin(),vec.end(),cmp);
			for(int i=0;i<vec.size();++i)
			{
				if(x<=vec[i].r-vec[i].l+1)
				{
					printf("%lld\n",vec[i].val);
					break;
				}
				x-=vec[i].r-vec[i].l+1;
			}
		}
		else
		{
			y=(rnd()%vmax)+1,ans=0;
			for(int i=0;i<vec.size();++i)(ans+=Pow(vec[i].val%y,x,y)*(vec[i].r-vec[i].l+1))%=y;
			printf("%lld\n",ans%y);
		}
	}
	return 0;
}