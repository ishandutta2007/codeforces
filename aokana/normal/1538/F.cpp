#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int l,r,t_case;
inline ll solve(int k){
	ll ret=0;
	for(ri i=10;;i*=10){
		if(k%i==i-1)++ret;
		if(k<i)break;
		ret+=k/i;
	}
	return ret;
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&l,&r);
		printf("%lld\n",solve(r-1)-solve(l-1)+r-l);
	}
	return 0;
}