#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)101*1000)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)
ll tavan(ll a,ll b,ll mod=MOD){ll res=1;while(b){res*=b%2?a:1;res%=mod;a*=a;a%=mod;b/=2;}return res;}

ll n,m,num[2][N],ans[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){ll x;cin>>x;num[0][x]++;}
	for(int i=0;i<n;i++){ll x;cin>>x;num[1][x]++;}
	stack <ll> s;
	for(int i=0,j=m-1;i<m;i++,j--)
	{
		while(num[0][i])s.push(i),num[0][i]--;
		while(num[1][j] && s.size())ans[s.top()+j]++,s.pop(),num[1][j]--;
	}
	while(s.size())num[0][s.top()]++,s.pop();
	for(int i=m-1,j=m-1;i>=0 && j>=0;)
	{
		if(!num[0][i]){i--;continue;}
		if(!num[1][j]){j--;continue;}
		ans[(i+j)%m]++;
		num[0][i]--;
		num[1][j]--;
	}
	for(int i=m-1;i>=0;i--)
		for(int j=0;j<ans[i];j++)
			cout<<i<<" ";
	return 0;
}