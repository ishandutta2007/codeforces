#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)201*1000)
#define INF ((ll)1e9+10)
#define MOD ((ll)1e9+7)
ll tavan(ll a,ll b,ll mod=MOD){ll res=1;while(b){res*=b%2?a:1;res%=mod;a*=a;a%=mod;b/=2;}return res;}

ll a,b,c,ans=INF;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>a>>b>>c;
	for(int i=-200;i<=200;i++)
		ans=min(ans,abs(a-i)+abs(b-i)+abs(c-i));
	cout<<ans;
	return 0;
}