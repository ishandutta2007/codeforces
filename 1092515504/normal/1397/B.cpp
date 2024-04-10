#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100100];
ll res=0x3f3f3f3f3f3f3f3f;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int lim=pow(1e18,1.0/n);
	sort(a+1,a+n+1);
	for(int i=1;i<=lim;i++){
		ll now=0,k=1;
		for(int j=1;j<=n;j++){
			now+=abs(k-a[j]);
			k*=i;
		}
		res=min(res,now);
	}
	printf("%I64d\n",res);
	return 0;
}