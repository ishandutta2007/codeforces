#include<bits/stdc++.h>
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((m)*(x-1)+(y))
#define R(n) (rnd()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using ll=long long;using db=double;using lb=long db;using ui=unsigned;using ull=unsigned ll;
using namespace std;const int N=20+5,M=pow(6,10)+5,K=2e3+5,mod=1e9+7,Mod=mod-1;const db eps=1e-5;const int INF=1e9+7;
int n,m,k,p,x,y,z,b1,b2,Po[N],A[N],B[N],C[N];db a1,a2,a3,Ts,Ans=-1e18,W1[N][N],W2[N][N];
db Q1(int x,int y){return max(0.0,min(x+a1,y+a3)-max(x-a1,y-a3));}
db Q2(int x,int y){return max(0.0,min(x+a2,y+a3)-max(x-a2,y-a3));}
void calc(int h,int &x,int &y,int &z){x=y=z=0;
	if(h==0) x=1,y=1;
	if(h==1) x=1,z=1;
	if(h==2) y=1,z=1;
	if(h==3) x=2;
	if(h==4) y=2;
	if(h==5) z=2;
}
void Solve(int a,int b,int c,db w){
	int i,j;if(n+m+k!=p*2){
		if(a^n){w+=a1*b1*2;for(j=1;j<=p;j++)w+=C[j]*W1[p+1][j]*b1;}
		if(b^m){w+=a2*b2*2;for(j=1;j<=p;j++)w+=C[j]*W2[p+1][j]*b2;}
		if(c^k){for(j=1;j<=p;j++)w+=A[j]*W1[j][p+1]*b1+B[j]*W2[j][p+1]*b2;}
	}Ans=max(Ans,w);
}
void dfs(int x,int a,int b,int c,db w){if(a>n||b>m||c>k) return;
	if(x==p+1) return Solve(a,b,c,w);db Wp=w;
	for(int i=0;i<6;i++){
		A[x]=B[x]=C[x]=0;calc(i,A[x],B[x],C[x]);w+=A[x]*a1*b1*2+A[x]*C[x]*b1*W1[x][x]+B[x]*a2*b2*2+B[x]*C[x]*b2*W2[x][x];
		for(int j=1;j<x;j++){
			int X=A[j],Y=B[j],Z=C[j];
			w+=b1*W1[x][j]*A[x]*Z+b1*W1[j][x]*X*C[x]+b2*W2[x][j]*B[x]*Z+b2*W2[j][x]*Y*C[x];
		}
		dfs(x+1,a+A[x],b+B[x],c+C[x],w);w=Wp;
	}
}
int main(){
//	freopen("1.in","r",stdin);
	int i,j,h,l;scanf("%d%d%d",&n,&m,&k);p=(n+m+k)/2;scanf("%lf%lf%lf%d%d",&a1,&a2,&a3,&b1,&b2);a1=sqrt(a1*a1-1);a2=sqrt(a2*a2-1);a3=sqrt(a3*a3-1);
	for(i=1;i<=p+1;i++) for(j=1;j<=p+1;j++) W1[i][j]=Q1(i,j),W2[i][j]=Q2(i,j);
/*	for(i=1;i<=p;i++){
		
		for(j=0;j<Po[i-1];j++) g[j]=f[j],f[j]=-1e18; 
		for(j=0;j<Po[i-1];j++){
			for(h=0;h<6;h++){
				Ts=g[j];int x,y,z;calc(h,x,y,z);
				for(l=1;l<i;l++) {
					int X=0,Y=0,Z=0;calc(j/Po[l-1]%6,X,Y,Z);
					Ts+=;
				}
				f[j+Po[i-1]*h]=max(f[j+Po[i-1]*h],Ts);
			}
		}
	}*/
	/*for(i=0;i<Po[p];i++){
		int T1=0,T2=0,T3=0;for(j=1;j<=p;j++){int x,y,z;calc(h,x,y,z);T1+=x;T2+=y;T3+=z;}
		if(T1>n||T2>m||T3>k) continue;Ts=f[i];
		if(n+m+k!=p*2){
			
		}Ans=max(Ans,Ts);
	}*/dfs(1,0,0,0,0);printf("%.10lf\n",Ans);
}