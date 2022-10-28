#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
pair<int, int> a[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first;
		a[i].second=i;
	}	
	sort(a+1, a+n+1);
	if(n==1)
		cout<<"-1";
	else if(n==2)
	{
		if(a[1].first==a[2].first)
			cout<<"-1";
		else
			cout<<"1\n1";
	}
	else
		cout<<1<<"\n"<<a[1].second;
	return 0;
}