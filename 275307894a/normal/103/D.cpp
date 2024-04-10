#include<cstdio>
#include<cmath>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
long long n,m,k,x,y,a[300039],f[300039],ans[300039],tot;
struct yyy{int x,y,num;}s[300039];
inline bool cmp(yyy x,yyy y){return x.y<y.y;}
int main(){
    register int i,j;
    scanf("%lld",&n);
    k=sqrt(n);
    for(i=1;i<=n;i++) scanf("%lld",&a[i]);
    scanf("%lld",&m);
    for(i=1;i<=m;i++)scanf("%lld%lld",&s[i].x,&s[i].y),s[i].num=i;
    sort(s+1,s+m+1,cmp);
    for(i=1;i<=m;i++){
    	if(s[i].y>k){
    		tot=0;
    		for(j=s[i].x;j<=n;j+=s[i].y) tot+=a[j];
    		ans[s[i].num]=tot;
		}
		else{
			for(j=n;j>n-s[i].y;j--) f[j]=a[j];
			for(j=n-s[i].y;j>=1;j--) f[j]=f[j+s[i].y]+a[j];
			for(j=i;s[j].y==s[j+1].y;j++) ans[s[j].num]=f[s[j].x];
			ans[s[j].num]=f[s[j].x];i=j;
		}
	}
	for(i=1;i<=m;i++) printf("%lld\n",ans[i]);
}///hanzhongtlxakioiorz