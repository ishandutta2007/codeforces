#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);
const ll N =1111;

ll n,m,xt,yt,xm,ym,dis[4][N][N];
string s[N];

bool check(ll turn,ll x,ll y,ll x2,ll y2)
{
	char c=s[x][y];
	for(int i=0;i<turn;i++)
	{
		if(s[x][y]=='-')s[x][y]='|';
		else if(s[x][y]=='|')s[x][y]='-';
		else if(s[x][y]=='^')s[x][y]='>';
		else if(s[x][y]=='>')s[x][y]='v';
		else if(s[x][y]=='v')s[x][y]='<';
		else if(s[x][y]=='<')s[x][y]='^';
		else if(s[x][y]=='L')s[x][y]='U';
		else if(s[x][y]=='U')s[x][y]='R';
		else if(s[x][y]=='R')s[x][y]='D';
		else if(s[x][y]=='D')s[x][y]='L';
	}
	
	if(x2==x+1)
	{
		if(s[x][y]=='+' ||
		s[x][y]=='|' ||
		s[x][y]=='v' ||
		s[x][y]=='L' ||
		s[x][y]=='R' ||
		s[x][y]=='U')
		{
			s[x][y]=c;
			return 1;
		}
		
	}
	if(x2==x-1)
	{
		if(s[x][y]=='+' ||
		s[x][y]=='|' ||
		s[x][y]=='^' ||
		s[x][y]=='L' ||
		s[x][y]=='R' ||
		s[x][y]=='D')
		{
			s[x][y]=c;
			return 1;
		}
	}
	if(y2==y-1)
	{
		if(s[x][y]=='+' ||
		s[x][y]=='-' ||
		s[x][y]=='<' ||
		s[x][y]=='U' ||
		s[x][y]=='R' ||
		s[x][y]=='D')
		{
			s[x][y]=c;
			return 1;
		}
	}
	if(y2==y+1)
	{
		if(s[x][y]=='+' ||
		s[x][y]=='-' ||
		s[x][y]=='>' ||
		s[x][y]=='U' ||
		s[x][y]=='L' ||
		s[x][y]=='D')
		{
			s[x][y]=c;
			return 1;
		}
	}
	s[x][y]=c;
	return 0;
}

int main() 
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>s[i];
	cin>>xt>>yt>>xm>>ym;
	xt--;yt--;xm--;ym--;
	for(int i=0;i<4;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<m;k++)
				dis[i][j][k]=INF;
	dis[0][xt][yt]=0;
	set <pair<pair<ll,ll>,pair<ll,ll> > > st;
	st.insert({{0,0},{xt,yt}});
	while(st.size())
	{
		ll d=st.begin()->first.first,x=st.begin()->second.first,y=st.begin()->second.second,turn=st.begin()->first.second;
		//cout<<d<<" "<<x<<" "<<y<<"\n";
		st.erase(st.begin());
		d++;
		if(dis[(turn+1)%4][x][y]>d)
		{
			st.erase({{dis[(turn+1)%4][x][y],(turn+1)%4},{x,y}});
			dis[(turn+1)%4][x][y]=d;
			st.insert({{dis[(turn+1)%4][x][y],(turn+1)%4},{x,y}});
		}
		
		if(x+1<n && dis[turn][x+1][y]>d && check(turn,x,y,x+1,y) && check(turn,x+1,y,x,y))
		{
			st.erase({{dis[turn][x+1][y],turn},{x+1,y}});
			dis[turn][x+1][y]=d;
			st.insert({{dis[turn][x+1][y],turn},{x+1,y}});
		}
		if(y+1<m && dis[turn][x][y+1]>d && check(turn,x,y,x,y+1) && check(turn,x,y+1,x,y))
		{
			st.erase({{dis[turn][x][y+1],turn},{x,y+1}});
			dis[turn][x][y+1]=d;
			st.insert({{dis[turn][x][y+1],turn},{x,y+1}});
		}
		if(x-1>=0 && dis[turn][x-1][y]>d && check(turn,x,y,x-1,y) && check(turn,x-1,y,x,y))
		{
			st.erase({{dis[turn][x-1][y],turn},{x-1,y}});
			dis[turn][x-1][y]=d;
			st.insert({{dis[turn][x-1][y],turn},{x-1,y}});
		}
		if(y-1>=0 && dis[turn][x][y-1]>d && check(turn,x,y,x,y-1) && check(turn,x,y-1,x,y))
		{
			st.erase({{dis[turn][x][y-1],turn},{x,y-1}});
			dis[turn][x][y-1]=d;
			st.insert({{dis[turn][x][y-1],turn},{x,y-1}});
		}
	}
	ll ans=min(min(dis[0][xm][ym],dis[1][xm][ym]),min(dis[2][xm][ym],dis[3][xm][ym]));
	if(ans>=INF)cout<<-1;
	else cout<<ans;
	return 0;
}