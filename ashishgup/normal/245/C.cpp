#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n, ans=0;
int a[N];

void update(int idx)
{
	int cur=a[idx];
	if(cur<=0)
		return;
	ans+=cur;
	a[idx]-=cur;
	if(idx%2==0 && idx+1>n)
	{
		cout<<"-1";
		exit(0);
	}
	if(idx%2 && (idx/2 < 1 && 2*idx+1>n))
	{
		cout<<"-1";
		exit(0);
	}
	if(idx%2)
		a[idx-1]-=cur;
	a[idx/2]-=cur;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i>=1;i--)
		update(i);
	for(int i=1;i<=n;i++)
	{
		if(a[i]>0)
		{
			cout<<"-1";
			return 0;
		}
	}
	cout<<ans;
	return 0;
}