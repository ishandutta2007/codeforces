#include<cstdio>
#define mod 1000000007
using namespace std;
int n,m,k,x,y,z,a[3039][3039];
long long f[3039][3039],ans;
char _s;
inline long long find(int x,int y,int l,int r){
	register int i,j;
	if(a[x][y])return 0;f[x][y]=1;
	for(i=x;i<=l;i++){
		for(j=y;j<=r;j++)if(!a[i][j])f[i][j]=(f[i][j]+f[i-1][j]+f[i][j-1])%mod; 
	}
	ans=f[l][r];
	for(i=x;i<=l;i++){
		for(j=y;j<=r;j++)f[i][j]=0;
	}
	return ans;
}
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			_s=getchar();
			while(_s!='.'&&_s!='#') _s=getchar();
			a[i][j]=(_s=='.'?0:1);
		}
	}
	printf("%lld\n",(find(1,2,n-1,m)*find(2,1,n,m-1)%mod-find(1,2,n,m-1)*find(2,1,n-1,m)%mod+mod)%mod);
}