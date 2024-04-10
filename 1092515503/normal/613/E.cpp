#include<bits/stdc++.h>
using namespace std;
const int M=3,N=4010,bs=37,md[M]={19260817,17680321,19491001};
int ksm(int x,int y,int mod){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
int pov[M][N],inv[M][N];
struct HASH{
	int val[M];int len;
	HASH(){for(int i=0;i<M;i++)val[i]=0;len=0;}
	HASH(char ip){for(int i=0;i<M;i++)val[i]=ip-'a';len=1;}
	friend HASH operator+(const HASH&x,const HASH&y){
		HASH z;
		for(int i=0;i<M;i++)z.val[i]=(1ll*x.val[i]*pov[i][y.len]+y.val[i])%md[i];
		z.len=x.len+y.len;return z;
	}
	friend HASH operator/(const HASH&x,const HASH&y){
		HASH z;
		for(int i=0;i<M;i++)z.val[i]=1ll*(x.val[i]+md[i]-y.val[i])*inv[i][y.len]%md[i];
		z.len=x.len-y.len;return z;
	}
	friend bool operator==(const HASH&x,const HASH&y){
		if(x.len!=y.len)return false;
		for(int i=0;i<M;i++)if(x.val[i]!=y.val[i])return false;
		return true;
	}
	friend bool operator!=(const HASH&x,const HASH&y){return!(x==y);}
}S[2][2][2010],T[2010];
int n,m,f[2010][4][2010],mat[2][2][2010],res;
int g[2010][2][2010];
char s[2][2010],t[2010];
void init(){
	int lim=max(n,m);
	for(int t=0;t<M;t++){
		pov[t][0]=inv[t][0]=1;
		for(int i=1;i<=lim;i++)pov[t][i]=1ll*pov[t][i-1]*bs%md[t];
		inv[t][lim]=ksm(pov[t][lim],md[t]-2,md[t]);
		for(int i=lim;i;i--)inv[t][i-1]=1ll*inv[t][i]*bs%md[t];
	}
	for(int t=0;t<2;t++){
		for(int i=1;i<=n;i++)S[t][0][i]=s[t][i]+S[t][0][i-1];
		for(int i=n;i;i--)S[t][1][i]=s[t][i]+S[t][1][i+1];
	}
	for(int i=1;i<=m;i++)T[i]=t[i]+T[i-1];
}
const int mod=1e9+7;
void ADD(int&x,int y){if((x+=y)>=mod)x-=mod;}
void solve(){
	memset(f,0,sizeof(f)),memset(g,0,sizeof(g));
	for(int i=n;i;i--)for(int j=3;j>=0;j--)for(int k=m;k;k--){
		if(s[j&1][i]!=t[k])continue;
		if(k==m){f[i][j][k]=1;if(m==1&&!(j&2))(++res)%=mod;continue;}
		if(!(j&2))ADD(f[i][j][k],f[i][3^j][k+1]);
		ADD(f[i][j][k],f[i+1][j&1][k+1]);
//			printf("%d,%d,%d:%d\n",i,j,k,f[i][j][k]);
		int p=m-k+1;
		if(!(j&2)&&p>=4&&!(p&1)&&i+(p>>1)-1<=n){
			bool ok=true;
			if(T[k+(p>>1)-1]/T[k-1]!=S[j][0][i+(p>>1)-1]/S[j][0][i-1])ok=false;
			if(T[m]/T[k+(p>>1)-1]!=S[!j][1][i]/S[!j][1][i+(p>>1)])ok=false;
			if(ok)(++f[i][j][k])%=mod;
		}
//		if(f[i][j][k])printf("%d,%d,%d:%d\n",i,j,k,f[i][j][k]);
		if(j&2)continue;
		if(k==1)ADD(res,f[i][j][k]);
		if(k>=5&&(k&1)){
			if(i<=(k>>1))continue;
			if(T[k-1]/T[k>>1]!=S[j&1][0][i-1]/S[j&1][0][i-1-(k>>1)])continue;
			if(T[k>>1]!=S[!(j&1)][1][i-(k>>1)]/S[!(j&1)][1][i])continue;
			ADD(res,f[i][j][k]);
		}
	}
}
void substract(){
	if(m==1)for(int i=1;i<=n;i++){
		if(s[0][i]==t[1])(res+=mod-1)%=mod;
		if(s[1][i]==t[1])(res+=mod-1)%=mod;
	}
	if(m==2)for(int i=1;i<=n;i++){
		if(s[0][i]==t[1]&&s[1][i]==t[2])(res+=mod-1)%=mod;
		if(s[1][i]==t[1]&&s[0][i]==t[2])(res+=mod-1)%=mod;
	}
}
int main(){
	scanf("%s%s%s",s[0]+1,s[1]+1,t+1),n=strlen(s[0]+1),m=strlen(t+1);
	init();
	solve();
	for(int t=0;t<2;t++){
		reverse(s[t]+1,s[t]+n+1);
		swap(S[t][0],S[t][1]),reverse(S[t][0]+1,S[t][0]+n+1),reverse(S[t][1]+1,S[t][1]+n+1);
	}
	solve();
	substract();
	printf("%d\n",res);
	return 0;
}
/*
baedc
cdeab
abcdeedcba
*/