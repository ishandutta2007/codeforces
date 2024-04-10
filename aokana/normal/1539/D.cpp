#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
struct node{
	ll a,b;
	inline bool operator<(const node &k)const{
		return b<k.b;
	}
}g[maxn];
int m,n,t_case;
ll ans,cnt,sum;
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%lld%lld",&g[i].a,&g[i].b),sum+=g[i].a*2;
	sort(g+1,g+n+1);
	for(ri l=1,r=n;;){
		if(l==r){
			sum-=max(g[l].a-max(g[l].b-cnt,0ll),0ll);
			break;
		}
		if(cnt>=g[l].b){
			cnt+=g[l].a;
			sum-=g[l].a;
			++l;
			continue;
		}
		if(cnt+g[r].a>g[l].b){
			sum-=g[l].a-(g[l].b-cnt);
			cnt=g[l].a+g[l].b;
			++l;
			continue;
		}
		cnt+=g[r].a;
		--r;
	}
	printf("%lld",sum);
	return 0;
}
// i->r j->l