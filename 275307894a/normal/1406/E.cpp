#include<cstdio>
#include<cmath>
using namespace std;
int n,m,k,ks,x,y,z,f[100039],head,s[100039],tot=1,ans,last,d[100039],dh,pr[100039],ph,nows;
int main() {
//	freopen("1.out","w",stdout);
	register int i,j,h;
	scanf("%d",&n);
	ks=sqrt(n);
	for(i=2; i<=n; i++) {
		if(!f[i]) {
			if(i<=ks)d[++dh]=i;
			else pr[++ph]=i;
			s[++head]=i;
		}
		for(j=1; j<=head&&i*s[j]<=n; j++) {
			f[i*s[j]]=1;
			if(i%s[j]==0) break;
		}
	}
//	for(i=1;i<=ph;i++)printf("%d\n",pr[i]);
	for(i=1; i<=dh; i++) {
		printf("B %d\n",d[i]);
		fflush(stdout);
		scanf("%d",&x);
		nows=d[i];
		while(nows<=n) {
			printf("A %d\n",nows);
			fflush(stdout);
			scanf("%d",&x);
			if(!x) break;
			tot*=d[i];
			nows*=d[i];
		}
	}
	k=sqrt(ph);
	printf("A 1\n");
	fflush(stdout);
	scanf("%d",&last);
	for(i=1; ph&&(i<=ph/k+(k*k==ph?0:1)); i++) {
		ans=0;
		for(j=i*k-k+1; j<=i*k&&j<=ph; j++) {
			printf("B %d\n",pr[j]);
			fflush(stdout);
			scanf("%d",&x);
			if(x>=2) tot*=pr[j];
			ans++;
		}
		printf("A 1\n");
		fflush(stdout);
		scanf("%d",&x);
		if(last!=x+ans) {
			for(j=i*k-k+1; j<=i*k&&j<=ph; j++) {
				printf("A %d\n",pr[j]);
				fflush(stdout);
				scanf("%d",&y);
				if(y)tot*=pr[j];
			}
			break;
		}
		last=x;
	}
	printf("C %d\n",tot);
}