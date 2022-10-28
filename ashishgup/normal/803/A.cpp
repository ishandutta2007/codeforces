#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=105;

int n, k;
int a[N][N];

int32_t main()
{
	IOS;
	cin>>n>>k;
	if(k>n*n)
		return cout<<"-1", 0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(i==j && k>=1)
				a[i][j]=1, k--;
			else if(i!=j && k>=2)
				a[i][j]=a[j][i]=1, k-=2;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}