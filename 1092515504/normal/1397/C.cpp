#include<bits/stdc++.h>
using namespace std;
int n;
typedef long long ll;
ll a[100100];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
	if(n==1){
		puts("1 1");
		printf("%I64d\n",-a[1]);
		puts("1 1");
		puts("0");
		puts("1 1");
		puts("0");
		return 0;
	}
	printf("%d %d\n",1,n);
	for(int i=1;i<=n;i++)printf("%I64d ",-a[i]*n),a[i]-=a[i]*n;puts("");
	printf("%d %d\n",1,n-1);
	for(int i=1;i<n;i++)printf("%I64d ",-a[i]);puts("");
	printf("%d %d\n",n,n);
	printf("%I64d\n",-a[n]);
	return 0;
}