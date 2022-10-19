#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int t_case;
ll a,b,s,x,y;
inline ll calc(ll k){
	ll tmp=k+min((x-a*k)/b,(y-b*k)/a);
	s=max(s,tmp);
	return tmp;
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%lld%lld%lld%lld",&x,&y,&a,&b);
		s=0;
		ll ans=0,l=0,r=min(x/a,y/b);
		while(l<=r){
			ll mid=l+r>>1;
			if((x-a*mid)/double(b)>(y-b*mid)/double(a))ans=mid,l=mid+1;
			else r=mid-1;
		}
		if(ans>0)calc(ans-1);
		calc(ans);
		if(ans<min(x/a,y/b))calc(ans+1);
		swap(a,b),swap(x,y);
		ans=0,l=0,r=min(x/a,y/b);
		while(l<=r){
			ll mid=l+r>>1;
			if((x-a*mid)/double(b)>(y-b*mid)/double(a))ans=mid,l=mid+1;
			else r=mid-1;
		}
		if(ans>0)calc(ans-1);
		calc(ans);
		if(ans<min(x/a,y/b))calc(ans+1);
		printf("%lld\n",s);
	}
	return 0;
}