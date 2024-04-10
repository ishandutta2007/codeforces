#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=6e5+10;
#define lowbit(k) ((k)&(-k))
template<typename T>
struct BIT{
	T c[maxn];
	int mx_idx;
	inline void clear(){memset(c,0,sizeof(T)*(mx_idx+1));}
	inline void add(int k,T v){
		for(;k<=mx_idx;k+=lowbit(k))c[k]+=v;
	}
	inline T query(int k){
		ri ret=0;
		for(;k;k^=lowbit(k))ret+=c[k];
		return ret;
	}
	inline T query(int l,int r){
		return query(r)-query(l-1);
	}
};
BIT<int>c;
int a[maxn],b[maxn],cnt,l,r,n,t_case;
ll ans;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%d",&n,&l,&r);
		cnt=0;
		for(ri i=1;i<=n;++i){
			scanf("%d",a+i);
			b[++cnt]=a[i];
			b[++cnt]=l-a[i];
			b[++cnt]=r-a[i];
		}
		sort(b+1,b+cnt+1);
		cnt=unique(b+1,b+cnt+1)-b-1;
		c.mx_idx=cnt;
		c.clear();
		ans=0;
		for(ri i=1;i<=n;++i){
			ri tmp1=lower_bound(b+1,b+cnt+1,l-a[i])-b,tmp2=lower_bound(b+1,b+cnt+1,r-a[i])-b;
			ans+=c.query(tmp1,tmp2);
			c.add(lower_bound(b+1,b+cnt+1,a[i])-b,1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}