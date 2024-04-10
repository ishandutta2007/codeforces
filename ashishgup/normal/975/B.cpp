//Electricity went, laptop about to discharge

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n=14, ans=0;
int a[N], b[N];

void move(int k)
{
	int store=a[k];
	int div=a[k]/n;
	for(int i=1;i<=n;i++)
		b[i]=a[i]+div;
	b[k]=div;
	int rem=a[k]%n;
	int index=k;
	index%=n;
	while(rem>0)
	{
		b[index+1]++;
		index++;
		index%=n;
		rem--;
	}
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i]%2==0)
			cur+=b[i];
	}
	ans=max(ans, cur);
}

int32_t main()
{
	IOS;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		move(i);
	cout<<ans;
	return 0;
}