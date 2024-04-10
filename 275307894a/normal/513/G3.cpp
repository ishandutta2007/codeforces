#include<bits/stdc++.h>
#define I inline
#define ll long long
#define db double
#define lb long db
#define N (100+5)
#define M (500+5)
#define K (700+5)
#define mod 64123
#define Mod (mod-1)
#define eps (1e-5)
#define ui unsigned int
#define ull unsigned ll
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((k+1)*(x)+(y))
#define R(n) (rnd()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;
int n,k,p[N];db f[N][N],g[N][N],ToT;
int main(){
//	freopen("1.in","r",stdin);
	int i,j,h;scanf("%d%d",&n,&k);k=min(k,1000);for(i=1;i<=n;i++) scanf("%d",&p[i]);for(i=1;i<=n;i++) for(j=i+1;j<=n;j++) f[i][j]=(p[i]>p[j]);
	while(k--){
		Mc(g,f);Me(f,0);for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				f[i][j]=g[i][j]*(i*(i-1)/2+(n-j+1)*(n-j)/2+(j-i)*(j-i-1)/2);
				for(h=1;h<j;h++) f[i][j]+=g[h][j]*min(min(i,h),min(j-i,j-h));
				for(h=i+1;h<=n;h++) f[i][j]+=g[i][h]*min(min(j-i,h-i),min(n-j+1,n-h+1));
				for(h=1;h<=n-(j-i);h++) f[i][j]+=(1-g[h][h+(j-i)])*min(min(h,i),min(n-j+1,n-h-(j-i)+1));f[i][j]/=n*(n+1)/2;
			}
		}
	}for(i=1;i<=n;i++) for(j=i+1;j<=n;j++) ToT+=f[i][j];printf("%.9lf\n",ToT); 
}