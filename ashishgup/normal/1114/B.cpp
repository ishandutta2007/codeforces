#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, m, k, ctr=0, sum=0;
int a[N];
multiset<int> s;

int32_t main()
{
	IOS;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		s.insert(a[i]);
	}
	while(s.size()>m*k)
	{
		sum-=*s.begin();
		s.erase(s.begin());
	}
	cout<<sum<<endl;
	for(int i=1;i<=n;i++)
	{
		if(s.find(a[i])!=s.end())
		{
			ctr++;
			s.erase(s.find(a[i]));
			if(ctr%m==0 && ctr<m*k)
				cout<<i<<" ";
		}
	}
	return 0;
}