#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3,P=1e9+7;
int p[N/8],f[N],g[N],h[N];
bool b[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int i,j,k,t=0;
	for(i=2,f[1]=1;i<N;++i){
		if(!b[i])for(f[p[++t]=j=i]=i+(k=i-1);g[j]=1,j*1ll*i<N;j*=i)f[j*i]=f[j]*i+(k*=i);
		for(j=1;j<=t&&(k=i*p[j])<N;++j)if(b[k]=1,i%p[j])g[k]=i,f[k]=f[i]*f[p[j]];else{
			g[k]=g[i],f[k]=f[g[i]]*f[k/g[i]];
			break;
		}
	}
	for(i=1;i<N;++i)j=(i*(i+1ll)*(2*i+1)/3-3ll*i*i+2*f[i])%P,f[i]=(f[i-1]+j)%P,g[i]=(g[i-1]+j*1ll*i)%P,h[i]=(h[i-1]+j*1ll*i%P*i)%P;
	for(cin>>t;t--;)cin>>i>>j,k=min(i,j),cout<<(((i+1ll)*(j+1)%P*f[k]-(i+j+2ll)*g[k]+h[k])%P+P)%P<<'\n';
	return 0;
}