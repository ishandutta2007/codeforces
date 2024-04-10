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
#define N (100000+5)
#define M 5000000
#define mod 1000000007
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
using namespace std;vector<int> S[N+5];
int n,m,op,x,P[N+5],D[N+5],Df[N+5],Bg[N+5],En[N+5],H;const int INF=-1e9;
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
namespace Tree{
	#define ls now<<1
	#define rs now<<1|1
	int F[N+5<<2],Fl[N+5<<2],Mx[N+5<<2],G[N+5<<2];I void PF(int x,int d){Fl[x]=1;F[x]=d;Mx[x]=INF;G[x]=0;}I void PX(int x,int d){Mx[x]=max(Mx[x],d+G[x]);}I void PG(int x,int d){G[x]+=d;}
	I void P(int now){Fl[now]&&(PF(ls,F[now]),PF(rs,F[now]),Fl[now]=F[now]=0);Mx[now]^INF&&(PX(ls,Mx[now]),PX(rs,Mx[now]),Mx[now]=INF);G[now]&&(PG(ls,G[now]),PG(rs,G[now]),G[now]=0);}
	I int Qry(int x,int l=0,int r=n,int now=1){if(l==r) return max(D[Df[l]]+F[now],Mx[now])-G[now];int m=l+r>>1;P(now);return x<=m?Qry(x,l,m,ls):Qry(x,m+1,r,rs);}
	I void IF(int x,int y,int z,int l=0,int r=n,int now=1){if(x<=l&&r<=y)return PF(now,z);int m=l+r>>1;P(now);x<=m&&(IF(x,y,z,l,m,ls),0);y>m&&(IF(x,y,z,m+1,r,rs),0);}
	I void IX(int x,int y,int z,int l=0,int r=n,int now=1){if(x<=l&&r<=y)return PX(now,z);int m=l+r>>1;P(now);x<=m&&(IX(x,y,z,l,m,ls),0);y>m&&(IX(x,y,z,m+1,r,rs),0);}
	I void IG(int x,int y,int z,int l=0,int r=n,int now=1){if(x<=l&&r<=y)return PG(now,z);int m=l+r>>1;P(now);x<=m&&(IG(x,y,z,l,m,ls),0);y>m&&(IG(x,y,z,m+1,r,rs),0);}
	#undef ls
	#undef rs
}
I void Make(int x,int La){Df[Bg[x]=++H]=x;D[x]=D[La]+1;for(RI i:S[x]) Make(i,x);En[x]=H;}
int main(){
//	freopen("1.in","r",stdin);
	RI i;fin>>n>>m;for(i=2;i<=n;i++) fin>>P[i],S[P[i]].PB(i);Make(1,0);Tree::IG(1,n,0);
	while(m--){fin>>op>>x;if(op==3) puts(Tree::Qry(Bg[x])^Tree::Qry(Bg[P[x]])?"white":"black");
		else if(op==1) Tree::IG(Bg[x],En[x],1),Tree::IX(Bg[x],En[x],Tree::Qry(Bg[P[x]]));else Tree::IF(Bg[x],En[x],Tree::Qry(Bg[P[x]])-D[P[x]]);
		//for(i=1;i<=n;i++) printf("%d ",Tree::Qry(Bg[i]));Pc('\n');
	}
}