#include <bits/stdc++.h> 
using namespace std; 
#define ll long long
#define ld long double
#define N ((int)2010)

int a[4][4]={8,9,1,13,
3,12,7,5,
0,2,4,11,
6,10,15,14};
int n;
int res[N][N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i+=4)
	{
		for(int j=0;j<n;j+=4)
		{
			int x=i*(n/4)+j;
			x*=4;
			for(int i1=0;i1<4;i1++)
				for(int j1=0;j1<4;j1++)
					res[i+i1][j+j1]=x+a[i1][j1];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<res[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}