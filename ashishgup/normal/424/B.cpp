#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e3+5;

int n, s;
int x[N], y[N], k[N];
vector<int> idx;

int dist(int idx)
{
	return x[idx]*x[idx] + y[idx]*y[idx];
}

bool comp(int i, int j)
{
	if(dist(i)!=dist(j))
		return dist(i)<dist(j);
	return k[i]>k[j];
}

int32_t main()
{
	IOS;
	cin>>n>>s;
	for(int i=1;i<=n;i++)
	{
		idx.push_back(i);
		cin>>x[i]>>y[i]>>k[i];
	}
	sort(idx.begin(), idx.end(), comp);
	for(int i=0;i<idx.size();i++)
	{
		s+=k[idx[i]];
		if(s>=1e6)
		{
			double ans=sqrtl(dist(idx[i]));
			cout<<fixed<<setprecision(12)<<ans;
			return 0;
		}
	}
	cout<<"-1";
	return 0;
}