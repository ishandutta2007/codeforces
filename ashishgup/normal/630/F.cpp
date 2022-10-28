#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e3+5;

int nCr[N][N];

void precompute()
{
	nCr[0][0]=1;
	for(int i=1;i<N;i++)
	{
		nCr[i][0]=1;
		for(int j=i;j>0;j--)
		{
			nCr[i][j]=nCr[i-1][j] + nCr[i-1][j-1];
		}
	}
}

int32_t main()
{
	IOS;
	precompute();
	int n;
	cin>>n;
	int ans=nCr[n][5] + nCr[n][6] + nCr[n][7];
	cout<<ans;
 	return 0;
}