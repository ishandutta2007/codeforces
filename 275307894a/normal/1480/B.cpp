#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,z,t;
long long a,b,now,flag;
struct yyy{long long x,y;}s[100039];
inline bool cmp(yyy x,yyy y){return x.y<y.y;}
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld%d",&b,&a,&n);flag=0;
		for(i=1;i<=n;i++) scanf("%lld",&s[i].y);
		for(i=1;i<=n;i++) scanf("%lld",&s[i].x);
		sort(s+1,s+n+1,cmp);
		for(i=1;i<=n;i++){
			now=(s[i].x+b-1)/b;
			a-=s[i].y*(now-1);
			if(a<=0){flag=1;break;}
			a-=s[i].y;
		}
		if(flag) printf("NO\n");
		else printf("YES\n");
	}
}