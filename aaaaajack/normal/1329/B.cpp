#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int d,m;
		long long ans=1;
		scanf("%d%d",&d,&m);
		for(long long i=1;i<=d;i<<=1){
			ans=ans*(min(i,d-i+1)+1)%m;
		}
		ans+=m-1;
		printf("%lld\n",ans%m);
	}
	return 0;
}