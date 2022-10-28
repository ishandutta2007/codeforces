#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, k, curgcd=0;
int a[N], vis[N];
vector<int> v;

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]%=k;
		curgcd=__gcd(curgcd, a[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int cur=a[i];
		while(!vis[cur])
		{
			ans++;
			vis[cur]=1;
			v.push_back(cur);
			cur+=curgcd;
			cur%=k;
		}
	}
	sort(v.begin(), v.end());
	cout<<v.size()<<endl;
	for(auto it:v)
		cout<<it<<" ";
	return 0;
}