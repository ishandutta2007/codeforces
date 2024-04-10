#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define N ((ll)310)
#define INF ((ll)1e9+10)
#define MOD ((ll)1e9+7)
ll tavan(ll a,ll b,ll mod=MOD){ll res=1;while(b){res*=b%2?a:1;res%=mod;a*=a;a%=mod;b/=2;}return res;}

ll n,a[N],num[N],m,dp[N][N];
bool mark[N];
map <ll,ll> id,l;
vector <ll> light;


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	set <ll> s,s2;
	for(int i=0;i<n;i++)
	{
		ll ex;
		cin>>a[i]>>ex;
		s.insert(a[i]);s.insert(a[i]-ex);s.insert(a[i]+ex);
		s2.insert(a[i]);l[a[i]]=ex;
	}
	light.push_back(-1);
	for(auto x:s)
	{
		if(s2.count(x))mark[m]=1,light.push_back(m);
		num[m]=x;
		id[x]=m++;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
		{
			dp[i][j]=dp[i][j-1];
			if(j<=light[i])dp[i][j]=dp[i-1][min(id[num[light[i]]-l[num[light[i]]]],j)]+max(0,num[j]-(num[light[i]]-l[num[light[i]]]));	
			for(int k=i,mini=light[i];j>light[i] && k>0;k--)
			{
				ll ex=min(num[j],num[light[k]]+l[num[light[k]]])-num[light[k]];
				mini=min(mini,id[num[light[k]]]);
				dp[i][j]=max(dp[i][j],ex+dp[k-1][mini]+num[light[k]]-num[mini]);
				mini=min(mini,id[num[light[k]]-l[num[light[k]]]]);
			}
			//cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
		}
	cout<<dp[n][m-1]<<"\n";
	return 0;
}