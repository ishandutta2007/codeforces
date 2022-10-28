#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;
const int MOD=1e9+7;

int a[10][5];

int dist(int i, int j)
{	
	int x=a[i][1]-a[j][1];
	int y=a[i][2]-a[j][2];
	int z=a[i][3]-a[j][3];
	x*=x;
	y*=y;
	z*=z;
	return (x+y+z);
}

bool check()
{
	map<int, int> m;
	for(int i=1;i<=8;i++)
	{
		for(int j=i+1;j<=8;j++)
		{
			m[dist(i, j)]++;
		}
	}
	int len=m.begin()->first;
	if(m[len]==12&&m[len*2]==12&&m[len*3]==4)
	{
		return 1;
	}
	return 0;
}

void dfs(int k)
{
	if(k>8)
	{
		if(check())
		{
			cout<<"YES"<<endl;
			for(int i=1;i<=8;i++)
			{
				for(int j=1;j<=3;j++)
				{
					cout<<a[i][j]<<" ";
				}
				cout<<endl;
			}
			exit(0);
		}
		return;
	}
	dfs(k+1);
	swap(a[k][2], a[k][3]);
	dfs(k+1);
	swap(a[k][1], a[k][3]);
	dfs(k+1);
	swap(a[k][2], a[k][3]);
	dfs(k+1);
	swap(a[k][1], a[k][3]);
	dfs(k+1);
	swap(a[k][2], a[k][3]);
	dfs(k+1);
}

int32_t main()
{
    IOS;
	for(int i=1;i<=8;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
		}
	}
	dfs(2);
	cout<<"NO";
    return 0;
}