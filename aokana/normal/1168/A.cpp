#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=3e5+10;
int a[maxn],b[maxn],m,n,t_case;
inline bool check(int k){
	memcpy(b,a,n+1<<2);
	for(ri i=1;i<=n;++i){
		ri mx=min(b[i]+k,m);
		if(mx<b[i-1])return false;
		if(b[i]<=b[i-1]||b[i]+k>=b[i-1]+m)b[i]=b[i-1];
	}
	return true;
}
int main(){
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	ri ans=-1,l=0,r=1e6;
	while(l<=r){
		ri mid=l+r>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d",ans);
	return 0;
}