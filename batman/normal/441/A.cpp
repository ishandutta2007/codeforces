#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 101*1000

ll n,m;
vector <ll> ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		ll k,a[110];
		cin>>k;
		for(int i=0;i<k;i++)cin>>a[i];
		sort(a,a+k);
		if(a[0]<m)
			ans.push_back(i+1);
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	return 0;
}