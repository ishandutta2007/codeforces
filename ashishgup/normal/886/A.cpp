#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=10;

int n=6;
int a[N];

int32_t main()
{
	IOS;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=0;i<(1<<n);i++)
	{	
		if(__builtin_popcount(i)!=3)
			continue;
		int suma=0, sumb=0;
		for(int j=0;j<n;j++)
		{
			if(i>>j &1)
				suma+=a[j+1];
			else
				sumb+=a[j+1];
		}
		if(suma==sumb)
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}