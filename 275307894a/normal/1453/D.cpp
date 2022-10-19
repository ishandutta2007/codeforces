#include<cstdio>
using namespace std;
int n,m,x,y,z,t,st[2039],sh;
long long k;
int main() {
	register int i,j;
	scanf("%d",&t);
	while(t--) {
		scanf("%lld",&k);
		sh=0;
		if(k%2) {printf("-1\n");continue;}
		while(k) {
		    st[++sh]=1;k-=2;
			for(i=2; i<=60; i++) {
				if(k>=(1ll<<i))k-=1ll<<i,st[++sh]=0;
			}
		}
		printf("%d\n",sh);
		for(i=1; i<=sh; i++) printf("%d ",st[i]);
		putchar('\n');
	}
}