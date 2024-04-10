//%%%
#include<bits/stdc++.h>
using namespace std;
int a[100009];
int p[100009],q[100009];
int main(){
	register long long s=0;
	register int n,i,j,t=0,l;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&l);
		for(j=1;j<=l;++j)scanf("%d",a+j);
		for(j=2;j<=l;++j){
			if(a[j-1]<a[j]){
				s+=n;
				goto ggg;
			}
		}
		p[++t]=a[1],q[t]=a[l];
		ggg:;
	}
	sort(p+1,p+t+1);
	for(i=1;i<=t;++i){
		s+=n-(upper_bound(p+1,p+t+1,q[i])-p-1);
	}
	printf("%lld",s);
	return 0;
}