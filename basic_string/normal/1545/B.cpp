#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3,P=998244353;
int fc[N],ic[N];
char s[N];
int qp(int a,int b){
	int r=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r;
}
int C(int n,int m){
	return fc[n]*1ll*ic[m]%P*ic[n-m]%P;
}
int main(){
	int T,n,i,j,k,l,c;
	fc[0]=1;
	for(i=1;i<N;++i)fc[i]=fc[i-1]*1ll*i%P;
	ic[N-1]=qp(fc[N-1],P-2);
	for(i=N-1;i;--i)ic[i-1]=ic[i]*1ll*i%P;
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1),j=0,k=0,c=0;
		for(i=1;i<=n+1;++i){
			if(s[i]=='1')++c;
			else j+=c/2,k+=c%2,c=0;
		}
		printf("%d\n",C(n-j-k,j));
	}
	return 0;
}