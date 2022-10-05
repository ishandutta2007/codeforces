#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;
int qp(int a,int b){
	int r=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r;
}
int main(){
	int n,m,i,s;
	scanf("%d%d",&n,&m),s=qp(m,n);
	for(i=0;i<n;++i)s=(s+qp(m,n-i)*1ll*qp(2*m-1,i))%P;
	printf("%d",s);
	return 0;
}