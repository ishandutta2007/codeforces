#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=2e5+5;

int n, satisfy=0, ans=0;
int a[N];

int check(int i)
{
	if(i%2)
		return a[i]<a[i+1];
	else
		return a[i]>a[i+1];
}

int checkswap(int p, int q)
{
	set<int> s;
	for(int i=-1;i<=1;i++)
	{
		if(p-i>=1&&p-i<n)
			s.insert(p-i);
		if(q-i>=1&&q-i<n)
			s.insert(q-i);
	}
	int store=satisfy;
	for(auto it:s)
		store-=check(it);
	swap(a[p], a[q]);
	for(auto it:s)
		store+=check(it);
	swap(a[p], a[q]);
	if(store==n-1)
		return 1;
	else
		return 0;
}

void work(int k)
{
	for(int i=1;i<=n;i++)
	{
		if(i==k||i==k+1)
			continue;
		ans+=checkswap(i, k);
		ans+=checkswap(i, k+1);
	}
	ans+=checkswap(k, k+1);
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		satisfy+=check(i);
	}
	for(int i=1;i<n;i++)
	{
		if(!check(i))
		{
			work(i);
			break;
		}
	}
	cout<<ans;
	return 0;
}