#include <bits/stdc++.h>
using namespace std;
int n,m,cnt[105];
deque<int> arr[105],s[105];
vector<int> c;
int solve(int idx,int rem)
{
	if (idx==m)
	{
		int cur=0;
		set<int> ch(c.begin(),c.end());
		if (ch.size()!=2)
		{
			for (int i:c)
			{
				cur+=s[i][cnt[i]];
				cnt[i]++;
			}
			for (int i:c)
			cnt[i]--;
			return cur;
		}
		int c1=*ch.begin(),c2=*next(ch.begin());
		for (int i=0;i<n;i++)
		{
			int tmp=0;
			arr[c1].push_front(arr[c1].back());
			arr[c1].pop_back();
			for (int j=0;j<n;j++)
			tmp+=max(arr[c1][j],arr[c2][j]);
			cur=max(cur,tmp);
		}
		return cur;
	}
	int ret=solve(idx+1,rem);
	if (rem)
	{
		c.push_back(idx);
		ret=max(ret,solve(idx,rem-1));
		c.pop_back();
	}
	return ret;
}
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int ans=0;
		scanf("%d%d",&n,&m);
		for (int i=0;i<m;i++)
		arr[i].resize(n);	
		vector<pair<int,int> > v;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
			{
				scanf("%d",&arr[j][i]);
				v.push_back({arr[j][i],j});
			}
		}
		for (int i=0;i<m;i++)
		{
			s[i]=arr[i];
			sort(s[i].begin(),s[i].end(),greater<int>());
		}
		sort(v.begin(),v.end(),greater<pair<int,int> >());
		if (n==1)
		{
			printf("%d\n",solve(0,1));
			continue;
		}
		for (int i=0;i<min(n*m,6);i++)
		{
			int c1=v[i].second;
			c.push_back(c1);
			for (int j=i+1;j<min(n*m,6);j++)
			{
				int c2=v[j].second;
				c.push_back(c2);
				ans=max(ans,solve(0,n-2));
				c.pop_back();
			}
			c.pop_back();
		}
		printf("%d\n",ans);
	}
}