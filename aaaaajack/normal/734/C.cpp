#include<bits/stdc++.h>
#define N 300100
long long a[N],b[N],c[N],d[N];
using namespace std;
int main(){
	int n,m,k;
	long long x,s;
	long long ans;
	scanf("%d%d%d",&n,&m,&k);
	scanf("%lld%lld",&x,&s);
	ans=x*n;
	for(int i=0;i<m;i++) scanf("%lld",&a[i]);
	for(int i=0;i<m;i++) scanf("%lld",&b[i]);
	a[m]=x;
	b[m]=0;
	for(int i=0;i<k;i++) scanf("%lld",&c[i]);
	for(int i=0;i<k;i++) scanf("%lld",&d[i]);
	for(int i=0;i<=m;i++){
		int j=upper_bound(d,d+k,s-b[i])-d-1;
		if(j>=0){
			ans=min(ans,max(n-c[j],0LL)*a[i]);
		}
		else if(b[i]<=s) ans=min(ans,n*a[i]);
	}
	printf("%lld\n",ans);
	return 0;
}