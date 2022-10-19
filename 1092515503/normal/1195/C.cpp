#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[100001][2],mx1,mx2,f[100001][2];
int main(){
	scanf("%I64d",&n);
	for(ll i=1;i<=n;i++)scanf("%I64d",&a[i][0]);
	for(ll i=1;i<=n;i++)scanf("%I64d",&a[i][1]);
	f[1][0]=mx1=a[1][0],f[1][1]=mx2=a[1][1];
	for(ll i=2;i<=n;i++)f[i][0]=mx2+a[i][0],f[i][1]=mx1+a[i][1],mx1=max(mx1,f[i][0]),mx2=max(mx2,f[i][1]);
	printf("%I64d\n",max(mx1,mx2));
	return 0;
}