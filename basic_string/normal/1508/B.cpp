#include<bits/stdc++.h>
using namespace std;const int N=1e5+3;
long long p[N];
int main(){
	int T,n,i,l,t;
	long long k;
	scanf("%d",&T),p[0]=p[1]=1;
	for(i=2;i<N;++i)p[i]=min((long long)4e18,p[i-1]*2);
	while(T--){
		scanf("%d%lld",&n,&k);
		if(p[n]<k){puts("-1");continue;}
		l=1e9,t=0;
		for(i=1;i<=n;++i){
			if(t>=l)printf("%d ",t),--t;
			else{l=1e9,t=0;if(k<=p[n-i]){
				printf("%d ",i); 
			
			}else{
				l=i,k-=p[n-i];
				for(t=i+1;;++t){
					if(k<=p[n-t])break;
					k-=p[n-t];
				}
				printf("%d ",t);--t;
			}}
		}putchar(10);
	}
	return 0;
}