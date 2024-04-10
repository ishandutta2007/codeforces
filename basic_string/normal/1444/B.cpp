#include<bits/stdc++.h>
using namespace std;
const int N=3e5+3,P=998244353;
int a[N];
int qp(int a,int b=P-2){
	int r=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r; 
}
int main(){
	int n,m,i,j,k;
	long long l=0;
	scanf("%d",&n),m=n*2;
	for(i=1;i<=m;++i)scanf("%d",a+i);
	sort(a+1,a+m+1);
	for(i=1,k=1;i<=n;++i)k=k*1ll*qp(i)%P;
	for(i=n+1;i<=m;++i)k=k*1ll*i%P;
	for(i=1;i<=n;++i)l-=a[i];
	for(i=n+1;i<=m;++i)l+=a[i];
	printf("%lld",l%P*k%P);
	return 0;
}