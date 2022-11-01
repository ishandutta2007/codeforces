#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (301*1000)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

string s;
ll m,cnt[3][N];


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s>>m;
	if(s[0]=='x')cnt[0][0]=1;
	if(s[0]=='y')cnt[1][0]=1;
	if(s[0]=='z')cnt[2][0]=1;
	for(int i=1;i<s.size();i++)
	{
		for(int j=0;j<3;j++)
			cnt[j][i]=cnt[j][i-1];
		if(s[i]=='x')cnt[0][i]++;
		if(s[i]=='y')cnt[1][i]++;
		if(s[i]=='z')cnt[2][i]++;	
	}
	while(m--)
	{
		ll l,r;
		cin>>l>>r;
		r--;l--;
		if(l>=r-1){cout<<"YES\n";continue;}
		ll x=cnt[0][r]-((l)?cnt[0][l-1]:0ll),y=cnt[1][r]-((l)?cnt[1][l-1]:0ll),z=cnt[2][r]-((l)?cnt[2][l-1]:0ll);
		if(min(x,min(y,z))+1>=max(x,max(y,z)))cout<<"YES\n";
		else cout<<"NO\n";
	}
    return 0;
}