#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1005;

int n, s;
int a[N], b[N], vis[N];

void yes()
{
	cout<<"YES";
	exit(0);
}

void no()
{
	cout<<"NO";
	exit(0);
}

int32_t main()
{
	IOS;
	cin>>n>>s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	if(!a[1])
		no();
	for(int i=1;i<=n;i++)
		if(a[i])
			vis[i]=1;
	for(int i=n;i>=1;i--)
	{
		if(a[i]==b[i] && a[i]==1)
		{
			for(int j=i-1;j>=1;j--)
			{
				if(b[j])
					vis[j]=1;
			}
			break;
		}
	}
	if(vis[s])
		yes();
	else
		no();
	return 0;
}