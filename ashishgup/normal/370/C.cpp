#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5005;

int n, m, ans=0;
int a[N];
vector<pair<int, int> > v;

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a, a+n);
	for(int i=0;i<n;i++)
	{
		if(a[i]!=a[(i+n/2)%n])
		{
			ans++;	
			v.push_back({a[i], a[(i+n/2)%n]});
		}
		else
			v.push_back({a[i], a[i]});
	}
	cout<<ans<<endl;
	for(auto &it:v)
		cout<<it.first<<" "<<it.second<<endl;
	return 0;
}