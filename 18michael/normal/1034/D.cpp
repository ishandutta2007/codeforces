#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,k,l=1,r=1000000000,mid;
LL sum,res,tmp=0,ans=0;
int a[300002],b[300002];
LL cnt[300002];
typedef pair<int,int> P;
struct aaa
{
	int l,r,x;
	inline bool operator < (const aaa &a) const
	{
		return l==a.l? (r==a.r? (x<a.x):(r<a.r)):(l<a.l);
	}
}t;
set<aaa> s;
set<aaa>::iterator it;
vector<aaa> Vec;
struct bbb
{
	int r,x;
};
vector<bbb> vec[300002];
inline void cut(int x)
{
	it=s.lower_bound((aaa){x,0,0});
	if(it!=s.begin() && (t=(*(--it))).r>=x)s.erase(it),s.insert((aaa){t.l,x-1,t.x}),s.insert((aaa){x,t.r,t.x});
}
inline void split(int l,int r)
{
	for(cut(l),cut(r+1),it=s.lower_bound((aaa){l,0,0});it!=s.end() && (*it).r<=r;it=s.erase(it))Vec.push_back(*it);
}
inline void init()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d%d",&a[i],&b[i]),--b[i];
	for(int i=1;i<=n;++i)
	{
		for(split(a[i],b[i]);Vec.size();Vec.pop_back())vec[i].push_back((bbb){Vec.back().x,Vec.back().l-Vec.back().r-1});
		s.insert((aaa){a[i],b[i],i}),vec[i].push_back((bbb){i,b[i]-a[i]+1});
	}
}
inline bool check()
{
	sum=res=0;
	for(int i=1;i<=n;++i)cnt[i]=0;
	for(int i=1,j=1;i<=n;++i)
	{
		for(int k=0;k<vec[i].size();++k)if(vec[i][k].r>=j)res+=vec[i][k].x,cnt[vec[i][k].r]+=vec[i][k].x;
		for(;j<=i && res>=mid;++j)res-=cnt[j];
		sum+=j-1;
	}
	if(sum<k)return 0;
	return 1;
}
int main()
{
	for(init();l<=r;)
	{
		mid=((l+r)>>1);
		if(check())l=mid+1;
		else r=mid-1;
	}
	sum=res=0;
	for(int i=1;i<=n;++i)cnt[i]=0;
	for(int i=1,j=1;i<=n;++i)
	{
		for(int k=0;k<vec[i].size();++k)
		{
			cnt[vec[i][k].r]+=vec[i][k].x,tmp+=(LL)vec[i][k].r*vec[i][k].x;
			if(vec[i][k].r>=j)res+=vec[i][k].x,tmp-=(LL)(vec[i][k].r-j+1)*vec[i][k].x;
		}
		for(;j<=i && res>=l;++j)tmp+=res,res-=cnt[j];
		sum+=j-1,ans+=tmp;
	}
	return 0&printf("%lld",ans+(LL)(k-sum)*r);
}