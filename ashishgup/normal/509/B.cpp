#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n, k;
int a[N];
vector<int> v[N];

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=1;j<=k;j++)
		{
			int cur=a[i]/k;
			if(a[i]-cur*k-(j-1)>=1)
				cur++;
			v[j].push_back(cur);
		}
	}
	for(int i=1;i<=k;i++)
	{
		sort(v[i].begin(), v[i].end());
		if(v[i].back()-v[i][0]>1)
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			int cur=j%k;
			if(cur==0)
				cur=k;
			cout<<cur<<" ";
		}
		cout<<endl;
	}
	return 0;
}