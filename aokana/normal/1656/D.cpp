#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
ll n;
int t_case;
inline bool check(ll k){return k>1&&k<=INT_MAX&&n>=k*(k+1)/2;}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%lld",&n);
		if(n&1)puts("2");
		else{
			ll x=n,y=2;
			while(!(x&1))x>>=1,y<<=1;
			if(check(y))printf("%lld\n",y);
			else if(check(x))printf("%lld\n",x);
			else puts("-1");
		}
	}
//	for(n=1;n<=50;++n){
//		printf("%d: ",n);
//		for(ri k=n;k>1;--k)
//			if(n>=k*(k+1)/2&&(n-k*(k-1)/2)%k==0){
//				printf("%d\n",k);
//				goto skip;
//			}
//		puts("-1");
//		skip:;
//	}
	return 0;
}