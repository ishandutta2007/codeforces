#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3,P=1e9+7;
int u[N],p[N/8],iv[N];
bool b[N];
int main(){
	int n,i,j,k,t=0,s=1;
	scanf("%d",&n),iv[1]=1;
	for(i=2;i<=n;++i){
		if(iv[i]=(P-P/i)*1ll*iv[P%i]%P,!b[i])p[++t]=i,u[i]=-1;
		for(j=1;j<=t&&(k=p[j]*i)<=n;++j){
			if(b[k]=1,i%p[j])u[k]=-u[i];
			else{u[k]=0;break;} 
		}
	}
	for(i=2;i<=n;++i)j=n/i,s=(s-u[i]*1ll*j%P*iv[n-j])%P;
	printf("%d",(s+P)%P);
	return 0;
}