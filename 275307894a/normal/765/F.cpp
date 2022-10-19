#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 100000
#define K 700
#define W (1<<20)
#define mod 998244353
#define eps (1e-5)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))0.
using namespace std;
int n,k,m,x,y,r,A[N+5],B[N+5],Bh,C[N+5],Ch,D[N+5],Dh,G[N+5],F[N+5][K+5],fr[N+5],en[N+5],Fs[K+5][K+5],ToT[N+5],Ans;const ll Maxn=2e9;
I bool cmp(int x,int y){return A[x]<A[y];}
int main(){
// 	freopen("1.in","r",stdin);
	re int i,j,h;scanf("%d",&n);k=180;for(i=1;i<=n;i++) scanf("%d",&A[i]);for(i=0;i<=n/k;i++) fr[i]=max(1,i*k),en[i]=min(n,i*k+k-1);
	for(i=0;i<=n/k;i++){
		for(j=fr[i];j<=en[i];j++) G[j]=j;sort(G+fr[i],G+en[i]+1,cmp);for(ToT[i]=Maxn,j=fr[i];j<en[i];j++) ToT[i]=min(ToT[i],A[G[j+1]]-A[G[j]]);
	}
	for(i=0;i<=n/k;i++){
		for(j=fr[i];j<=en[i];j++) F[j][i]=Maxn;
		for(j=i+1;j<=n/k;j++){
			for(r=fr[j],h=fr[i];h<=en[i];h++){
				F[G[h]][j]=F[G[h]][j-1];while(r<=en[j]&&A[G[r]]<A[G[h]])r++;r^fr[j]&&(F[G[h]][j]=min(F[G[h]][j],A[G[h]]-A[G[r-1]]));r<=en[j]&&(F[G[h]][j]=min(F[G[h]][j],A[G[r]]-A[G[h]]));
			}
		}
		for(j=i-1;~j;j--){
			for(r=fr[j],h=fr[i];h<=en[i];h++){
				F[G[h]][j]=F[G[h]][j+1];while(r<=en[j]&&A[G[r]]<A[G[h]])r++;r^fr[j]&&(F[G[h]][j]=min(F[G[h]][j],A[G[h]]-A[G[r-1]]));r<=en[j]&&(F[G[h]][j]=min(F[G[h]][j],A[G[r]]-A[G[h]]));
			}
		}
	}
	for(i=0;i<=n/k;i++){
		i&&(Fs[i][i-1]=Maxn);for(j=i;j<=n/k;j++){
			Fs[i][j]=min(Fs[i][j-1],ToT[j]);for(h=fr[j];h<=en[j];h++) Fs[i][j]=min(Fs[i][j],F[h][i]);
		}
	}scanf("%d",&m);while(m--){
		scanf("%d%d",&x,&y);if(x/k==y/k){Bh=0;for(i=fr[x/k];i<=en[x/k];i++)G[i]>=x&&G[i]<=y&&(B[++Bh]=G[i]);Ans=Maxn;for(i=1;i<Bh;i++) Ans=min(Ans,A[B[i+1]]-A[B[i]]);printf("%d\n",Ans);continue;}
		Ans=Fs[x/k+1][y/k-1];for(i=x;i<=en[x/k];i++) Ans=min(Ans,F[i][y/k-1]);for(i=fr[y/k];i<=y;i++) Ans=min(Ans,F[i][x/k+1]);for(Bh=0,i=fr[x/k];i<=en[x/k];i++) G[i]>=x&&(B[++Bh]=G[i]);
		for(Ch=0,i=fr[y/k];i<=en[y/k];i++) G[i]<=y&&(C[++Ch]=G[i]);i=j=1;Dh=0;while(i<=Bh||j<=Ch)D[++Dh]=(j>Ch||(i<=Bh&&A[B[i]]<A[C[j]]))?B[i++]:C[j++];for(i=1;i<Dh;i++) Ans=min(Ans,A[D[i+1]]-A[D[i]]);printf("%d\n",Ans);
	}
}