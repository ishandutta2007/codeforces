#include<bits/stdc++.h>
#define N 100100
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	long long period[3][4]={{0,3,1,2},{},{0,2,3,1}};
	while(t--){
		long long n;
		scanf("%lld",&n);
		int p2=0;
		long long t=1;
		while((t<<2)<=n) t<<=2,p2+=2;
		long long row=(n-t)/3;
		if(n%3==1) printf("%lld\n",t+row);
		else{
			long long ans;
			if(n%3==2) ans=t<<1;
			else ans=t<<1|t;
			while(p2>0){
				p2-=2;
				ans|=period[n%3][(row>>p2)&3]<<p2;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}