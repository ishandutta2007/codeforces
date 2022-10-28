#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n,m;
vector<int> a, b;

vector<int> diffarray(vector<int> v)
{
	int sz=v.size();
	vector<int> ans;
	for(int i=1;i<sz;i++)
	{
		ans.push_back(v[i]-v[i-1]);
	}
	return ans;
}

vector<int> zalgorithm(vector<int> v)
{
	int sz=v.size();
	vector<int> z(sz);
	for(int i=1, l=0, r=0; i<sz; i++)
	{
		if(i<=r)
		{
			z[i]=min(r-i+1, z[i-l]);
		}
		while(i + z[i] < sz && v[z[i]] == v[i + z[i]])
		{
			z[i]++;
		}
		if(i + z[i] - 1 > r)
		{
			l=i;
			r=i + z[i]- 1;
		}
	}
	return z;
}

int countocc()
{
	if(b.size()==0)
	{
		return a.size()+1;
	}
	b.insert(b.end(), a.begin(), a.end());
	int sz=b.size();
	vector<int> getz=zalgorithm(b);
	int ans=0;
	for(int i=m-1;i<sz;i++)
	{
		if(getz[i]>=m-1)
		{
			ans++;
		}
	}
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	a=vector<int> (n);
	b=vector<int> (m);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<m;i++)
	{
		cin>>b[i];
	}
	a=diffarray(a);
	b=diffarray(b);
	int ans=countocc();
	cout<<ans;
	return 0;
}