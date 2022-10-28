#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n;
int a[10][N];

int32_t main()
{
	IOS;
	memset(a, -1, sizeof(a));
	cin>>n;
	if(n==1)
	{
		cout<<"a\na\nb\nb";
		return 0;
	}
	a[1][1]=0;
	a[2][1]=1;
	a[3][1]=2;
	a[4][1]=2;
	a[1][2]=0;
	a[2][2]=1;
	a[3][2]=3;
	a[4][2]=3;
	int cur=4;
	for(int i=3;i<=n;i++)
	{
		int c1=cur++;
		cur%=26;
		int c2=cur++;
		cur%=26;
		if(a[1][i-1]==a[2][i-1])
		{
			a[1][i]=a[1][i-1];
			a[2][i-1]=a[2][i]=c1;
			a[3][i]=a[4][i]=c2;
		}
		else
		{
			a[4][i]=a[4][i-1];
			a[3][i-1]=a[3][i]=c1;
			a[2][i]=a[1][i]=c2;
		}
	}
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<(char)(a[i][j]+'a');
		}
		cout<<endl;
	}
	return 0;
}