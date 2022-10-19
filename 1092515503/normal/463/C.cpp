#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,num[2001][2001],ls[4001],rs[4001],mx1=-1,mx2=-1,mx11,mx12,mx21,mx22;
int mat(int l,int r){
	return num[(n+r-l+1)/2][(3*n-l-r+1)/2];
}
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%lld",&num[i][j]),ls[n*2-i-j+1]+=num[i][j],rs[i-j+n]+=num[i][j];
//	for(int i=1;i<n*2;i++)printf("%d %d\n",ls[i],rs[i]);
	for(int i=1;i<n*2;i++){
		if(i&1)for(int j=abs(i-n)+1;j<=2*n-abs(i-n)-1;j+=2){
			if(mx1<rs[i]+ls[j]-mat(j,i))mx1=rs[i]+ls[j]-mat(j,i),mx12=(3*n-j-i+1)/2,mx11=(n+i-j+1)/2;
//			printf("1:%d %d:%d %d\n",i,j,(n+i-j+1)/2,(3*n-j-i+1)/2);
		}
		else for(int j=abs(i-n)+1;j<=2*n-abs(i-n)-1;j+=2){
			if(mx2<rs[i]+ls[j]-mat(j,i))mx2=rs[i]+ls[j]-mat(j,i),mx22=(3*n-j-i+1)/2,mx21=(n+i-j+1)/2;
//			printf("2:%d %d:%d %d\n",i,j,(n+i-j+1)/2,(3*n-j-i+1)/2);
		}
	}
	printf("%lld\n",mx1+mx2);
	printf("%lld %lld %lld %lld\n",mx11,mx12,mx21,mx22);
	return 0;
}