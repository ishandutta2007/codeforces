#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 200000
#define M 1000000
#define mod 998244353
#define eps (1e-5)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
using namespace std;
int n,T,Ans,m,Fl[N+5],x,y,op;set<int> F[N+5];
I void make(int x){Fl[x]=(F[x].lower_bound(x)==F[x].end());}
int main(){
//	freopen("1.in","r",stdin);
	re int i;scanf("%d%d",&n,&m);while(m--)scanf("%d%d",&x,&y),F[x].insert(y),F[y].insert(x);for(i=1;i<=n;i++) make(i),Ans+=Fl[i];
	scanf("%d",&m);while(m--){
		scanf("%d",&op);if(op==1) scanf("%d%d",&x,&y),Ans-=Fl[x]+Fl[y],F[x].insert(y),F[y].insert(x),make(x),make(y),Ans+=Fl[x]+Fl[y];
		else if(op==2) scanf("%d%d",&x,&y),Ans-=Fl[x]+Fl[y],F[x].erase(y),F[y].erase(x),make(x),make(y),Ans+=Fl[x]+Fl[y];else printf("%d\n",Ans);
	}
}