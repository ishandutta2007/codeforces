#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;
const int N=5*100005;

bool so(const pair<int,int> a,const pair<int,int> b)
{
	return a.second<b.second;
}
int n,m;
vector<int> a[N];
vector<pair<int,int> > v;
int ans;
vector<int> vv;
void dfs(int x,int p,int y)
{
	if(a[x].size()==1)
	{
		v.push_back(make_pair(x,y));
		vv.push_back(0);
	}
	for(int i=0;i<a[x].size();++i)
	{
		int h=a[x][i];
		if(h==p)continue;
		dfs(h,x,y+1);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(int i=0;i<a[1].size();++i)
	{
		int x=a[1][i];
		v.clear();
		vv.clear();
		dfs(x,1,0);
		sort(v.begin(),v.end(),so);
		if(v.size())
		{
			vv[0]=v[0].second+1;
			ans=max(ans,vv[0]);
			for(int j=1;j<v.size();++j)
			{
				vv[j]=max(vv[j-1]+1,v[j].second+1);
				ans=max(ans,vv[j]);
			}
		}
		else
			ans=max(ans,1);
	}
	cout<<ans<<endl;
	return 0;
}