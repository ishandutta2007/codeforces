#include<bits/stdc++.h>
using namespace std;
char _[999999],*U,*V;
#define I (U==V&&(V=(U=_)+fread(_,1,999991,stdin),U==V)?0:*U++)
template<class T>bool in(T&x){char c=I;bool f=0;for(x=0;c<48||c>57;c=I)if(c==45)f=1;else if(!c)return 0;for(;c>47&&c<58;c=I)x=x*10+c-48;if(f)x=-x;return 1;}
char O_[999999],*OU=O_,*OV=OU+999991,OS[21],*OT=OS;
#define F fwrite(O_,1,OU-O_,stdout)
#define O(x) (*(OU=(OU==OV?(F,O_):OU))++=(x))
template<class T>void out(T x){if(x<0)O(45),x=-x;for(;*OT++=x%10+48,x/=10;);for(;OT!=OS;O(*--OT));O(32);}
namespace DP{
const int N=19,M=65539;
int n,p[N];
long long f[N][M],e[N][N];
void get(int x,int y,int z){
	p[z]=x;
	if(!z)return;
	for(int i=0;i<n;++i)if(f[x][y]==f[i][y^(1<<x)]+e[i][x]){get(i,y^(1<<x),z-1);return;}
}
void work(){
	memset(f,9,sizeof f);
	int i,j,m=1<<n,k;
	long long w;
	for(i=0;i<n;++i)f[i][1<<i]=0;
	for(j=0;j<m;++j)for(i=0;i<n;++i)if(f[i][j]<1e15){
		for(k=0;k<n;++k)if(!(j>>k&1))f[k][j|(1<<k)]=min(f[k][j|(1<<k)],f[i][j]+e[i][k]);
	}
	for(i=0,w=1e18;i<n;++i)w=min(w,f[i][m-1]);
	for(i=0;i<n;++i)if(w==f[i][m-1]){get(i,m-1,n-1);break;}
	/*for(i=0;i<n;++i)out(p[i]+1);
	O(10);*/
	if(p[0]==0){O('N'),O('O');}else O('Y'),O('E'),O('S');
	O(10);
}
}
enum{N=609};
int a[N][N],*bg[19],*ed[19];
int main(){
	memset(DP::e,9,sizeof DP::e);
	int T,n,m,o,o2,i,j,k;
	long long w;
	in(T);
	while(T--){
		in(n),in(m),o=2,o2=n/o;
		//in(n),in(m),in(o),o2=n/o;
		for(i=1;i<=n;++i)for(j=1;j<=m;++j)in(a[i][j]);	
		for(i=0;i<o;++i)bg[i]=a[o2*i+1],ed[i]=a[o2*(i+1)];
		for(i=0;i<o;++i)for(j=0;j<o;++j)if(i!=j){
			w=0;
			for(k=1;k<=m;++k)w+=(ed[i][k]-bg[j][k])*(ed[i][k]-bg[j][k]);
			DP::e[i][j]=w;
		}
		DP::n=o,DP::work();
	}
	return F,0;
}