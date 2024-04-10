#include<bits/stdc++.h>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
#define db double
#define lb long db
#define N (2000000+5)
#define M (220+5)
#define K (12+5)
#define mod 1000000007
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
int T,Mx,n,m,R,Fl[N],Ans[N],Sf[N],Bh;char A[N];
I void Solve(){
	int i,j;Mx=1e9;scanf("%d%d",&n,&m);scanf("%s",A+1);for(i=1;i<=n*m;i++) A[i]-='0',A[i]&&(Mx=min(Mx,i));for(i=1;i<=m*n*2;i++) Ans[i]=Fl[i]=0;
	for(i=1;i<=m;i++) for(j=1;j<=n;j++) if(A[(j-1)*m+i]){Ans[(j-1)*m+i]++;break;}
	Bh=0;for(i=0;i<m;i++) Sf[i]=0;
	for(i=1;i<=n*m;i++){
		if(A[i]){
			for(j=i-1;j;j--) if(A[j]) break;
			if(i-j>=m||!j) Ans[i]++;else Sf[j%m]++,Sf[i%m]--;
		}
		Ans[i]+=Ans[i-1]+Sf[i%m]+(A[i]&&(i-j<m&&j));fout<<Ans[i]<<' ';
	}fout<<'\n';
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d",&T);while(T--) Solve();
}