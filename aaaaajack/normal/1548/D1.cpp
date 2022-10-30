#include<bits/stdc++.h>
#define N 6010
using namespace std;
int x[N],y[N];
int gcd(int a,int b){
	if(a==0 && b==0) return 0;
	while(b){
		a%=b;
		swap(a,b);
	}
	return a;
}
int main(){
	int n,c[4]={};
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&x[i],&y[i]);
		x[i]/=2;
		y[i]/=2;
		c[(x[i]&1)<<1 | (y[i]&1)]++;
	}
	long long ans=0;
	for(int i=0;i<4;i++){
		//printf("%d\n",c[i]);
		ans+=1LL*c[i]*(c[i]-1)/2*(n-c[i]);
		ans+=1LL*c[i]*(c[i]-1)*(c[i]-2)/6;
		//printf("%lld\n",ans);
	}
	printf("%lld\n",ans);
	return 0;
}