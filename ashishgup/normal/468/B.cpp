#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e6+5;

int n, a, b;
int v[N];
vector<int> temp;
map<int, int> m;

int32_t main()
{
	IOS;
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
		m[v[i]]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(m.find(a-v[i])==m.end())
			temp.push_back(v[i]);
	}
	for(int i=0;i<temp.size();i++)
	{
		int it=temp[i];
		m[it]=2;
		if(m.find(b-it)==m.end())
			return cout<<"NO", 0;
		if(m[b-it]==2)
			continue;
		m[b-it]=2;
		if(m[a-(b-it)]==1)
		{
			m[a-(b-it)]=2;
			temp.push_back(a-(b-it));
		}
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<m[v[i]]-1<<" ";
	}
}