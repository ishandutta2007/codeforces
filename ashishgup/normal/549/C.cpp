#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, k, odd=0, even=0;
int a[N];

bool isWin()
{
	if((n-k)%2) //Turn ends at Stannis
	{
		int canRemove=(n-k)/2;
		if(even<=canRemove && k%2==0)
			return 0;
		if(odd<=canRemove)
			return 0;
		return 1;
	}
	else //Turn ends at Daenerys
	{
		if(n==k)
			return odd&1;
		int canRemove=(n-k)/2;
		if(odd<=canRemove)
			return 0;
		if(even<=canRemove && k%2==1)
			return 1;
		return 0;
	}
}	

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]%2)
			odd++;
		else
			even++;
	}
	if(isWin())
		cout<<"Stannis";
	else
		cout<<"Daenerys";
	return 0;
}