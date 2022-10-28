#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int a[10][10], r[10], c[10];

void reduce()
{
	memset(r, 0, sizeof(r));
	memset(c, 0, sizeof(c));
	for(int i=1;i<=4;i++)
	{
		int cur=1;
		for(int j=1;j<=4;j++)
			cur&=a[i][j];
		if(cur==1)
			r[i]=1;
	}
	for(int j=1;j<=4;j++)
	{
		int cur=1;
		for(int i=1;i<=4;i++)
			cur&=a[i][j];
		if(cur==1)
			c[j]=1;
	}
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
			if(r[i]||c[j])
				a[i][j]=0;
}

pair<int, int> get(char ch)
{
	if(ch=='0')
	{
		for(int i=1;i<=1;i++)
		{
			for(int j=1;j<=4;j++)
			{
				if(a[i][j]==0 && a[i+1][j]==0)
				{
					a[i][j]=1;
					a[i+1][j]=1;
					return {i, j};
				}
			}
		}
	}
	else
	{
		for(int i=4;i<=4;i++)
		{
			for(int j=1;j<=3;j++)
			{
				if(a[i][j]==0 && a[i][j+1]==0)
				{
					a[i][j]=1;
					a[i][j+1]=1;
					return {i, j};
				}
			}
		}
	}
}

int32_t main()
{
	IOS;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		pair<int, int> p = get(s[i]);
		cout<<p.first<<" "<<p.second<<endl;
		reduce();
	}
	return 0;
}