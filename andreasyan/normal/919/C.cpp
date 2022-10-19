#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N=2002;

int yans=0;
int n,m,k;
int a[N][N];
int p[N][N];
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i)
	{
		string s;
		cin>>s;
		for(int j=1;j<=m;++j)
		{
			char ch=s[j-1];
			if(ch=='*')
				a[i][j]=1;
			else
				++yans;
		}
	}
	if(k==1)
	{
		cout<<yans<<endl;
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			p[i][j]=p[i][j-1]+a[i][j];
			if(j-k>=0)
			{
				if(p[i][j]-p[i][j-k]==0)
					++ans;
			}
		}
	}
	for(int j=1;j<=m;++j)
	{
		for(int i=1;i<=n;++i)
		{
			p[i][j]=p[i-1][j]+a[i][j];
			if(i-k>=0)
			{
				if(p[i][j]-p[i-k][j]==0)
					++ans;
			}
		}
	}
	cout<<ans<<endl;
//	system("pause");
	return 0;
}