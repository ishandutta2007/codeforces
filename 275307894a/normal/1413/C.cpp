#include<cstdio>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,maxn,minn=2e9,f[7][100039],a[7],head,b[100039],ans=2e9,gh,h[100039];
struct yyy{int x,num;}g[600039],tmp;
inline bool cmp(yyy x,yyy y){return x.x<y.x;}
int main(){
	register int i,j;
	for(i=1;i<=6;i++) scanf("%d",&a[i]);
	sort(a+1,a+7);
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&b[i]);
	sort(b+1,b+n+1);
	for(i=1;i<=n;i++){
		for(j=1;j<=6;j++) f[7-j][i]=b[i]-a[j],g[++head]=(yyy){b[i]-a[j],i};
	}
	sort(g+1,g+head+1,cmp);
	for(i=1;i<=n;i++) maxn=max(maxn,f[1][i]),h[i]=1;
	for(i=1;i<=head;i++){
		tmp=g[i];
		h[tmp.num]++;
		if(h[tmp.num]<=6){
			ans=min(ans,maxn-min(tmp.x,minn));
			maxn=max(maxn,f[h[tmp.num]][tmp.num]);
		}
		else {ans=min(ans,maxn-tmp.x);break;}
	}
	printf("%d\n",ans);
}