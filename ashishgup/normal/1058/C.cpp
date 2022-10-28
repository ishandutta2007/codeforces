#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n, sum=0;
char a[N];

void check(int k)
{
	if(sum>0 && k==sum)
		return;
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		cur+=(a[i]-'0');
		if(cur==k)
			cur=0;
		if(cur>k)
			return;
	}
	if(cur!=0)
		return;
	cout<<"YES";
	exit(0);
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i]-'0';
	}
	if(sum==0)
	{
		cout<<"YES";
		return 0;
	}
	for(int i=1;i*i<=sum;i++)
	{
		if(sum%i==0)
		{
			int pos=i;
			check(pos);
			pos=sum/i;
			check(pos);
		}
	}
	cout<<"NO";
	return 0;
}