#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (200000+5)
#define M ((1<<20)+5)
#define K (200000+5)
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-9)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
using namespace std;
int n,m,k,col[N],x,y,Maxn;vector<int>  S[N];
struct Ques{int x,id;};I bool cmp(Ques x,Ques y){return x.x<y.x;}vector<Ques> X[N],Y[N];
I void dfs(int x,int w){if(col[x]) {if(col[x]^w) assert(0);return;}col[x]=w;for(int i:S[x]) dfs(i,-w);}
int main(){
	//freopen("1.in","r",stdin);
	int i,j;scanf("%d",&n);for(i=1;i<=n;i++) scanf("%d%d",&x,&y),Maxn=max(Maxn,max(x,y)),X[x].PB((Ques){y,i}),Y[y].PB((Ques){x,i});
	for(i=1;i<=Maxn;i++){
		sort(X[i].begin(),X[i].end(),cmp);for(j=1;j<X[i].size();j+=2) S[X[i][j].id].PB(X[i][j-1].id),S[X[i][j-1].id].PB(X[i][j].id);
		sort(Y[i].begin(),Y[i].end(),cmp);for(j=1;j<Y[i].size();j+=2) S[Y[i][j].id].PB(Y[i][j-1].id),S[Y[i][j-1].id].PB(Y[i][j].id);
	}for(i=1;i<=n;i++) !col[i]&&(dfs(i,1),0),putchar(~col[i]?'r':'b');
}