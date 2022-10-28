#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1005;

int n, ct0=0, sti, stj;
int a[N][N], cache2[N][N], cache5[N][N];

int ct2(int k)
{
	int cur=0;
	while(k%2==0)
	{
		cur++;
		k/=2;
	}
	return cur;
}

int ct5(int k)
{
	int cur=0;
	while(k%5==0)
	{
		cur++;
		k/=5;
	}
	return cur;
}

int dp2(int i, int j)
{
	if(i==n+1||j==n+1)
		return 1e9;
	if(i==n&&j==n)
		return ct2(a[i][j]);
	int &ans=cache2[i][j];
	if(ans!=-1)
		return ans;
	ans=ct2(a[i][j]) + min(dp2(i+1, j), dp2(i, j+1));
	return ans;
}

int dp5(int i, int j)
{
	if(i==n+1||j==n+1)
		return 1e9;
	if(i==n&&j==n)
		return ct5(a[i][j]);
	int &ans=cache5[i][j];
	if(ans!=-1)
		return ans;
	ans=ct5(a[i][j]) + min(dp5(i+1, j), dp5(i, j+1));
	return ans;
}

void path2(int i, int j)
{
	if(i==n && j==n)
		return;
	int ans=dp2(i, j);
	if(ans==ct2(a[i][j])+dp2(i+1, j))
	{
		cout<<"D";
		return path2(i+1, j);
	}
	else
	{
		cout<<"R";
		return path2(i, j+1);
	}
}

void path5(int i, int j)
{
	if(i==n && j==n)
		return;
	int ans=dp5(i, j);
	if(ans==ct5(a[i][j])+dp5(i+1, j))
	{
		cout<<"D";
		return path5(i+1, j);
	}
	else
	{
		cout<<"R";
		return path5(i, j+1);
	}
}

int32_t main()
{
	IOS;
	memset(cache2, -1, sizeof(cache2));
	memset(cache5, -1, sizeof(cache5));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(!a[i][j])
			{
				sti=i, stj=j;
				ct0++;
				a[i][j]=10;
			}
		}
	}		
	int ans=min(dp2(1, 1), dp5(1, 1));
	if(ans>1 && ct0>0)
	{
		cout<<"1"<<endl;
		for(int i=2;i<=sti;i++)
			cout<<"D";
		for(int j=2;j<=stj;j++)
			cout<<"R";
		for(int i=sti+1;i<=n;i++)
			cout<<"D";
		for(int j=stj+1;j<=n;j++)
			cout<<"R";
	}
	else
	{
		cout<<ans<<endl;
		if(ans==dp2(1, 1))
			path2(1, 1);
		else
			path5(1, 1);
	}
}