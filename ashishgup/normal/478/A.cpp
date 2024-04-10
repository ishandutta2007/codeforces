#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=10;

int n, sum=0;
int a[N];

int32_t main()
{
	IOS;
	n=5;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	if(sum%n || (sum/n)==0)
		cout<<"-1";
	else
		cout<<sum/n;
	return 0;
}