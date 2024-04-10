#include<bits/stdc++.h>
#define R (rand()|181766&5156951569^5156918176)%n+1
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,f[1000039],maxn1,maxn2;
int main(){
	srand((unsigned int) time(0)); srand((unsigned int) time(0)); 
	register int i;
	scanf("%d",&m);
	n=(1<<m)-1;
	for(i=1;i<=415;i++){
		x=R;y=R;z=R;
		while(y==x) y=R;
		while(z==y||z==x) z=R;
		printf("? %d %d %d\n",x,y,z);
		fflush(stdout);
		scanf("%d",&x);
		f[x]++;
	}
	for(i=1;i<=n;i++)maxn1=max(maxn1,f[i]);
	for(i=n;i;i--) if(maxn1==f[i]){f[i]=0;maxn1=i;break;}
	for(i=1;i<=n;i++) maxn2=max(maxn2,f[i]);
	for(i=n;i;i--) if(f[i]==maxn2){f[i]=0;maxn2=i;break;}
	//printf("%d %d\n",maxn1,maxn2);
	for(i=1;i<=n;i++){
		if(i==maxn1||i==maxn2) continue;
		printf("? %d %d %d\n",maxn1,maxn2,i);
		fflush(stdout);
		scanf("%d",&x);
		if(x!=maxn1&&x!=maxn2) {printf("! %d",i);return 0;}
	}
	printf("! %d",rand()%n+1);
}