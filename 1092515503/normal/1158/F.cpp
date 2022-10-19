#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef long long ll;//
int n,c,m,a[3010];
int ksm(int x,int y=mod-2){
	int z=1;
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;
	return z;
}
void ADD(int &x,int y){x+=y;if(x>=mod)x-=mod;}
int SUM(int x,int y){if(x+y>=mod)return x+y-mod;return x+y;}
namespace SUB1{//subtask for c>10
	int g[3010][3010],cnt[3010],pov[3010],vop[3010];
	ll s[3010][3010];
	void solve(){
		pov[0]=1;for(int i=1;i<=n;i++)pov[i]=(pov[i-1]<<1)%mod;
		for(int i=0;i<=n;i++)pov[i]=(pov[i]-1+mod)%mod,vop[i]=ksm(pov[i]);
		for(int l=1;l<=n;l++){
			memset(cnt,0,sizeof(cnt));
			int ways=1,nil=c-1;
			for(int r=l+1;r<=n;r++){
				cnt[a[r]]++;
				if(a[r]!=a[l]){
					if(cnt[a[r]]==1)nil--;else ways=1ll*ways*vop[cnt[a[r]]-1]%mod;
					if(!nil)g[l][r]=ways;
					ways=1ll*ways*pov[cnt[a[r]]]%mod;
				}else ways=(ways<<1)%mod;
			}
			ways=1;
			if(nil)for(int i=1;i<=c;i++){if(cnt[i])ways=1ll*ways*(pov[cnt[i]]+1)%mod;}
			else{
				for(int i=1;i<=c;i++)ways=1ll*ways*(pov[cnt[i]]+(i==a[l]))%mod;
				ways=SUM(pov[n-l]+1,mod-ways);
			}
			s[l][0]=ways;
//			printf("%d:%d\n",l,f[l][0]);
		}
		s[n+1][0]=1;
		for(int i=n;i;i--){
			for(int j=1;j<=m;j++)for(int k=i+c-1;k<=n;k++){
				s[i][j]+=g[i][k]*s[k+1][j-1];
				if(!(k%8))s[i][j]%=mod;
			}
			for(int j=0;j<=m;j++)(s[i][j]+=s[i+1][j])%=mod;
		}
		for(int i=0;i<=n;i++)printf("%lld ",(s[1][i]+mod-!i)%mod);puts(""); 
	}
}
namespace SUB2{//subtask for c<=10
	int f[2][3010][1<<10],lim,res[3010];
	void solve(){
		for(int i=1;i<=n;i++)a[i]--;
		lim=1<<c;
		f[0][0][0]=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<=m;j++)for(int k=0;k<lim-1;k++)f[!(i&1)][j][k]=0;
			for(int j=0;j<=m;j++)for(int k=0;k<lim-1;k++){
				int K=k|(1<<a[i+1]);
				if(K==lim-1)K=0;
				(f[!(i&1)][j][k]+=f[i&1][j][k])%=mod;
				(f[!(i&1)][j+!K][K]+=f[i&1][j][k])%=mod;//choose or not.
			}	
		}
		for(int j=0;j<=n;j++)for(int k=0;k<lim-1;k++)(res[j]+=f[n&1][j][k])%=mod;
		for(int i=0;i<=n;i++)printf("%d ",(res[i]-!i+mod)%mod);puts("");
	}
}
//namespace SUB3{void solve(){for(int i=0;i<=n;i++)printf("%d ",(C(n,i)-!i+mod)%mod);puts("");}}//subtask for c=1
void read(int &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
}
int main(){
	read(n),read(c),m=n/c;
	for(int i=1;i<=n;i++)read(a[i]);
	if(c<=10)SUB2::solve();
	else SUB1::solve();
	return 0;
}