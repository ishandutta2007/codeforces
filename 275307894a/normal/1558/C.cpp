#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define lb long db
#define N 4000
#define K 20
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
using namespace std;
int T,Ans[N*5+5],Ah,n,B[N+5],p1,p2;
I int find(int x){for(int i=1;i<=n;i++) if(B[i]==x)return i;}I void Make(int x){Ans[++Ah]=x;for(int i=1;i<=x/2;i++) swap(B[i],B[x-i+1]);}
I void Solve(){
	re int i,j;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d",&B[i]);Ah=0;
	for(i=1;i<=n;i+=2) if(B[i]%2==0){printf("-1\n");return;}for(i=2;i<=n;i+=2) if(B[i]%2==1) {printf("-1\n");return;}
	for(i=n;i>1;i-=2){
		p1=find(i);Make(p1);p2=find(i-1);Make(p2-1);
		Make(p2+1);Make(3);Make(i);
    }printf("%d\n",Ah);for(i=1;i<=Ah;i++)printf("%d ",Ans[i]);printf("\n");
}
int main(){
//	freopen("1.in","r",stdin);
	re int i;scanf("%d",&T);while(T--)Solve();
}