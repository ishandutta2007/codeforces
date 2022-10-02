#include <bits/stdc++.h>
#define int long long
using namespace std;
multiset <int> s;
vector <int> a[200005],id[200005];
int sum[200005],qwq[200005],ans[200005];
inline void solve(int l,int r)
{
	if(l==r)
	{
		for(int i=0;i<a[l].size();i++)
		{
			int nxts=sum[l]-a[l][i];
			nxts=(nxts-2+a[l].size())/(a[l].size()-1);
			if(*s.lower_bound(nxts)<=1e17)
				ans[id[l][i]]=1;
			else ans[id[l][i]]=0;
		}
		return ;
	}
	int mid=(l+r)/2;
	int flag=0;
	for(int i=l;i<=mid;i++)
	{
		int k=*s.lower_bound((sum[i]-1+a[i].size())/a[i].size());
		if(k>1e17)
		{
			for(int j=mid+1;j<=r;j++)
			{
				for(auto t:id[j])
					ans[t]=0;
				flag=1;
			}
			break;
		}
		s.erase(s.find(k));
		qwq[i]=k;
	}
	if(!flag) solve(mid+1,r);
	for(int i=l;i<=mid;i++)
		if(qwq[i]) s.insert(qwq[i]),qwq[i]=0;
	flag=0;
	for(int i=mid+1;i<=r;i++)
	{
		int k=*s.lower_bound((sum[i]-1+a[i].size())/a[i].size());
		if(k>1e17)
		{
			for(int j=l;j<=mid;j++)
			{
				for(auto t:id[j])
					ans[t]=0;
				flag=1;
			}
			break;
		}
		s.erase(s.find(k));
		qwq[i]=k;
	}
	if(!flag) solve(l,mid);
	for(int i=mid+1;i<=r;i++)
		if(qwq[i]) s.insert(qwq[i]),qwq[i]=0;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		s.clear();
		s.insert(1e18);
		for(int i=1;i<=m;i++) a[i].clear(),id[i].clear(),sum[i]=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin >> x;
			s.insert(x);
		}
		int ID=0;
		for(int i=1;i<=m;i++)
		{
			int k;
			cin >> k;
			while(k--)
			{
				int x;
				cin >> x;
				sum[i]+=x;
				a[i].push_back(x);
				id[i].push_back(++ID);
			}
		}
		solve(1,m);
		for(int i=1;i<=ID;i++)
			cout << ans[i];
		cout << "\n";
	}
	return 0;
}