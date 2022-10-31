#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (201*1000)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

ll n,k,a,b,q,fen[2][N],in[N];


ll query1(ll x){ll num=0;for(;x>0;x-=x&(-x))num+=fen[0][x];return num;}
ll query2(ll x){ll num=0;for(;x>0;x-=x&(-x))num+=fen[1][x];return num;}
void add1(ll x,ll y){for(;x<=n;x+=x&(-x))fen[0][x]+=y;}
void add2(ll x,ll y){for(;x<=n;x+=x&(-x))fen[1][x]+=y;}

int main()
{ 
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k>>a>>b>>q;
	while(q--)
	{
		ll t;
		cin>>t;
		if(t==1)
		{
			ll x,y;
			cin>>x>>y;
			if(in[x]<b)add1(x,min(b-in[x],y));
			if(in[x]<a)add2(x,min(a-in[x],y));
			in[x]+=y;
			continue;
		}
		ll x;
		cin>>x;
		cout<<query1(x-1)+query2(n)-query2(x+k-1)<<"\n";
	}
    return 0;
}