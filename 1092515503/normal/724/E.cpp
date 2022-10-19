#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[10100],b[10100];
ll o[10100],res,sum;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),res+=a[i];
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),o[i]=1ll*m*(n-i)+b[i]-a[i];
	sort(o+1,o+n+1),sum=res;
	for(int i=1;i<=n;i++)res=min(res,sum+=o[i]-1ll*m*(i-1));
	printf("%lld\n",res);
	return 0;
}