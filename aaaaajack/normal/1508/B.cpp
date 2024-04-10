#include<bits/stdc++.h>
#define N 100100
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,now=0;
		long long k;
		scanf("%d%lld",&n,&k);
		if(n<=60 && (1LL<<n-1)<k ) puts("-1");
		else{
			while(n>0){
				n--;
				int tmp=1;
				while(n<=60 && n>=1 && (1LL<<n-1)<k){
					k-=(1LL<<n-1);
					tmp++;
					n--;
				}
				for(int i=tmp;i>=1;i--) printf("%d ",now+i);
				now+=tmp;
			}
			puts("");
		}
	}
	return 0;
}