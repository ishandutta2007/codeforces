#include<cstdio>
using namespace std;
int main(){
	long long ans=1;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		if(i==1) ans+=(n-3);
		else if(i==2||i==n) ans+=(n-3);
		else ans+=(n-4);
	}
	printf("%I64d\n",ans);
	return 0;
}