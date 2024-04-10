#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[300100];
ll msk[300100],sum,res;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%lld",&a[i],&msk[i]),sum+=a[i];
	if(sum<0)for(int i=1;i<=n;i++)a[i]=-a[i];
	for(int i=0;i<62;i++){
		sum=0;
		for(int j=1;j<=n;j++)if((msk[j]&(1ll<<i))&&((1ll<<(i+1))>msk[j]))sum+=a[j];
		if(sum<=0)continue;
		res|=1ll<<i;
		for(int j=1;j<=n;j++)if(msk[j]&(1ll<<i))a[j]=-a[j];
	}
	printf("%lld\n",res);
	return 0;
}