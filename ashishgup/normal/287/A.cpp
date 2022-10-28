#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n=4;
char a[10][10];
int dx[4]={0, 0, +1, +1};
int dy[4]={0, +1, 0, +1};

int32_t main()
{
	IOS;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	bool check=0;
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=n-1;j++)
		{
			map<char, int> m;
			for(int k=0;k<4;k++)
				m[a[i+dx[k]][j+dy[k]]]++;
			for(auto &it:m)
				check|=(it.second>=3);
		}
	}
	if(check)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}