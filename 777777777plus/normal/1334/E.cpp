#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 5e1+5;
const ll mod = 998244353;
 
int Q;
ll D,x,y;
int tot;
ll p[M];
int C[M][M];
 
void prepare(){
	for(int i=0;i<M;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	}
}
 
ll work(ll x){
	static int q[M];
	ll ans=1,cnt=0;
	ll x1=x;
	for(int i=1;i<=tot;++i){
		while(x%p[i]==0){
			x/=p[i];
			++q[i];
		}
		cnt+=q[i];
	}
	for(int i=1;i<=tot;++i){
		ans=(ans*C[cnt][q[i]])%mod;
		cnt-=q[i];
		while(x1%p[i]==0){
			x1/=p[i];
			--q[i];
		}
	}
	return ans;
}
 
int main(){
	prepare();
	scanf("%lld",&D);
	for(ll i=2;i*i<=D;++i)
	if(D%i==0){
		p[++tot]=i;
		while(D%i==0)D/=i;
	}
	if(D>1)p[++tot]=D;
	scanf("%d",&Q);
	while(Q--){
		scanf("%lld%lld",&x,&y);
		ll g=__gcd(x,y);
		printf("%lld\n",work(x/g)*work(y/g)%mod);
	}
}