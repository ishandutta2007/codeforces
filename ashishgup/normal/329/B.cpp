#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define fr(i,s,e) for(i=s;i<e;i++)
#define rf(i,s,e) for(i=s-1;i>=e;i--)
#define pb push_back
#define eb emblace_back
#define mp make_pair
#define ff first
#define ss second
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<vvvll> vvvvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<pair<long long,long long> > vpll;
typedef vector<vector<pair<ll,ll> > > vvpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;

#define PI 3.141592653589793
#define MOD 1000000007

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

ll r,c;
vvc v;
vvll level;
queue<pair<ll,ll> > q;
vvll vis;

void func(ll x,ll y,ll a,ll b)
{
	if(x<r&&x>=0&&y<c&&y>=0&&v[x][y]!='T')
	{
		if(vis[x][y])
			return;
		pll p3={x,y};
		q.push(p3);
		vis[x][y]=1;
		level[x][y]=level[a][b]+1;
	}
}
int main()
{
	IOS;
	cin>>r>>c;
	v=vvc(r,vc(c));
	level=vvll(r,vll(c,-1));
	vis=vvll(r,vll(c,0));
	pll p;
	ll sti,stj;
	for(ll i=0;i<r;i++)
	{
		for(ll j=0;j<c;j++)
		{
			cin>>v[i][j];	
			if(v[i][j]=='E')
			{
				p=mp(i,j);
			}
			if(v[i][j]=='S')
			{
				sti=i;
				stj=j;
			}
		}
	}
	q.push(p);
	level[p.ff][p.ss]=0;
	while(!q.empty())
	{
		pll p2=q.front();
		q.pop();
		ll x=p2.ff;
		ll y=p2.ss;
		if(v[x][y]=='T')
		{
			continue;
		}
		func(x+1,y,x,y);
		func(x,y+1,x,y);
		func(x-1,y,x,y);
		func(x,y-1,x,y);
	}
	ll ans=0;
	for(ll i=0;i<r;i++)
	{
		for(ll j=0;j<c;j++)
		{
			if(level[i][j]!=-1 && level[i][j]<=level[sti][stj])
			{
				if(v[i][j]!='S'&&v[i][j]!='E')
					ans+=(v[i][j]-'0');
			}
		}
	}
	cout<<ans;
	return 0;
}