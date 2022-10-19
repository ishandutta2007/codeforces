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
#define N 500000
#define M (1<<N)
#define mod 1000000007
#define Mod 998244352
#define eps (1e-4)
#define U unsigned int
#define it iterator
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define d(x,y) (n*(x-1)+(y))
#define R(n) (rand()*rand()%(n)+1)
using namespace std;
int T,n,m,k,En[N+5],Bg[N+5],Ah,A1[N+5],A2[N+5],x,y,z,A3[N+5],A4[N+5],Bh,siz[N+5];
struct yyy{int to,z;};struct ljb{int head,h[N+5];yyy f[N+5<<1];I void add(int x,int y){f[++head]=(yyy){y,h[x]};h[x]=head;}}s;
I void dfs(int x,int LA){
	vector<int> C,D;yyy tmp;int i;for(i=s.h[x];i;i=tmp.z) tmp=s.f[i],tmp.to^LA&&(dfs(tmp.to,x),siz[tmp.to]<=1?(siz[x]++,C.push_back(tmp.to)):D.push_back(tmp.to),0);
	Bg[x]=En[x]=x;if(C.size()==1) En[x]=En[C[0]];else if(C.size()>=2){Bg[x]=En[C[0]];En[x]=En[C[1]];for(i=2;i<C.size();i++) A1[++Ah]=x,A2[Ah]=C[i],A3[Ah]=C[i],A4[Ah]=En[x],En[x]=En[C[i]];}
	for(i=0;i<D.size();i++) A1[++Ah]=x,A2[Ah]=D[i],A3[Ah]=Bg[D[i]],A4[Ah]=En[x],En[x]=En[D[i]];
}
int main(){
//	freopen("1.in","r",stdin);
	RI i;scanf("%d",&T);while(T--){
		Ah=0;for(i=1;i<=n;i++) siz[i]=s.h[i]=0;s.head=0;scanf("%d",&n);for(i=1;i<n;i++) scanf("%d%d",&x,&y),s.add(x,y),s.add(y,x);dfs(1,0);printf("%d\n",Ah);for(i=1;i<=Ah;i++) printf("%d %d %d %d\n",A1[i],A2[i],A3[i],A4[i]);
	}
}