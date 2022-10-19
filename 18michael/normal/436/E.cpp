#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,w,cnt;
LL ans=0,t=0,res=0;
int a[300002],b[300002],id[300002],to[300002];
multiset<int> ms;
multiset<int>::iterator it;
multiset<int,greater<int> > ms1;
multiset<int,greater<int> >::iterator it1;
inline bool cmpa(int x,int y)
{
	return a[x]<a[y];
}
inline bool cmpb(int x,int y)
{
	return b[x]<b[y];
}
inline void solve(int o)
{
	ms.clear(),ms1.clear(),cnt=w-2;
	for(int i=1;i<=n;++i)ms.insert(a[i]);
	for(int i=1;i<=n;++i,cnt-=2)
	{
		it=ms.lower_bound(a[id[i]]),res+=b[id[i]];
		if(it!=ms.end() && (*it)==a[id[i]])ms.erase(it);
		else res-=a[id[i]],ms1.erase(ms1.lower_bound(a[id[i]])),++cnt;
		for(;ms1.size() && cnt<0;++cnt)res-=(*ms1.begin()),ms.insert(*ms1.begin()),ms1.erase(ms1.begin());
		for(;ms.size() && cnt>0;--cnt)res+=(*ms.begin()),ms1.insert(*ms.begin()),ms.erase(ms.begin());
		if(o && i==t)
		{
			for(int j=1;j<i;++j)
			{
				it1=ms1.lower_bound(b[id[j]]-a[id[j]]);
				if(it1!=ms1.end() && (*it1)==b[id[j]]-a[id[j]])to[id[j]]=2,ms1.erase(it1);
				else to[id[j]]=1;
			}
			to[id[i]]=2;
			for(int j=i+1;j<=n;++j)
			{
				it1=ms1.lower_bound(a[id[j]]);
				if(it1!=ms1.end() && (*it1)==a[id[j]])to[id[j]]=1,ms1.erase(it1);
			}
			return ;
		}
		if(!cnt && res<ans)ans=res,t=i;
		ms1.insert(b[id[i]]-a[id[i]]);
	}
}
int main()
{
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;++i)scanf("%d%d",&a[i],&b[i]),id[i]=i;
	if(w<=n)
	{
		sort(id+1,id+n+1,cmpa);
		for(int i=1;i<=w;++i)ans+=a[id[i]];
	}
	else ans=inf;
	sort(id+1,id+n+1,cmpb),solve(0),printf("%lld\n",ans);
	if(!t)
	{
		sort(id+1,id+n+1,cmpa);
		for(int i=1;i<=w;++i)to[id[i]]=1;
	}
	else solve(1);
	for(int i=1;i<=n;++i)printf("%d",to[i]);
	return 0;
}