#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll 
typedef unsigned long long ull; 
	template <class I> 
	il I A(I x){return x<0?-x:x;} 
const int N=1000005;
int n,T,a[N];
ll pw[N];
il ull ksm(it x,it L){
	ull ans=1;
	while(L) L&1?ans=ans*x:0,x=x*x,L>>=1;
	return ans;
}
int main(){ 
	scanf("%d",&n);it i;
	for(i=1;i<=n;++i) scanf("%d",&a[i]);
	std::sort(a+1,a+1+n);
	ull lst=9e18,ans,inf=9e18;
	for(it c=1;ksm(c,n-1)<inf;++c){
		for(i=pw[0]=1,ans=0;i<=n;++i){
			pw[i]=pw[i-1]*c,ans+=A(pw[i-1]-a[i]);
			if(ans>inf) break;
		}
		//if(ans>lst) break;
		if(ans<lst) lst=ans;
	}
	printf("%llu",lst);
	return 0;
}