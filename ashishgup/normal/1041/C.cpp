#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, m, d, reqd=1;
int ans[N];
pair<int, int> a[N];
vector<int> g[N];

void work()
{
	g[1].push_back(a[1].first);
	ans[a[1].second]=1;
	map<int, int> m;
	m[a[1].first]=1;
	for(int i=2;i<=n;i++)
	{
		int minstart=m.begin()->first;
		if(a[i].first-minstart-1<d)
		{
			g[++reqd].push_back(a[i].first);
			m[a[i].first]=reqd;
			ans[a[i].second]=reqd;
		}
		else
		{
			int row=m.begin()->second;
			m.erase(m.begin());
			m[a[i].first]=row;
			ans[a[i].second]=row;
			g[row].push_back(a[i].first);
		}
	}
}

int32_t main()
{
	IOS;
	cin>>n>>m>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a+1, a+n+1);
	work();
	cout<<reqd<<endl;
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	return 0;
}