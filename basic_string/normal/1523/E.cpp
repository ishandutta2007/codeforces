#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7,N=1e5+3;
int fc[N],ic[N];
int qp(int a,int b){
	int r=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r;
}
int main(){
	int T,n,m,o,i,s;
	scanf("%d",&T);
	for(fc[0]=i=1;i<N;++i)fc[i]=fc[i-1]*1ll*i%P;
	for(ic[N-1]=qp(fc[N-1],P-2),i=N-1;i;--i)ic[i-1]=ic[i]*1ll*i%P;
	while(T--){
		scanf("%d%d",&n,&m),--m,o=n,s=1;
		for(i=1;i<n;++i){
			if(o<i)break;
			s=(s+fc[o]*1ll*ic[i]%P*ic[o-i]%P*ic[n]%P*fc[i]%P*fc[n-i])%P,o-=m;
		}
		printf("%d\n",s);
	}
	return 0;
}