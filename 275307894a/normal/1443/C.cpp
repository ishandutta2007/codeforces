#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,t;
long long tot,pus,ans;
struct yyy{int x,y;}s[1000039];
inline bool cmp(yyy x,yyy y){return x.x>y.x;}
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		tot=0;ans=1e18;
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&s[i].x);
		for(i=1;i<=n;i++) scanf("%d",&s[i].y);
		sort(s+1,s+n+1,cmp);s[n+1].x=0;
		for(i=0;i<=n;i++){
			tot+=s[i].y;
			ans=min(ans,max(tot,s[i+1].x));
		}
		printf("%lld\n",ans);
	}
}