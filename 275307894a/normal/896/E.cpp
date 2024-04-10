#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (1000000+5)
#define M (100000+5)
#define K (2500+5)
#define mod 998244353
#define Mod (mod-1)
#define eps (1e-9)
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
using namespace std;
int Fr,En,L,R,n,m,k,x,y,z,Ps,fa[M],Ans[N],op[N],X[N],Y[N],Z[N],Si[M],A[N];
I int GF(int x){return fa[x]^x?fa[x]=GF(fa[x]):x;}
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
int main(){
//	freopen("1.in","r",stdin);
	int i,j,h;fin>>n>>m;k=max(sqrt(n)*2,1);for(i=1;i<=n;i++) fin>>A[i];for(i=1;i<=m;i++) fin>>op[i]>>X[i]>>Y[i]>>Z[i];
	for(i=0;i<=n/k;i++){Fr=max(1,i*k),En=min(n,i*k+k-1);
		L=R=1;Ps=0;Me(Si,0);for(j=Fr;j<=En;j++) R=max(R,A[j]),Si[A[j]]++;for(j=L;j<=R;j++) fa[j]=j;for(j=1;j<=m;j++){
			if(Y[j]<Fr||X[j]>En) continue;if(op[j]^2){if(Z[j]+Ps>R) continue;
				if(X[j]>=Fr&&Y[j]<=En) {for(h=X[j];h<=Y[j];h++) GF(A[h])-Ps>Z[j]&&(Si[GF(A[h])]--,A[h]-=Z[j],Si[GF(A[h])]++);continue;}
				if(Y[j]>=Fr&&Y[j]<=En) {for(h=Fr;h<=Y[j];h++) GF(A[h])-Ps>Z[j]&&(Si[GF(A[h])]--,A[h]-=Z[j],Si[GF(A[h])]++);continue;}
				if(X[j]>=Fr&&X[j]<=En) {for(h=X[j];h<=En;h++) GF(A[h])-Ps>Z[j]&&(Si[GF(A[h])]--,A[h]-=Z[j],Si[GF(A[h])]++);continue;}
				if(Z[j]*2<R-Ps) {for(h=L;h<L+Z[j];h++) Si[h+Z[j]]+=Si[h],fa[h]=h+Z[j],Si[h]=0;L+=Z[j];Ps+=Z[j];}
				else{for(h=R;h>Z[j]+Ps;h--) Si[h-Z[j]]+=Si[h],fa[h]=h-Z[j],Si[h]=0;while(R&&!Si[R]) R--;}
			}else{
				if(X[j]>=Fr&&Y[j]<=En) {for(h=X[j];h<=Y[j];h++) GF(A[h])-Ps==Z[j]&&(Ans[j]++);continue;}
				if(X[j]>=Fr&&X[j]<=En) {for(h=X[j];h<=En;h++) GF(A[h])-Ps==Z[j]&&(Ans[j]++);continue;}
				if(Y[j]>=Fr&&Y[j]<=En) {for(h=Fr;h<=Y[j];h++) GF(A[h])-Ps==Z[j]&&(Ans[j]++);continue;}if(Z[j]==0) Ans[j]+=Si[0];else Z[j]+Ps<=R&&(Ans[j]+=Si[Z[j]+Ps]);
			}
		}
	} for(i=1;i<=m;i++) op[i]^1&&(fout<<Ans[i]<<'\n',0);
}