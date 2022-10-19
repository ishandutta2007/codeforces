#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 300000
#define K 50
#define mod 1000000000
#define eps (1e-9)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
using namespace std;
int T,n,A[N+5],Ans,k,Id[N+5];I bool cmp(int x,int y){return A[x]<A[y];}
int main(){
//	freopen("1.in","r",stdin);
	re int i,j;scanf("%d",&T);while(T--){
		Ans=0;scanf("%d%d",&n,&k);for(i=1;i<=n;i++)scanf("%d",&A[i]),Id[i]=i;sort(Id+1,Id+n+1,cmp);for(i=2;i<=n;i++) Ans+=(Id[i]!=Id[i-1]+1);printf("%s\n",Ans+1<=k?"YES":"NO");
	}
}