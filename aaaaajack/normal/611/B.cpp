#include<cstdio>
using namespace std;
int main(){
	long long a,b;
	int ans=0;
	scanf("%I64d%I64d",&a,&b);
	for(int r=2;r<=60;r++){
		for(int j=0;j<r-1;j++){
			long long tmp=(1LL<<r)-1-(1LL<<j);
			if(tmp>=a&&tmp<=b) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}