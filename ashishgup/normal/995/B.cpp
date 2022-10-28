#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=205;

int n, ans=0;
int a[N], vis[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=2*n;i++)
		cin>>a[i];
	n*=2;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]==a[j])
			{
				for(int k=j-1;k>=i+1;k--)
				{
					ans++;
					swap(a[k], a[k+1]);
				}
			}
		}
	}
	cout<<ans;
	return 0;
}