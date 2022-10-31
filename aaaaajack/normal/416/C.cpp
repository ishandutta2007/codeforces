#include<cstdio>
using namespace std;
int main(){
	int n,i,j,a[2000]={0},b[2000]={0},p[2000]={0},c[2000]={0},t[2000]={10000},m,r,s,count=0,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&c[i],&p[i]);
	}
	scanf("%d",&m);
	for(i=1;i<=m;i++) scanf("%d",&t[i]);
	for(i=1;i<=n;i++){
		r=0;
		for(j=1;j<=n;j++){
			if(!a[j]&&p[j]>p[r]) r=j;
		}
		s=0;
		if(r){
			for(j=1;j<=m;j++){
				if(!b[j]&&t[j]>=c[r]&&t[j]<t[s]) s=j;
			}
			if(s) a[r]=s,b[s]=r,count++,ans+=p[r];
			else a[r]=10000;
		}
	}
	printf("%d %d\n",count,ans);
	for(i=1;i<=n;i++){
		if(a[i]>0&&a[i]<10000) printf("%d %d\n",i,a[i]);
	}
	return 0;
}