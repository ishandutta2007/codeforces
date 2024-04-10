#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (200000+5)
#define M (220+5)
#define K (12+5)
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-9)
#define ull unsigned ll
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
int n,m,k,x,y,A[N],L[N],R[N],st[N],H,Pl[N];ll Ans[N<<3];
struct Ques{int x,y,op;};vector<Ques> P[N],Q[N];
namespace Tree{
	#define ls now<<1
	#define rs now<<1|1
	ll F[N<<3];int G[N<<3],Fl[N<<3],Fs[N<<3],S[N<<3],Si[N<<3];I void Up(int now){S[now]=(G[now]?Si[now]:S[ls]+S[rs]);}
	I void BD(int l=1,int r=n,int now=1){Si[now]=r-l+1;if(l==r) return;int m=l+r>>1;BD(l,m,ls);BD(m+1,r,rs);}
	I void PS(int now,int w){Fs[now]+=w;F[now]+=1ll*w*Si[now];}I void PF(int now,int w){G[now]?(PS(now,w),0):(F[now]+=w*S[now],Fl[now]+=w);}I void P(int now){Fs[now]&&(PS(ls,Fs[now]),PS(rs,Fs[now]),Fs[now]=0);Fl[now]&&(PF(ls,Fl[now]),PF(rs,Fl[now]),Fl[now]=0);}
	I void Ins(int x,int y,int w,int l=1,int r=n,int now=1){if(x<=l&&r<=y){G[now]+=w;Up(now);return;}int m=l+r>>1;P(now);x<=m&&(Ins(x,y,w,l,m,ls),0);y>m&&(Ins(x,y,w,m+1,r,rs),0);Up(now);}
	I ll Qry(int x,int y,int l=1,int r=n,int now=1){if(x<=l&&r<=y) return F[now];int m=l+r>>1;ll Fs=0;P(now);x<=m&&(Fs+=Qry(x,y,l,m,ls));y>m&&(Fs+=Qry(x,y,m+1,r,rs));return Fs;}
	#undef ls
	#undef rs
}
int main(){
//	freopen("1.in","r",stdin);
	int i,j;fin>>n>>m;for(i=1;i<=n;i++) fin>>A[i],Pl[A[i]]=i,R[i]=n+1;Tree::BD();
	for(i=1;i<=n;i++) {while(H&&A[st[H]]<A[i]) R[st[H]]=i,H--;L[i]=st[H];st[++H]=i;}
	for(i=1;i<=n;i++) for(j=i+1;1ll*i*j<=n;j++) min(Pl[i],Pl[j])>L[Pl[i*j]]&&max(Pl[i],Pl[j])<R[Pl[i*j]]&&(/*cerr<<L[Pl[i*j]]<<' '<<min(Pl[i],Pl[j])<<' '<<max(Pl[i],Pl[j])<<' '<<R[Pl[i*j]]<<'\n',*/P[max(max(Pl[i],Pl[j]),Pl[i*j])].PB((Ques){L[Pl[i*j]]+1,min(min(Pl[i],Pl[j]),Pl[i*j]),1}),P[R[Pl[i*j]]].PB((Ques){L[Pl[i*j]]+1,min(min(Pl[i],Pl[j]),Pl[i*j]),-1}),0);
	for(i=1;i<=m;i++) fin>>x>>y,Q[y].PB((Ques){x,y,i});for(i=1;i<=n;i++) {for(Ques d:P[i]) Tree::Ins(d.x,d.y,d.op);Tree::PF(1,1);for(Ques d:Q[i]) Ans[d.op]=Tree::Qry(d.x,d.y);}for(i=1;i<=m;i++) fout<<Ans[i]<<'\n';
}