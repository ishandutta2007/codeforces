#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=1e6+10;
vector<int>pri;
bool vis[maxn];
inline void sieve(int siz){
	pri.clear();
	for(ri i=2;i<=siz;++i){
		if(!vis[i])pri.push_back(i);
		for(ri j:pri){
			if(i*j>siz)break;
			vis[i*j]=true;
			if(i%j==0)break;
		}
	}
}
int a[maxn],l[maxn],m,n,r[maxn],t_case;
int main(){
	sieve(1000000);
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		for(ri i=1;i<=n;++i)scanf("%d",a+i),l[i]=r[i]=0;
		ll ans=0;
		for(ri i=1;i<=n;++i)
			if(!vis[a[i]]){
				if(i>m&&a[i-m]==1)l[i]=l[i-m]+1;
				else l[i]=1;
			}
		for(ri i=n;i;--i)
			if(!vis[a[i]]){
				if(i+m<=n&&a[i+m]==1)r[i]=r[i+m]+1;
				else r[i]=1;
			}
		for(ri i=1;i<=n;++i)
			if(a[i]>1&&l[i]&&r[i])
				ans+=1ll*l[i]*r[i]-1;
		printf("%lld\n",ans);
	}
	return 0;
}