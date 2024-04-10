#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 200000
#define M 50000
#define mod 1000000000
#define mod2 39989
#define eps (1e-7)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define R(x) (rand()*rand()%x+1)
using namespace std;
int T,n,A[N+5],st[N+5],sh,l1[N+5],r1[N+5],l2[N+5],r2[N+5],Minn[N+5],now;ll ans;
int main(){
//	freopen("1.in","r",stdin);
	re int i;scanf("%d",&T);while(T--){
		scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]),Minn[i]=1e9;ans=0;
		for(i=1;i<=n;i++) l1[i]=l2[i]=0,r1[i]=r2[i]=n+1;
		for(i=1;i<=n;i++){
			while(sh&&A[st[sh]]>A[i])sh--;l1[i]=st[sh];st[++sh]=i; 
		}sh=0;
		for(i=1;i<=n;i++){
			while(sh&&A[st[sh]]>=A[i])r1[st[sh]]=i,sh--;st[++sh]=i; 
		}sh=0;
		for(i=1;i<=n;i++){
			while(sh&&A[st[sh]]<A[i])sh--;l2[i]=st[sh];st[++sh]=i; 
		}sh=0;
		for(i=1;i<=n;i++){
			while(sh&&A[st[sh]]<=A[i])r2[st[sh]]=i,sh--;st[++sh]=i; 
		}sh=0;
		for(i=1;i<=n;i++)Minn[l1[i]]=min(Minn[l1[i]],r2[i]),Minn[l2[i]]=min(Minn[l2[i]],r1[i]);now=n+1;
		for(i=n;i;i--)now=min(now,Minn[i]),ans+=now-i;
		printf("%lld\n",ans);
	}
}