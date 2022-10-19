#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int inf=1e9+7;
ll ans;
const int N=505;
int t,n;
int a[N][N];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		ans=0;
		for (int i=1;i<=n*2;++i)
			for (int j=1;j<=n*2;++j)
				scanf("%d",&a[i][j]);
		int mn=min({a[n+1][1],a[n+1][n],a[2*n][1],a[2*n][n],a[1][n+1],a[1][n*2],a[n][n+1],a[n][n*2]});
		for (int i=n+1;i<=n*2;++i)
			for (int j=n+1;j<=n*2;++j)
				ans+=a[i][j];
		ans+=mn;
		cout<<ans<<endl;
	}
	return 0;
}