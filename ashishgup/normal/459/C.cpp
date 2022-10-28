#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1005;

int n, k, d;
int ans[N][N];

void work(int num)
{
	int store=num;
	int len=d;
	for(int i=len;i>=1;i--)
	{
		ans[store][i]=num%k;
		num/=k;
	}
}

int32_t main()
{
	IOS;
	cin>>n>>k>>d;
	if(k>=n)
	{
		for(int i=1;i<=d;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cout<<j<<" ";
			}
			cout<<endl;
		}
		return 0;
	}
	bool check=false;
	int cur=1;
	for(int i=1;i<=d;i++)
	{
		cur*=k;
		if(cur>=n)
		{
			check=true;
			break;
		}
	}
	if(!check)
	{
		cout<<"-1";
		return 0;
	}
	for(int i=0;i<n;i++)
		work(i);
	for(int i=d;i>=1;i--)
	{
		for(int j=0;j<n;j++)
		{
			cout<<ans[j][i]+1<<" ";
		}
		cout<<endl;
	}
	return 0;
}