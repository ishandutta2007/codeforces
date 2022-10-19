#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,x,y,z,t,a[139],d,maxn;
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&d);maxn=0;
		for(i=1;i<=n;i++) scanf("%d",&a[i]),maxn=max(maxn,a[i]);
		sort(a+1,a+n+1);
		if(a[1]+a[2]<=d||maxn<=d) printf("YES\n");
		else printf("NO\n");
	}
}