#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
inline int ask(int x){
	printf("? %d\n",x);
	fflush(stdout);
	ri ret;
	scanf("%d",&ret);
	return ret;
}
int main(){
	scanf("%d",&n);
	ri l=1,len=0,r=5e6;
	while(l<=r){
		ri mid=l+r>>1;
		if(ask(mid)==1)len=mid,r=mid-1;
		else l=mid+1;
	}
	int ans=len;
	for(ri i=1;i<=n;++i){
		ri tmp=ask(len/i);
		if(tmp)ans=min(ans,(len/i)*tmp);
	}
	printf("! %d",ans);
	fflush(stdout);
	return 0;
}