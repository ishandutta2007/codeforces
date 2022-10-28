#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

const int N=1e6+5;

int n, diff;
int a[N], vis[N];

void query(int x)
{
	if(vis[x])
		return;
	cout<<"? "<<x<<endl;
	cin>>a[x];
	vis[x]=1;
}

void print(int x)
{
	cout<<"! "<<x<<endl;
	exit(0);
}

int sign(int x)
{
	return x/abs(x);
}

int check(int x)
{
	query(x);
	query(x + n/2);
	int curdiff=a[x] - a[x+n/2];
	if(curdiff==0)
		print(x);
	if(sign(diff) == sign(curdiff))
		return 1;
	return 0;
}

void binary_search(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi)/2;
		if(check(mid))
			lo=mid+1;
		else
			hi=mid;
	}
	print(lo);
}

int32_t main()
{
	IOS;
	cin>>n;
	query(1);
	query(n/2 + 1);
	diff=a[1] - a[n/2 + 1];
	if(diff%2)
		print(-1);
	else if(diff==0)
		print(1);
	else
		binary_search(1, n/2);
	return 0;
}