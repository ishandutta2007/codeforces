#include <cstdio>
int c[101];
int main(){
	int n,m,k=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) c[i]=0;
	for(int i=0;i<n;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		for(int j=l;j<=r;j++) c[j]=1;
	}
	for(int i=1;i<=m;i++){
		if(c[i]==0) k++;
	}
	printf("%d\n",k);
	for(int i=1;i<=m;i++){
		if(c[i]==0) printf("%d ",i);
	}
}