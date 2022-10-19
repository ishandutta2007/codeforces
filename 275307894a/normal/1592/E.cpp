#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define RI re int
#define ll long long
#define db double
#define lb long db
#define N 1100000
#define M (N*N*4)
#define mod 1000000007
#define Mod (mod-1)
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) ((m+1)*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
using namespace std;
int n,m,r,A[N+5],B[N+5],Q[N+5],Qs[N+5],F[N+5][2],Ans,now,G[N+5];
I int count(int x){int cnt=0;while(x) cnt++,x>>=1;return cnt;}
int main(){
//	freopen("1.in","r",stdin);
	RI i,j,h;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&A[i]);Me(F,-1);
	for(i=0;i<=21;i++){
		for(j=1;j<=n;j++)Q[j]=Q[j-1]^(A[j]>>1);
		for(j=1;j<=n;j=r+1){
			if(!(A[j]&1)){r=j;continue;}for(r=j;r<=n;r++) if(!(A[r]&1)) break;r--;
			for(h=j-1;h<=r;h++) {
				if(~F[Q[h]][(h&1)])Ans=max(Ans,h-F[Q[h]][h&1]);
	    		else F[Q[h]][h&1]=h;
			}
			for(h=j-1;h<=r;h++) F[Q[h]][h&1]=-1;
		}
		for(j=1;j<=n;j++) A[j]>>=1;
	}printf("%d\n",Ans);
}