#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		ri ans=0;
		for(ri i=2,l=a[1]-m,r=a[1]+m;i<=n;++i){
			ri L=a[i]-m,R=a[i]+m;
			if(max(l,L)>min(r,R))++ans,l=L,r=R;
			ckmax(l,L),ckmin(r,R);
		}
		printf("%d\n",ans);
	}
	return 0;
}