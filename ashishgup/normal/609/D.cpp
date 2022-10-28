#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, m, k, s;
int a[N], b[N], t[N], c[N];
vector<pair<int, int> > ans;

int check(int d)
{
	int dollar=1e6+1, day=1;
	for(int i=1;i<=d;i++)
	{
		if(a[i]<dollar)
		{
			dollar=a[i];
			day=i;
		}
	}
	int pound=1e6+1, day2=1;
	for(int i=1;i<=d;i++)
	{
		if(b[i]<pound)
		{
			pound=b[i];
			day2=i;
		}
	}	
	vector<pair<int, int> > v;
	for(int i=1;i<=m;i++)
	{
		if(t[i]==1)
			v.push_back({c[i]*dollar, i});
		else
			v.push_back({c[i]*pound, i});
	}
	sort(v.begin(), v.end());
	int have=s;
	for(int i=0;i<k;i++)
	{
		have-=v[i].first;
		if(have<0)
			return 0;
	}
	ans.clear();
	for(int i=0;i<k;i++)
	{
		if(t[v[i].second]==1)
			ans.push_back({v[i].second, day});
		else
			ans.push_back({v[i].second, day2});
	}
	return 1;
}

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi)/2;
		if(check(mid))
			hi=mid;
		else
			lo=mid+1;
	}
	if(lo<=n && check(lo))
		return lo;
	else
		return -1;
}

int32_t main()
{
	IOS;
	cin>>n>>m>>k>>s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=m;i++)
		cin>>t[i]>>c[i];
	int day=binsearch(1, n);
	cout<<day<<endl;
	if(day!=-1)
	{
		for(auto it:ans)
			cout<<it.first<<" "<<it.second<<endl;
	}
	return 0;
}