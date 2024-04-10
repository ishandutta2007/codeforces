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
int n,m,k,T,A[N],Ans,Fl[N],Ct;
I void Solve(){
	int i,j;scanf("%d%d",&n,&m);Me(Fl,0);for(i=1;i<=n;i++) scanf("%d",&A[i]);k=0;for(i=n;i;i--){
		if(A[i]>k&&k<m) k++,Fl[i]=1;else if(A[i]<=k) Fl[i]=1;
	}for(i=1;i<=n;i++) Pc(Fl[i]+'0');Pc('\n');
}
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}