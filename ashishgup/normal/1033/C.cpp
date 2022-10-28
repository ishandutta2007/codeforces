#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int a[N], pos[N];
int losing[N];
char ans[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pos[a[i]]=i;
	}
	ans[pos[n]]='B';
	losing[pos[n]]=1;
	for(int i=n-1;i>=1;i--)
	{
		int cur=pos[i];
		int left=(cur-1)/i;
		int right=(n-cur)/i;
		int check=0;
		for(int j=-1*left;j<=right;j++)
		{
			if(a[cur+i*j]<=i)
				continue;
			check|=losing[cur+i*j];
			if(check)
				break;
		}		
		if(!check)
			losing[cur]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(losing[i])
			cout<<"B";
		else
			cout<<"A";
	}
	return 0;
}