#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;
int n, ans;
char a[5][N][N];
vector<int> v;

void workwhite()
{
	int cnt=0;
	int cur=1;
	int checker=0;
	for(auto it:v)
	{
		checker++;
		if(checker==3)
			cur=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[it][i][j]!=(cur+'0'))
				{
					cnt++;
				}
				cur^=1;
			}
		}
	}
	ans=min(ans, cnt);
}

void workblack()
{
	int cnt=0;
	int cur=0;
	int checker=0;
	for(auto it:v)
	{
		checker++;
		if(checker==3)
			cur=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[it][i][j]!=(cur+'0'))
				{
					cnt++;
				}
				cur^=1;
			}
		}
	}
	ans=min(ans, cnt);
}

int32_t main()
{
	IOS;
	cin>>n;
	ans=INT_MAX;
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				cin>>a[i][j][k];
			}
		}
	}
	for(int i=1;i<=4;i++)
	{
		v.push_back(i);
	}
	do
	{
		workwhite();
		workblack();
	}while(next_permutation(v.begin(), v.end()));
	cout<<ans;
	return 0;
}