#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int a[N], b[N];
vector<int> v[N];

int check(int k)
{
	for(int i=0;i<k;i++)
		v[i].clear();
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		v[cur].push_back(a[i]);
		cur++;
		cur%=k;
	}
	for(int i=0;i<k;i++)
	{
		int above=v[i].size();
		for(auto it:v[i])
		{
			above--;
			if(it<above)
				return 0;
		}
	}
	return 1;
}

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi)>>1;
		if(check(mid))
			hi=mid;
		else
			lo=mid+1;
	}
	return lo;
}

int32_t main()
{
	IOS;
	cin>>n;	
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1, a+n+1);
	reverse(a+1, a+n+1);
	int ans=binsearch(1, n);
	cout<<ans;	
	return 0;
}