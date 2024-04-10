#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
typedef double db;
#define rdb register db
#define cdb const db 
const int N=3005;
int T,n,a[N],pre[N],lst[N];
ll f[N][N],ans;
int main(){ 
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);it i,j;
		for(i=1;i<=n;++i) scanf("%d",&a[i]),pre[i]=lst[i]=0;
		for(i=1;i<=n;++i) pre[i]=lst[a[i]],lst[a[i]]=i;
		for(i=1;i<=n;++i){
			for(j=1;j<i;++j) 
				f[i][j]=f[i][j-1]+(a[j]==a[i]);
			for(j=1;j<i;++j) f[i][j]+=f[i-1][j];
		}
		//f[i][j]:1~j=ai
		ans=0;
		for(it i=1;i<=n;++i)
			for(it j=pre[i];j;j=pre[j])
				if(i-1>=j+1) ans+=f[i-1][j-1]-f[j][j-1];
		printf("%lld\n",ans);
	}
	return 0;
}