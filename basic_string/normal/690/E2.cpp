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
int n,p[N],ip[N];
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
	for(j=0;j<m;++j)for(i=0;i<n;++i)if(j>>i&1){
		for(k=0;k<n;++k)if(!(j>>k&1))f[k][j|(1<<k)]=min(f[k][j|(1<<k)],f[i][j]+e[i][k]);
	}
	for(i=0,w=1e18;i<n;++i)w=min(w,f[i][m-1]);
	for(i=0;i<n;++i)if(w==f[i][m-1]){get(i,m-1,n-1);break;}
	for(i=0;i<n;++i)ip[p[i]]=i;
	for(i=0;i<n;++i)cout<<ip[i]+1<<' ';cout<<'\n';
}
}
enum{N=609};
int a[N][N];
int pf(int x){return x*x;}
int main(){
	memset(DP::e,9,sizeof DP::e);
	int T,n,m,o,o2,i,j,k,l;
	long long w,w1,w2,u,mn1,mx1,mn2,mx2;
	in(T);
	while(T--){
		in(n),in(m),in(o),o2=n/o;
		for(i=1;i<=n;++i)for(j=1;j<=m;++j)in(a[i][j]);	
		for(i=0;i<o;++i)for(j=0;j<o;++j)if(i!=j){
			w=0;
			for(k=1;k+9<=m;++k){
				w1=w2=0,mn1=mn2=1e9,mx1=mx2=-1e9;
				for(l=k;l<=k+9;++l){
					u=a[(i+1)*o2][l];
					mn1=min(mn1,u);
					mx1=max(mx1,u);
					w1+=u;
				}
				for(l=k;l<=k+9;++l){
					u=a[j*o2+1][l];
					mn2=min(mn2,u);
					mx2=max(mx2,u);
					w2+=u;
				}
				w+=pf((w1-mn1-mx1)-(w2-mn2-mx2));
			}
			DP::e[i][j]=w;
		}
		DP::n=o,DP::work();
	}
	return 0;
}