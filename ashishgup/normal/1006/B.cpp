#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2005;

int n, k, ans=0;
pair<int, int> a[N];
vector<int> v;

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a+1, a+n+1);
	reverse(a+1, a+n+1);
	v.push_back(0);
	for(int i=1;i<=k;i++)
	{
		ans+=a[i].first;
		v.push_back(a[i].second);
	}
	v.push_back(n+1);
	sort(v.begin(), v.end());
	cout<<ans<<endl;
	v.pop_back();
	v.pop_back();
	v.push_back(n);
	for(int i=0;i+1<v.size();i++)
		cout<<v[i+1]-v[i]<<" ";
	return 0;
}