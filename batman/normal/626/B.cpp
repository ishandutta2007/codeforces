#include<bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define MOD ((ll)1e9+7)
#define INF ((ll)1e9)
#define N (202)

ll n,num[3];
string s;
ll ans[N][N][N];

ll solve(ll a,ll b,ll c)
{
	if(ans[a][b][c])return ans[a][b][c];
	if(!c && !b)ans[a][b][c]=1;
	if(!a && !c)ans[a][b][c]=2;
	if(!b && !a)ans[a][b][c]=4;
	if(ans[a][b][c])return ans[a][b][c];
	ll res=0;
	if(a>1)res=res|solve(a-1,b,c);
	if(b>1)res=res|solve(a,b-1,c);
	if(c>1)res=res|solve(a,b,c-1);
	if(a && b)res=res|solve(a-1,b-1,c+1);
	if(c && b)res=res|solve(a+1,b-1,c-1);
	if(a && c)res=res|solve(a-1,b+1,c-1);
	ans[a][b][c]=res;
	return res;
}


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='R')num[0]++;
		if(s[i]=='G')num[1]++;
		if(s[i]=='B')num[2]++;
	}
	ll p=solve(num[0],num[1],num[2]);
	if(ans[num[0]][num[1]][num[2]]&4)cout<<'B';
	if(ans[num[0]][num[1]][num[2]]&2)cout<<'G';
	if(ans[num[0]][num[1]][num[2]]&1)cout<<'R';

	
	
	return 0;
}