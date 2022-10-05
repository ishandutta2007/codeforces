//
#include<bits/stdc++.h>
using namespace std;
int f[109][109][2],a[109];
int main(){
	register int n,i,j,s;
	scanf("%d",&n),s=(n+1)/2;
	memset(f,63,sizeof(f)),f[n+1][0][0]=f[n+1][0][1]=0;
	for(i=1;i<=n;++i){
		scanf("%d",a+i);
		if(a[i]&1)--s;
	}
	for(i=n;i;--i){
		for(j=s;j>=0;--j){
			if(a[i]&1){
				f[i][j][1]=min(f[i+1][j][0]+1,f[i+1][j][1]);
			}else if(!a[i]){
				if(j)f[i][j][1]=min(f[i+1][j-1][0]+1,f[i+1][j-1][1]);
				f[i][j][0]=min(f[i+1][j][0],f[i+1][j][1]+1);
			}else{
				f[i][j][0]=min(f[i+1][j][0],f[i+1][j][1]+1);
			}
		}
	}
	printf("%d\n",min(f[1][s][0],f[1][s][1]));
	return 0;
}