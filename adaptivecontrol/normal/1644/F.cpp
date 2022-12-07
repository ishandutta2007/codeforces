#include<bits/stdc++.h>
using namespace std;
const int ggg=3,mod=998244353,invggg=(mod+1)/3;
int mypow(int x,int times){
	int ret=1;
	while(times){
		if(times&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;times>>=1;
	}return ret;
}
int pos[4194304];
void init(int n){
	for(int i=1;i<n;i++){
		pos[i]=pos[i>>1]>>1;
		if(i&1)pos[i]|=(n>>1);
	}
}
void DFT(int *a,int n,int rev){
	int _w;
	if(rev==1)_w=ggg;else _w=invggg;
	init(n);
	for(int i=0;i<n;i++)
		if(i<pos[i])
			a[i]^=a[pos[i]]^=a[i]^=a[pos[i]];
	for(int i=2;i<=n;i<<=1){
		int wn=mypow(_w,(mod-1)/i),wk;
		for(int j=0;j<n;j+=i){
			wk=1;
			for(int k=j;k<(j|(i>>1));k++){
				int tmpa=a[k],tmpb=1ll*wk*a[k|(i>>1)]%mod;
				a[k]=(tmpa+tmpb)%mod;
				a[k|(i>>1)]=(tmpa-tmpb+mod)%mod;
				wk=1ll*wn*wk%mod;
			}
		}
	}
	if(rev==-1){
		int tmp=mypow(n,mod-2);
		for(int i=0;i<n;i++)
			a[i]=1ll*a[i]*tmp%mod;
	}
}
int a[4194304],b[4194304];
int val[2000003],ans=0,S[5003][5003],fac[2000003],inv[2000003];
int calc(int len,int k){
	k=min(k,len);
	if(len<=5000)return S[len][k];
	int maxn=1;
	while(maxn<=2*len+2)maxn*=2;
	vector<int>v1,v2;
	for(int i=0;i<maxn;i++)
		if(i<=len){
			a[i]=1ll*mypow(i,len)*inv[i]%mod;
			b[i]=inv[i];
			if(i&1)b[i]=mod-b[i];
		}else
			a[i]=0,b[i]=0;
	DFT(a,maxn,1);
	DFT(b,maxn,1);
	for(int i=0;i<maxn;i++)a[i]=1ll*a[i]*b[i]%mod;
	DFT(a,maxn,-1);
	int ret=0;
	for(int i=0;i<=k;i++)
		ret=(ret+1ll*a[i])%mod;
	return ret;
}
int main(){
//	freopen("sequence.in","r",stdin);
//	freopen("sequence.out","w",stdout);
	inv[0]=1;
	fac[0]=1;for(int i=1;i<2000003;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[2000002]=mypow(fac[2000002],mod-2);
	for(int i=2000001;i>=0;i--)inv[i]=1ll*inv[i+1]*(i+1)%mod;
	S[0][0]=1;
	for(int i=1;i<=5000;i++)
		for(int j=1;j<=5000;j++)
			S[i][j]=(1ll*S[i-1][j]*j+S[i-1][j-1])%mod;
	for(int i=0;i<=5000;i++)
		for(int j=1;j<=5000;j++)
			S[i][j]=(S[i][j]+S[i][j-1])%mod;
	int n,k;
	cin>>n>>k;val[1]=1;
	if(n==1||k==1){cout<<1;return 0;}
	for(int i=1;i<=n;i++){
		ans+=val[i]*(calc((n+i-1)/i,k)-1);
		if(ans<0)ans+=mod;
		if(ans>=mod)ans-=mod;
		for(int j=i+i;j<=n;j+=i)
			val[j]-=val[i];
	}cout<<ans;
}