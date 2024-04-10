#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int MOD=1e9+7;

void copy(int arr[2][2], int brr[2][2])
{
	for(int i=0;i<=1;i++)
	{
		for(int j=0;j<=1;j++)
		{
			arr[i][j]=brr[i][j];
		}
	}
}

void mult(int arr[2][2], int brr[2][2])
{
	int crr[2][2];
	memset(crr, 0, sizeof(crr));
	for(int i=0;i<=1;i++)
	{
		for(int j=0;j<=1;j++)
		{
			for(int k=0;k<=1;k++)
			{
				crr[i][j]+=arr[i][k] * brr[k][j];
				crr[i][j]%=MOD;
			}
		}
	}
	copy(arr, crr);
}

void matrixexpo(int arr[2][2], int n)
{
	int res[2][2]={{1, 0}, {0, 1}};
	while(n>0)
	{
		if(n%2)
			mult(res, arr);
		mult(arr, arr);
		n/=2;
	}
	copy(arr, res);
}

int32_t main()
{
	IOS;
	int n;
	cin>>n;
	int v[2][2]={{3, 1}, {1, 3}};
	matrixexpo(v, n);
	cout<<v[0][0];
}