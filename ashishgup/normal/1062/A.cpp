#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, ans=0;
int a[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	a[0]=0;
	a[n+1]=1001;
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i-1]+1 && a[i]==a[i+1]-1)
			cur++;
		else
			cur=0;
		ans=max(cur, ans);
	}
	cout<<ans;
	return 0;
}