#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, k;
int a[N], f[N];
vector<int> v;

int check(int x)
{
	int take=0;
	for(int i=1;i<=2e5;i++)
	{
		take+=f[i]/x;
		if(take>=k)
			return 1;
	}	
	return 0;
}

void work(int x)
{
	int take=k;
	for(int i=1;i<=2e5;i++)
	{
		int cur=min(take, f[i]/x);
		take-=cur;
		for(int j=1;j<=cur;j++)
			v.push_back(i);
	}	
}

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi+1)/2;
		if(check(mid))
			lo=mid;
		else
			hi=mid-1;
	}	
	return lo;
}

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[a[i]]++;
	}
	int ans=binsearch(1, n/k);
	work(ans);
	for(auto &it:v)
		cout<<it<<" ";
	return 0;
}