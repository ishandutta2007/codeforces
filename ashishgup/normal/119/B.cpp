#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N=105;

int n, k, q, sz, rem;
int a[N], vis[N];
double mn=1e9, mx=0;
vector<int> v;

int32_t main()
{
	IOS;
	cin>>n>>k;
	sz=n/k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>q;
	while(q--)
	{
		int cur=0;
		for(int i=1;i<=sz;i++)
		{
			int num;
			cin>>num;
			cur+=a[num];
			vis[num]=1;
		}
		double curans=(double)cur/sz;
		mn=min(mn, curans);
		mx=max(mx, curans);
	}
	int taken=0;
	for(int i=1;i<=n;i++)
		taken+=vis[i];
	int rem=k - taken/sz;
	if(rem)
	{
		for(int i=1;i<=n;i++)
			if(!vis[i])
				v.push_back(a[i]);
		sort(v.begin(), v.end());
		int cur=0;
		for(int i=0;i<sz;i++)
			cur+=v[i];
		double curans=(double)cur/sz;
		mn=min(mn, curans);
		mx=max(mx, curans);
		reverse(v.begin(), v.end());
		cur=0;
		for(int i=0;i<sz;i++)
			cur+=v[i];
		curans=(double)cur/sz;
		mn=min(mn, curans);
		mx=max(mx, curans);
	}
	cout<<fixed<<setprecision(12)<<mn<<" "<<mx;
	return 0;
}