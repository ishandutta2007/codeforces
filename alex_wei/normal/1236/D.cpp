#pragma GCC optimize(3)

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pii pair <int,int>
#define pb push_back
#define all(v) v.begin(),v.end()
#define sor(v) sort(all(v))
#define rev(v) reverse(all(v))
#define mem(v,x) memset(v,x,sizeof(v))

const int N=1e5+5;
ll n,m,k;
vector <ll> rr[N],cc[N];

int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++){
		ll x,y;
		cin>>x>>y;
		rr[x].pb(y),cc[y].pb(x);
	}
	for(int i=1;i<=n;i++)rr[i].pb(0),rr[i].pb(m+1),sor(rr[i]);
	for(int i=1;i<=m;i++)cc[i].pb(0),cc[i].pb(n+1),sor(cc[i]);
	ll x=1,y=1,s=1,dir=0,u=1,d=n+1,l=0,r=m+1;
	if(*lower_bound(all(rr[1]),1)==2)dir=1;
	while(1){
		ll dx,dy;
		if(dir==0)dx=x,r=dy=min(r,*lower_bound(all(rr[x]),y))-1;
		if(dir==1)dy=y,d=dx=min(d,*lower_bound(all(cc[y]),x))-1;
		if(dir==2)dx=x,l=dy=max(l,*--lower_bound(all(rr[x]),y))+1;
		if(dir==3)dy=y,u=dx=max(u,*--lower_bound(all(cc[y]),x))+1;
		dir=(dir+1)%4,s+=abs(dx-x)+abs(dy-y);
		if(dx==x&&dy==y)break;
		x=dx,y=dy;
	}
	if(s<n*m-k)puts("No");
	else puts("Yes");
	
	return 0;
}