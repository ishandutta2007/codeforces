#include<bits/stdc++.h>
#include<iostream>
#define I inline
#define ll long long
#define db double
#define lb long db
#define N (100000+5)
#define M ((1<<16)+5)
#define K (1500+5)
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-5)
#define ull unsigned ll
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((k+1)*(x)+(y))
#define R(n) (1ll*rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;
int T,n,A[N],Ct,x,y,z,H,B[N],Bh;
I void Solve(){
	int i,j;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]);H=n;
	Ct=0;for(i=n;i>1;i--){
		y=0;x=Ct;Bh=0;for(j=1;j<H;j++) A[j]^A[j+1]?(B[++Bh]=A[j+1]-A[j]):(y++);if(x&&H) B[++Bh]=A[1];sort(B+1,B+Bh+1);Ct=max(Ct-1,0)+y;for(j=1;j<=Bh;j++) A[j]=B[j];H=Bh;
	}printf("%d\n",H?A[1]:0);
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}