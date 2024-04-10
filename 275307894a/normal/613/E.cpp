#include<cstdio>
#include<cstring>
#define N 2000
#define mod 1000000007
#define mod1 998244353
#define base 131
#define re register
#define ll long long
#define I inline
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z;ll f[3][N+5][N+5],ans,sum1[N+5],sum2[N+5],sum3[N+5],sum4[N+5],ba[N+5],inv[N+5];
char s[3][N+5],a[N+5];
I ll mpow(ll x,ll y=mod1-2){ll ans=1;while(y) (y&1)&&(ans=ans*x%mod1),x=x*x%mod1,y>>=1;return ans;}
I ll find1(int x,int y){return (sum1[y]-sum1[x-1]+mod1)*inv[x-1]%mod1;}
I ll find2(int x,int y){return (sum2[x]-sum2[y+1]+mod1)*inv[n-y]%mod1;}
I ll find3(int x,int y){return (sum3[y]-sum3[x-1]+mod1)*inv[x-1]%mod1;}
I ll find4(int x,int y){return (sum4[x]-sum4[y+1]+mod1)*inv[m-y]%mod1;}
I void make(){
	int i,j,k;memset(f,0,sizeof(f));
	for(i=1;i<=n;i++) sum1[i]=(sum1[i-1]+(s[1][i]-'a'+1)*ba[i])%mod1;
	for(i=n;i;i--) sum2[i]=(sum2[i+1]+(s[2][i]-'a'+1)*ba[n-i+1])%mod1;
	for(i=1;i<=m;i++) sum3[i]=(sum3[i-1]+(a[i]-'a'+1)*ba[i])%mod1;
	for(i=m;i;i--) sum4[i]=(sum4[i+1]+(a[i]-'a'+1)*ba[m-i+1])%mod1;
	for(i=1;i<=n;i++){
		for(j=max(0,i-(m-1)/2);j<i;j++){
			f[2][i][2*(i-j)]=(find1(j+1,i)==find4(1,i-j)&&find2(j+1,i)==find4(i-j+1,2*(i-j)));
			f[1][i][2*(i-j)]=(find2(j+1,i)==find3(1,i-j)&&find1(j+1,i)==find3(i-j+1,2*(i-j)));//printf("%d %d %lld %lld %lld %lld\n",j+1,i,find2(j+1,i),find3(1,i-j),find1(j+1,i),find3(i-j+1,2*(i-j)));
		} 
	}
	for(i=0;i<=n;i++) f[1][i][0]=f[2][i][0]=1; 
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			for(k=1;k<=2;k++)s[k][i]==a[j]&&(f[k][i][j]+=f[k][i-1][j-1],j>=3&&(s[3-k][i]==a[j-1])&&(f[k][i][j]+=f[3-k][i-1][j-2]),f[k][i][j]%=mod);
		}
	}
	for(i=1;i<=n;i++,ans%=mod){
		ans+=f[1][i][m]+f[2][i][m];
		for(j=i+2;j<=min(n,i+(m-1)/2);j++){
			if(find1(i+1,j)==find3(m-2*(j-i)+1,m-(j-i))&&find2(i+1,j)==find3(m-(j-i)+1,m)) ans+=f[1][i][m-(j-i)*2];
			if(find2(i+1,j)==find4(m-2*(j-i)+1,m-(j-i))&&find1(i+1,j)==find4(m-(j-i)+1,m)) ans+=f[2][i][m-(j-i)*2];
			//printf("%d %d %lld %lld %lld %lld\n",i,j,find1(i+1,j),find3(m-2*(j-i)+1,m-(j-i)),find2(i+1,j),find3(m-(j-i)+1,m));
		}
	}
}
I void swap(char &x,char &y){x^=y^=x^=y;}
int main(){
//	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	re int i;scanf("%s%s%s",s[1]+1,s[2]+1,a+1);n=strlen(s[1]+1);m=strlen(a+1);
	if(m==1){
		for(i=1;i<=n;i++) ans+=(s[1][i]==a[1])+(s[2][i]==a[1]);printf("%d\n",ans);return 0;
	}
	if(m==2){
		for(i=1;i<=n;i++) {
			if(s[2][i]==a[1])ans+=(s[2][i-1]==a[2])+(s[2][i+1]==a[2])+(s[1][i]==a[2]);
			if(s[1][i]==a[1])ans+=(s[1][i-1]==a[2])+(s[1][i+1]==a[2])+(s[2][i]==a[2]);
		}
		printf("%d\n",ans);return 0;
	}
	ba[0]=inv[0]=1;for(i=1;i<=max(n,m);i++) ba[i]=ba[i-1]*base%mod1,inv[i]=inv[i-1]*mpow(base)%mod1;
	make();for(i=1;i<=m/2;i++) swap(a[i],a[m-i+1]);make();
	if(m%2==0){
		for(i=m/2;i<=n;i++)ans+=(find1(i-m/2+1,i)==find4(1,m/2)&&find2(i-m/2+1,i)==find4(m/2+1,m))+(find2(i-m/2+1,i)==find3(1,m/2)&&find1(i-m/2+1,i)==find3(m/2+1,m));
		for(i=1;i<=n-m/2+1;i++)ans+=(find1(i,i+m/2-1)==find3(1,m/2)&&find2(i,i+m/2-1)==find3(m/2+1,m))+(find2(i,i+m/2-1)==find4(1,m/2)&&find1(i,i+m/2-1)==find4(m/2+1,m));
	}
	printf("%lld\n",ans);
}