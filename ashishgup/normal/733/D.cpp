#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int ans=0, idx1, idx2;
map<pair<int, int>, pair<int, int> > m;

void insert(int a, int b, int c, int i)
{
	pair<int, int> p = {b, c};
	if(m.find(p)==m.end())
		m[p]={a, i};
	else
	{
		if(a>m[p].first)
			m[p]={a, i};
	}	
}

void update(int a, int b, int c, int i)
{
	pair<int, int> p={b, c};
	if(m.find(p)!=m.end())
	{
		int cur=min({m[p].first + a, b, c});
		if(cur>ans)
		{
			ans=cur;
			idx1=i;
			idx2=m[p].second;
		}
	}
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		vector<int> v;
		for(int j=1;j<=3;j++)
		{
			int x;
			cin>>x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		if(v[0]>ans)
		{
			ans=v[0];
			idx1=i;
			idx2=0;
		}

		update(v[0], v[1], v[2], i);
		update(v[1], v[0], v[2], i);
		update(v[2], v[0], v[1], i);

		insert(v[0], v[1], v[2], i);
		insert(v[1], v[0], v[2], i);
		insert(v[2], v[0], v[1], i);
	}		
	if(idx2)
	{
		cout<<2<<endl;
		cout<<idx1<<" "<<idx2;
	}
	else
	{
		cout<<1<<endl;
		cout<<idx1;
	}
	return 0;
}