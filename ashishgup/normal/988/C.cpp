#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int k;
int a[N];
set<int> s;
map<int, pair<int, int> > m;

int32_t main()
{
	IOS;
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		int n;
		cin>>n;
		int sum=0;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
			sum+=a[j];
		}
		for(int j=1;j<=n;j++)
		{
			if(s.find(sum-a[j])!=s.end())
			{
				cout<<"YES"<<endl;
				cout<<m[sum-a[j]].first<<" "<<m[sum-a[j]].second<<endl;
				cout<<i<<" "<<j;
				return 0;
			}
		}
		for(int j=1;j<=n;j++)
		{
			s.insert(sum-a[j]);
			m[sum-a[j]]={i, j};
		}
	}
	cout<<"NO";
	return 0;
}