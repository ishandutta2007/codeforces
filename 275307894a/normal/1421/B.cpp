#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,z;
char a[539][1369];
int main(){
	int i,j;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		k=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++) cin>>a[i][j],a[i][j]-='0';
		}
		if(a[1][2]+a[2][1]-a[n][n-1]-a[n-1][n]<-a[1][2]-a[2][1]+a[n][n-1]+a[n-1][n]){
			printf("%d\n",a[1][2]+a[2][1]-a[n][n-1]-a[n-1][n]+2);
			if(a[1][2]) printf("1 2\n");
			if(a[2][1]) printf("2 1\n");
			if(!a[n][n-1]) printf("%d %d\n",n,n-1);
			if(!a[n-1][n]) printf("%d %d\n",n-1,n);
		}
		else{
			printf("%d\n",-a[1][2]-a[2][1]+a[n][n-1]+a[n-1][n]+2);
			if(!a[1][2]) printf("1 2\n");
			if(!a[2][1]) printf("2 1\n");
			if(a[n][n-1]) printf("%d %d\n",n,n-1);
			if(a[n-1][n]) printf("%d %d\n",n-1,n);
		}
	}
}