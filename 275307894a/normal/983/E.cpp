#include<bits/stdc++.h>
#define I inline
#define ll long long
#define db double
#define lb long db
#define N (200000+5)
#define M (8000+5)
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
struct IO{
    static const int S=1<<21;
    char buf[S],*p1,*p2;int st[105],Top;
    ~IO(){clear();}
    inline void clear(){fwrite(buf,1,Top,stdout);Top=0;}
    inline void pc(const char c){Top==S&&(clear(),0);buf[Top++]=c;}
    inline char gc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
    inline IO&operator >> (char&x){while(x=gc(),x==' '||x=='\n'||x=='\r');return *this;}
    template<typename T>inline IO&operator >> (T&x){
        x=0;bool f=0;char ch=gc();
        while(ch<'0'||ch>'9'){if(ch=='-') f^=1;ch=gc();}
        while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=gc();
        f?x=-x:0;return *this;
    }
    inline IO&operator << (const char c){pc(c);return *this;}
    template<typename T>inline IO&operator << (T x){
        if(x<0) pc('-'),x=-x;
        do{st[++st[0]]=x%10,x/=10;}while(x);
        while(st[0]) pc('0'+st[st[0]--]);return *this;
    }
}fin,fout;
using namespace std;vector<int> S[N],Q[N];
int n,m,k,x,y,z,fa[N][20],d[N],W[N],P[N][20],lg[N],X[N],Y[N],Bg[N],En[N],Bh,Ans[N],Ls;
I void Make(int x,int La){d[x]=d[La]+1;Bg[x]=++Bh;fa[x][0]=La;W[x]=x;for(int i=1;fa[x][i-1];i++) fa[x][i]=fa[fa[x][i-1]][i-1];for(int i:S[x]) Make(i,x);En[x]=Bh;}
I int LCA(int x,int y){d[x]<d[y]&&(swap(x,y),0);while(d[x]^d[y]) x=fa[x][lg[d[x]-d[y]]];if(x==y) return x;for(int i=19;~i;i--) fa[x][i]^fa[y][i]&&(x=fa[x][i],y=fa[y][i]);return fa[x][0]; }
namespace Tree{int F[N];I void add(int x){while(x<=n) F[x]++,x+=x&-x;}I int Qry(int x){ll Ans=0;while(x) Ans+=F[x],x-=x&-x;return Ans;}}
struct Ques{int x,id;};vector<Ques> G[N];I void GA(int x){vector<int> Ts;Ts.clear();for(Ques d:G[x]) Ts.PB(Tree::Qry(En[d.x])-Tree::Qry(Bg[d.x]-1));for(int i:Q[x]) Tree::add(Bg[i]);for(int i:S[x]) GA(i);for(int i=0;i<G[x].size();i++) Ans[G[x][i].id]+=(Ts[i]==Tree::Qry(En[G[x][i].x])-Tree::Qry(Bg[G[x][i].x]-1));}
int main(){
///////	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	int i,j;fin>>n;for(i=2;i<=n;i++) fin>>x,S[x].PB(i),lg[i]=lg[i/2]+1;Make(1,0);fin>>m;while(m--)fin>>x>>y,Q[x].PB(y),Q[y].PB(x),Ls=LCA(x,y),d[Ls]<d[W[x]]&&(W[x]=Ls),d[Ls]<d[W[y]]&&(W[y]=Ls);
	for(i=n;i>1;i--) d[W[fa[i][0]]]>d[W[i]]&&(W[fa[i][0]]=W[i]);for(i=1;i<=n;i++) for(P[i][0]=W[i],j=1;j<=lg[d[i]];j++) P[i][j]=P[P[i][j-1]][j-1];
	fin>>k;for(i=1;i<=k;i++){
		fin>>x>>y;d[x]>d[y]&&(swap(x,y),0);if(Bg[x]<=Bg[y]&&En[x]>=En[y]) {for(int j=19;~j;j--) d[W[P[y][j]]]>d[x]&&(y=P[y][j],Ans[i]+=(1<<j));
		d[W[y]]>d[x]&&(y=W[y],Ans[i]++);if(d[W[y]]>d[x]) Ans[i]=-1;else Ans[i]++;}
		else{
			int Ls=LCA(x,y);for(int j=19;~j;j--) d[W[P[x][j]]]>d[Ls]&&(x=P[x][j],Ans[i]+=(1<<j));for(int j=19;~j;j--) d[W[P[y][j]]]>d[Ls]&&(y=P[y][j],Ans[i]+=(1<<j));
			d[W[x]]>d[Ls]&&(x=W[x],Ans[i]++);d[W[y]]>d[Ls]&&(y=W[y],Ans[i]++);if(d[W[y]]>d[Ls]||d[W[x]]>d[Ls]) Ans[i]=-1;else Ans[i]++,G[x].PB((Ques){y,i});
		}
	}GA(1);for(i=1;i<=k;i++) fout<<Ans[i]<<'\n';
}