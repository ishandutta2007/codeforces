#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
typedef pair<ll,int> pli;
#define fi first
#define se second
pli a[maxn];
int m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		for(ri i=1;i<=n;++i){
			a[i]={0,i};
			for(ri j=1,x;j<=m;++j){
				scanf("%d",&x);
				a[i].fi+=1ll*j*x;
			}
		}
		sort(a+1,a+n+1);
		printf("%d %lld\n",a[n].se,a[n].fi-a[n-1].fi);
	}
	return 0;
}