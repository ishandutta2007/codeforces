
 #include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m, l, r, ans=0;
int a[N], b[N];
int active[N];

int32_t main()
{
	IOS;
	cin>>n>>m>>l>>r;
	for(int i=1;i<=n;i++)
	{
		int x, y;
		cin>>x>>y;
		for(int j=x;j<=y;j++)
			active[j]=1;
	}
	for(int i=1;i<=m;i++)
		cin>>a[i]>>b[i];
	for(int i=l;i<=r;i++)
	{
		int check=0;
		for(int j=1;j<=m&&!check;j++)
		{
			for(int k=a[j];k<=b[j];k++)
			{
				check|=active[k+i];
				if(check)
					break;
			}
		}
		ans+=check;
	}
	cout<<ans;
	return 0;
}