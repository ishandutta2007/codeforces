#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[200100],T;
ll sum,mx,tot;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),sum=mx=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i+=2)sum+=a[i];
		tot=0;
		for(int i=1;i+1<=n;i+=2){
			tot+=(a[i+1]-a[i]);
			if(tot<0)tot=0;
			mx=max(mx,tot);
		}
		tot=0;
		for(int i=2;i+1<=n;i+=2){
			tot+=(a[i]-a[i+1]);
			if(tot<0)tot=0;
			mx=max(mx,tot);
		}
		printf("%I64d\n",sum+mx);
	}
	return 0;
}