#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1005;

int n, place;
char a[N][N];

int32_t main()
{
	IOS;
	cin>>n>>place;
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]='.';
		}
	}
	cout<<"YES"<<endl;
	for(int i=2;i<=3;i++)
	{
		for(int j=2, k=n-1;j<k;j++, k--)
		{
			if(place>=2)
			{
				place-=2;
				a[i][j]='#';
				a[i][k]='#';
			}
		}		
	}
	for(int i=2;i<=3;i++)
	{
		if(place>=1)
		{
			place-=1;
			a[i][n/2 + 1]='#';
		}
	}
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}