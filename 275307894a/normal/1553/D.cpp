#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 100000
#define M 200000
#define W (1<<20)
#define mod 998244353
#define eps (1e-5)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
using namespace std;
int T,n,m,r,las,flag;char s1[N+5],s2[N+5];
I void solve(){
	re int i;scanf("%s%s",s1+1,s2+1);n=strlen(s1+1);m=strlen(s2+1);r=1;las=0;flag=0;
	for(i=1;i<=m;i++){
		while(r<=n&&(s1[r]^s2[i]||((r-las)%2==0))) r++;
		if(r==n+1)break;las=r;r+=(i!=m);
	}flag|=(r!=n+1&&(n-r+1)&1);
	r=las=1;for(i=1;i<=m;i++){
		while(r<=n&&(s1[r]^s2[i]||((r-las)%2==0))) r++;
		if(r==n+1)break;las=r;r+=(i!=m);
	}flag|=(r!=n+1&&(n-r+1)&1);
	puts(flag?"Yes":"No");
}
int main(){
// 	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) solve();
}