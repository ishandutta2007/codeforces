#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=25;

int n, m;
int a[N][N];
bool flag=0;

void swap_col(int idx1, int idx2)
{
	for(int i=1;i<=n;i++)
		swap(a[i][idx1], a[i][idx2]);
}

bool check()
{
	for(int i=1;i<=n;i++)
	{
		int reqd=0;
		for(int j=1;j<=m;j++)
			reqd+=(a[i][j]!=j);
		if(reqd>2)
			return 0;
	}
	return 1;
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=m;i++)
	{
		for(int j=i;j<=m;j++)
		{
			swap_col(i, j);
			flag|=check();
			swap_col(i, j);
		}
	}
	if(flag)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}