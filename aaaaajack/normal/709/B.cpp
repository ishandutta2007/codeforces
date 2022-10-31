#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
int a[100100];
int main(){
	int n,b;
	long long ans=1LL<<60;
	scanf("%d%d",&n,&b);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	if(n==1){
		puts("0");
		return 0;
	}
	sort(a,a+n);
	for(int j=0;j<2;j++){
		long long l=0,r=0;
		if(a[j]<b) l=b-a[j];
		if(a[n-2+j]>b) r=a[n-2+j]-b;
		ans=min(ans,l+r+min(l,r));
	}
	printf("%lld\n",ans);
	return 0;
}