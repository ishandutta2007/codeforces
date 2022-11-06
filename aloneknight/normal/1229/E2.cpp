#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
const int P=1e9+7;
ll n,b[1<<10],p[10],a[10];vector<ll>v[10];
unordered_map<ll,ll>f[10];
int main()
{
	scanf("%lld",&n);
	for(int i=0;i<(1<<n);i++){int s=__builtin_popcount(i);b[i]=v[s].size();v[s].pb(i);}
	f[0][1]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++){scanf("%lld",&p[j]);p[j]=p[j]*570000004%P;}
		for(auto t:f[i])
		{
			for(int j=0;j<n;j++)a[j]=0;
			for(auto m:v[i])if(t.X>>b[m]&1)for(int j=0;j<n;j++)if(~m>>j&1)a[j]|=1ll<<b[m|(1<<j)];
			for(int m=0;m<(1<<n);m++)
			{
				ll X=1,M=0;
				for(int j=0;j<n;j++)if(m>>j&1)M|=a[j],X=X*p[j]%P;else X=X*(P+1-p[j])%P;
				f[i+1][M]=(f[i+1][M]+t.Y*X)%P;
			}
		}
	}
	printf("%lld\n",f[n][1]);
	return 0;
}