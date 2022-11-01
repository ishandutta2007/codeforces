#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)301*1000)
#define MOD ((ll)1e9+7)
ll tavan(ll x,ll y){ll res=1;while(y){res*=y%2?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}

ll n,a[N],fen[2][N];

void update(ll x,ll num,bool id){for(;x<N;x+=x&-x)fen[id][x]+=num,fen[id][x]%=MOD;}
ll ask(ll x,bool id){ll res=0;for(;x>0;x-=x&-x)res+=fen[id][x];return res%MOD;}
ll query(ll l,ll r,bool id){return (ask(r,id)-ask(l-1,id)+MOD)%MOD;}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ll ex=tavan(2,a[i]),ex2=tavan(2,n-a[i]+1);
		update(a[i],ex,0);
		update(a[i],ex2,1);
		ll x=min(n-a[i],a[i]-1);
		if((query(a[i],a[i]+x,0)*tavan(ex,MOD-2))%MOD!=(query(a[i]-x,a[i],1)*tavan(ex2,MOD-2))%MOD)return cout<<"YES\n",0;
	}
	cout<<"NO\n";
	return 0;
}