#include<cstdio>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int l,r,mid,n,m,k,f[200039],ans,tot,pus,a[200039];
inline void read(int &x){
	char s=getchar();x=0;
	while(s<'0'||s>'9') s=getchar();
	while(s>='0'&&s<='9') x=(x<<3)+(x<<1)+(s^48),s=getchar();
}
int main(){
	register int i;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++) read(a[i]);
	l=0;r=(1e9)+m+1;
	while(l+1<r){
		mid=(l+r)>>1;
		ans=0;
		memset(f,0,sizeof(f));
		for(i=1;i<=n;i++){
			f[i]+=f[i-1];
			ans+=max(mid-f[i]-a[i],0);
			f[i+k]-=max(mid-f[i]-a[i],0);
			f[i]+=max(mid-f[i]-a[i],0);
			if(ans>m) break;
		}
		if(ans>m) r=mid;
		else l=mid;
	}
	printf("%d\n",l);
}