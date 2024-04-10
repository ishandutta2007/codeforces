#include<bits/stdc++.h>
using namespace std;
int n,G=0,ans=0;
int a[200002],mn[400008];
set<int> s[200002];
set<int>::iterator it,it1;
typedef pair<int,int> P;
vector<P> vec;
inline void solve(int x)
{
	for(vec.clear(),it=s[x].begin();it!=s[x].end();++it)
	{
		vec.push_back(P(*it,-1));
		if((it1=s[G].lower_bound(*it))!=s[G].end())
		{
			vec.push_back(P(*it1,1));
			if((it1=s[G].erase(it1))!=s[G].end())vec.push_back(P(*it1,1)),s[G].erase(it1);
		}
		if((it1=s[G].lower_bound(*it))!=s[G].begin())
		{
			vec.push_back(P(*(--it1),1)),it1=s[G].erase(it1);
			if(it1!=s[G].begin())vec.push_back(P(*(--it1),1)),s[G].erase(it1);
		}
	}
	vec.push_back(P(0,0)),vec.push_back(P(n+1,0)),sort(vec.begin(),vec.end());
	for(int i=(vec.size()<<1);~i;--i)mn[i]=n;
	for(int i=0,x=vec.size();i+1<vec.size();++i)x+=vec[i].second,ans=max(ans,vec[i+1].first-mn[x]-1),mn[x]=min(mn[x],vec[i].first);
	for(int i=0;i<vec.size();++i)if(vec[i].second>0)s[G].insert(vec[i].first);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),s[a[i]].insert(i);
	for(int i=1;i<=n;++i)if(s[i].size()>s[G].size())G=i;
	for(int i=1;i<=n;++i)if(i^G)solve(i);
	return 0&printf("%d",ans);
}