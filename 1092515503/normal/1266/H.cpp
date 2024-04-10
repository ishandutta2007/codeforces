/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
const int N=60;
typedef long long ll;
typedef __int128 ii;
ll ksm(ll x,ll y,ll mod){ll z=1;for(;y;y>>=1,x=(ii)x*x%mod)if(y&1)z=(ii)z*x%mod;return z;}
void Gauss(int n,ll a[N][N<<1],ll mod){
	// for(int i=1;i<=n;i++,puts(""))for(int j=1;j<=(n<<1);j++)printf("%lld ",a[i][j]);
	for(int i=1,j;i<=n;i++){
		for(j=i;j<=n;j++)if(a[j][i])break;
		assert(j<=n);
		if(i!=j)swap(a[i],a[j]);
		ll inv=ksm(a[i][i],mod-2,mod);
		for(int j=i;j<=(n<<1);j++)a[i][j]=(ii)a[i][j]*inv%mod;
		for(int j=1;j<=n;j++)if(i!=j){
			ll lam=mod-a[j][i];
			for(int k=i;k<=(n<<1);k++)a[j][k]=((ii)a[i][k]*lam+a[j][k])%mod;
		}
	}
	// for(int i=1;i<=n;i++,puts(""))for(int j=1;j<=(n<<1);j++)printf("%lld ",a[i][j]);
	// puts("");
}
const ll mod1=9000000000000000041,mod2=8999999999999999983;
ll a[N][N<<1],b[N][N],c[N][N],U[N],V[N],W[N];
int n,B[N],R[N],q;
char s[N];
bool g[N][N],vis[N];
void dfs(int x){if(vis[x])return;vis[x]=true;for(int y=1;y<n;y++)if(g[x][y])dfs(y);}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%d%d",&B[i],&R[i]);
	for(int i=1;i<n;i++){
		a[i][i]=2,a[i][i+n-1]=1;
		if(R[i]<n)a[R[i]][i]--;
		if(B[i]<n)a[B[i]][i]--;
	}
	for(int i=1;i<n;i++)for(int j=1;j<n;j++)if(a[i][j]<0)a[i][j]+=mod1;
	Gauss(n-1,a,mod1);for(int i=1;i<n;i++)for(int j=1;j<n;j++)b[i][j]=a[i][j+n-1];memset(a,0,sizeof(a));

	for(int i=1;i<n;i++){
		a[i][i]=2,a[i][i+n-1]=1;
		if(R[i]<n)a[R[i]][i]--;
		if(B[i]<n)a[B[i]][i]--;
	}
	for(int i=1;i<n;i++)for(int j=1;j<n;j++)if(a[i][j]<0)a[i][j]+=mod2;
	Gauss(n-1,a,mod2);for(int i=1;i<n;i++)for(int j=1;j<n;j++)c[i][j]=a[i][j+n-1];memset(a,0,sizeof(a));

	scanf("%d",&q);
	for(int K;q--;){
		scanf("%d%s",&K,s+1);
		for(int i=1;i<n;i++)U[i]=V[i]=W[i]=0;
		for(int i=1;i<n;i++)if(s[i]=='R')U[i]++,B[i]<n?U[B[i]]--:0;
		U[1]++,U[K]--;

		for(int i=1;i<n;i++)for(int j=1;j<n;j++)
			if(U[i]<0)V[j]=((ii)(U[i]+mod1)*b[j][i]+V[j])%mod1,W[j]=((ii)(U[i]+mod2)*c[j][i]+W[j])%mod2;
			else V[j]=((ii)U[i]*b[j][i]+V[j])%mod1,W[j]=((ii)U[i]*c[j][i]+W[j])%mod2;
		// for(int i=1;i<n;i++)printf("%lld ",V[i]);puts("");
		// for(int i=1;i<n;i++)printf("%lld ",W[i]);puts("");
		bool ok=true;
		for(int i=1;i<n;i++)if(V[i]!=W[i]||(V[i]==0&&s[i]=='R')){ok=false;break;}
		if(!ok){puts("-1");continue;}
		for(int i=1;i<n;i++)W[i]=V[i]-(s[i]=='R');
		for(int i=1;i<n;i++)if(V[i]||W[i])g[s[i]=='R'?R[i]:B[i]][i]=true;

		dfs(K);
		for(int i=1;i<n;i++)if(V[i]||W[i])ok&=vis[i];
		memset(g,false,sizeof(g)),memset(vis,false,sizeof(vis));
		if(!ok){puts("-1");continue;}
		ll sum=0;
		for(int i=1;i<N;i++)sum+=V[i]+W[i];
		printf("%lld\n",sum);
	}
	return 0;
}