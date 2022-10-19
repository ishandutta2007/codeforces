#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,x,y,z,a[500039],f[500039],l,r,now,ans;
int main(){
	register int i;
	f[0]=1;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	l=1;
	for(i=1;i<=n;i++){
		if(i>=m) ans+=f[i-m];
		while(a[i]-a[l]>k) ans-=f[l-1],l++;
		f[i]=ans>0?1:0;
		//printf("%d %d %d\n",f[i],ans,l);
	}
	if(f[n]) printf("YES\n");
	else printf("NO\n");
}