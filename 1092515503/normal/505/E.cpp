#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,p,h[100100],a[100100];
struct dat{
	ll tim,tot;
	int id;
	dat(ll A,ll B,int C){tim=A,tot=B,id=C;}
	friend bool operator<(const dat&u,const dat&v){return u.tim>v.tim;}
};
priority_queue<dat>q;
bool che(ll ip){
	while(!q.empty())q.pop();
	for(int i=1;i<=n;i++)if(ip-1ll*m*a[i]<h[i])q.push(dat(ip/a[i],ip,i));
	for(int i=1;i<=m;i++){
		if(!q.empty()&&q.top().tim<i)return false;
		for(int j=1;j<=k;j++)if(!q.empty()){
			dat x=q.top();q.pop();
			x.tot+=p,x.tim=x.tot/a[x.id];
			if(x.tot-1ll*m*a[x.id]<h[x.id])q.push(x);
		}
	}
	return q.empty();
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&p);
	for(int i=1;i<=n;i++)scanf("%d%d",&h[i],&a[i]);
	ll l=1,r=1e14;
	while(l<r){
		ll mid=(l+r)>>1;
		if(che(mid))r=mid;
		else l=mid+1;
	}
	printf("%lld\n",r);
	return 0;
}