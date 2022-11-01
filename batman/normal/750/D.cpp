#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)1000)
#define MOD ((ll)1e9+7)
#define INF ((ll)2e9+100)

ll n,t[N],ans;
bool a[N][N];
pair <ll,ll> b[8]={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
set <pair<pair<pair<ll,ll>,pair<ll,ll> >,pair<ll,ll> > > st;

pair <ll,ll> _do1(ll x,ll y)
{
	for(int i=0;i<8;i++)
		if(b[i].first==x && b[i].second==y)
			return b[(i+1)%8];
}

pair <ll,ll> _do2(ll x,ll y)
{
	for(int i=0;i<8;i++)
		if(b[i].first==x && b[i].second==y)
			return b[(i-1+8)%8];
}

void solve(ll posx,ll posy,ll id,ll move,ll x,ll y)
{
	if(st.count({{{posx,posy},{x,y}},{id,move}}))return ;
	st.insert({{{posx,posy},{x,y}},{id,move}});
	if(!a[posx][posy])a[posx][posy]=1,ans++;
	if(move==t[id])
	{
		if(id==n-1)return ;
		ll x2=x,y2=y;
		x=_do1(x2,y2).first;y=_do1(x2,y2).second;
		solve(posx+x,posy+y,id+1,1,x,y);
		x=_do2(x2,y2).first;y=_do2(x2,y2).second;
		solve(posx+x,posy+y,id+1,1,x,y);
		return ;
	}
	solve(posx+x,posy+y,id,move+1,x,y);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>t[i];
	solve(500,500,0,1,0,1);
	cout<<ans;
	return 0;
}