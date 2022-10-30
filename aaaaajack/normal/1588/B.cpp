#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		printf("? 1 %d\n",n);
		fflush(stdout);
		long long tt,cur;
		scanf("%lld",&tt);
		int l=1,r=n;
		while(r-l>1){
			int m=(l+r)/2;
			printf("? 1 %d\n",m);
			fflush(stdout);
			scanf("%lld",&cur);
			if(cur==tt) r=m;
			else l=m;
		}
		printf("? 1 %d\n",l);
		fflush(stdout);
		scanf("%lld",&cur);
		int b=tt-cur+1;
		tt-=1LL*b*(b-1)/2;
		int a=max(0,(int)floor(sqrt(tt*2)-10));
		while(1LL*a*(a-1)/2<tt) a++;
		printf("! %d %d %d\n",l+2-a-b,l+2-b,l+1);
		fflush(stdout);
	}
	return 0;
}