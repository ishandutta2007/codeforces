#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, h;
pair<int, int> a[N];
int mark[N];

int check(int k)
{
	vector<int> v1, v2;
	mark[a[1].second]=1;
	mark[a[2].second]=1;
	v1.push_back(a[1].first);
	v1.push_back(a[2].first);
	for(int i=3;i<=n;i++)
	{
		if(abs((v1.back()+a[i].first)-(v1[0]+v1[1]))>k)
		{
			for(int j=i;j<=n;j++)
			{
				v2.push_back(a[j].first);
				mark[a[j].second]=2;
			}
			break;
		}
		else
		{
			mark[a[i].second]=1;
			v1.push_back(a[i].first);
		}
	}
	vector<int> maxpos, minpos;
	maxpos.push_back(v1[0]+v1[1]);
	if(v2.size()>=2)
		maxpos.push_back(v2[0]+v2[1]);
	if(v2.size())
		maxpos.push_back(v1[0]+v2[0]+h);
	sort(maxpos.rbegin(), maxpos.rend());
	minpos.push_back(v1[v1.size()-1]+v1[v1.size()-2]);
	if(v2.size()>=2)
		minpos.push_back(v2[v2.size()-1]+v2[v2.size()-2]);
	if(v2.size())
		minpos.push_back(v1.back()+v2.back()+h);
	sort(minpos.begin(), minpos.end());
	return (maxpos[0]-minpos[0])<=k;
}

int binary_search(int lo, int hi)
{	
	while(lo<hi)
	{
		int mid=(lo+hi)/2;
		if(check(mid))
			hi=mid;
		else
			lo=mid+1;
	}
	check(lo);
	return lo;
}

int32_t main()
{
	IOS;
	cin>>n>>h;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a+1, a+n+1);
	reverse(a+1, a+n+1);
	int ans=binary_search(0, 2e13);
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
		cout<<mark[i]<<" ";
	return 0;
}