#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
#define fi   first
#define se   second
using namespace std;
int T,n,m,ans[200005];
ll a[200005];
pair<pair<ll,ll>,int> P[200005];
pair<ll,ll> p[200005];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		m*=2;
		for(int i=1;i<=n;++i)scanf("%I64d%I64d",&P[i].fi.fi,&P[i].fi.se),P[i].fi.fi*=2,P[i].fi.se*=2,P[i].se=i;
		sort(P+1,P+n+1);
		for(int i=1;i<=n;++i)p[i]=P[i].fi;
		priority_queue<ll> q;
		int cnt=0;
		ll sum=0;
		for(int i=1;i<=n;++i){
			q.push(-p[i].fi-p[i].se);
			sum+=p[i].fi+p[i].se,++cnt;
			while(cnt&&q.top()+p[i].fi>0)sum+=q.top(),--cnt,q.pop();
			a[i]=sum-cnt*1ll*p[i].fi;
		}
		while(cnt--)q.pop();
		cnt=0;
		sum=0;
		for(int i=n;i;--i){
			while(cnt&&q.top()-p[i].fi>0)sum+=q.top(),--cnt,q.pop();
			a[i]+=sum+cnt*1ll*p[i].fi;
			q.push(p[i].fi-p[i].se);
			sum+=p[i].se-p[i].fi,++cnt;
		}
		bool ok=0;
		ll x,y;
		for(int i=1;i<=n;++i){
			if(a[i]<=m) continue;
			if(!ok){
				ok=1;
				x=p[i].fi;
				y=a[i]-m;
			}
			else{
				ll _x=p[i].fi,_y=a[i]-m;
				if(_x<x)swap(x,_x),swap(y,_y);
				if(_y>=y+_x-x)x=_x,y=_y;
				else if(y<_y+_x-x){
					ll nx=(x-y+_x+_y);
					ll ny=(y-x+_x+_y);
					x=nx/2,y=ny/2;
				}
			}
		}
		if(!ok){
			for(int i=1;i<=n;++i)printf("1");
			printf("\n");
			continue;
		}
		for(int i=1;i<=n;++i){
			if(p[i].fi>=x){
				if(p[i].se>=p[i].fi-x+y)ans[P[i].se]=1;
				else ans[P[i].se]=0;
			}
			else{
				if(p[i].se>=x-p[i].fi+y)ans[P[i].se]=1;
				else ans[P[i].se]=0;
			}
		}
		for(int i=1;i<=n;++i)printf("%d",ans[i]);
		printf("\n");
	}
    return 0;
}