#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 600000
#define M 200000
#define W (1<<20)
#define mod 998244353
#define eps (1e-5)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
using namespace std;
int n,m,T,A[N+5],pl[N+5],F[N+5],cnt,Ans[N+5],fa[N+5],ToT,un,wn;
I int Getfa(int x){return x==fa[x]?x:fa[x]=Getfa(fa[x]);}
I void merge(int x,int y){
	un=Getfa(x);wn=Getfa(y);un^wn&&(fa[un]=wn,ToT--);
}
I void Solve(){
	re int i,j;for(i=0;i<=2*n;i++) F[i]=0;cnt=0;scanf("%d%d",&n,&m);for(i=1;i<=n;i++) scanf("%d",&A[i]),pl[A[i]]=i;
	for(i=1;i<=n;i++) pl[i+n]=pl[i];for(i=1;i<=n*2;i++) i>=pl[i]&&(F[i-pl[i]]++);
	for(i=0;i<n;i++){
		if(F[i]<n-2*m) continue;for(j=1;j<=n;j++) fa[j]=j;ToT=n;for(j=i+1;j<=i+n;j++) merge(j-i,pl[j]);
		n-ToT<=m&&(Ans[++cnt]=(n-i)%n);
	}sort(Ans+1,Ans+cnt+1);printf("%d ",cnt);for(i=1;i<=cnt;i++) printf("%d ",Ans[i]);puts("");
}
int main(){
// 	freopen("1.in","r",stdin);
	re int i;scanf("%d",&T);while(T--) Solve();
}