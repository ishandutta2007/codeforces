#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
#define ll long long
#define N 805000
multiset<int> s1,s2;
int n,lz,sl,sr,x,y,ls;
ll as;
pair<int,int> tp[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&x,&y),tp[i]=make_pair(x+y,y);
	sort(tp+1,tp+n+1);
	for(int i=1;i<=n;i++)s1.insert(0),s2.insert(1e9);
	sl=0,sr=1e9;ls=tp[n].first;
	for(int i=n;i>=1;i--)
	{
		int vl=ls-tp[i].first;ls=tp[i].first;
		sl-=vl;lz+=vl;
		int sy=tp[i].second;
		if(sl<=sy&&sy<=sr)s1.insert(sy+lz),s2.insert(sy),sl=sr=sy;
		else if(sl>sy)
		{
			as+=sl-sy;
			int lb=(*s1.rbegin())-lz;s1.erase(s1.find(lb+lz));
			s2.insert(sl);
			s1.insert(sy+lz);s1.insert(sy+lz);
			sr=sl;sl=(*s1.rbegin())-lz;
		}
		else
		{
			as+=sy-sr;
			int rb=*s2.begin();s2.erase(s2.find(rb));
			s1.insert(sr+lz);
			s2.insert(sy);s2.insert(sy);
			sl=sr;sr=*s2.begin();
		}
	}
	lz+=ls;
	while((*s1.rbegin())-lz>0){int tp=*s1.rbegin();as+=tp-lz;s1.erase(s1.find(tp));}
	while((*s2.begin())<0){int tp=*s2.begin();as-=tp;s2.erase(s2.find(tp));}
	printf("%lld\n",as);
}