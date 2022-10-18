#include <cstdio>
#include <cctype>
#include <string>
#include <cmath>

#define int long long
#define debug(...) fprintf(stderr,__VA_ARGS__);
#define Debug if(DEBUG)

using std::string;

namespace Template {
    struct IN {
        template<class T>void fr(T &a) {
            T s=0;int w=1;char ch=getchar();
            while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
            while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
            a=w*s;
        }
        template<class T>T fr() {T a;fr(a);return a;}
        IN& operator >> (long long &x) {return fr(x),*this;}
        IN& operator >> (signed &x) {return fr(x),*this;}
        IN& operator >> (unsigned &x) {return fr(x),*this;}
        IN& operator >> (char &c) {
            while(isspace(c=getchar()));
            return *this;
        }
        IN& operator >> (string &str) {
            char ch;
            while(isspace(ch=getchar()));str=ch;
            while(!isspace(ch=getchar())) str+=ch;
            return *this;
        }
    }cin;
    struct OUT {
        char D[1<<27],*A=D-1;
        ~OUT() {fwrite(D,1,A-D+1,stdout);}
        template<class T>void fw(T x) {
            static char C[20];static int f;
            x<0?*++A='-',x=-x:0;
            while(C[++f]=48+x%10,x/=10);
            while(*++A=C[f],--f);
        }
        OUT& operator << (char c) {return *++A=c,*this;}
        OUT& operator << (string str) {
            int len=str.length();
            for(int i=0;i<len;i++) *++A=str[i];
            return *this;
        }
        OUT& operator << (long long x) {return fw(x),*this;}
        OUT& operator << (signed x) {return fw(x),*this;}
        OUT& operator << (unsigned x) {return fw(x),*this;}
    }cout;
    char endl='\n';int DEBUG=0;
    template<class T>T sqr(T a) {return a*a;}
    template<class T>T abs(T a) {return a<0?-a:a;}
    template<class T>T cmin(T a,T b) {return a<b?a:b;}
    template<class T>T cmax(T a,T b) {return a>b?a:b;}
    template<class T>void cswp(T &a,T &b) {T t=a;a=b;b=t;}
}
using namespace Template;

const int N=1e5,SN=320;

namespace Block {
    int len,blo,A[N+10],id[N+10],sum[SN+10],Max[SN+10];
    void Init(int *a,int n) {
        len=n,blo=sqrt(n);
        for(int i=1;i<=n;i++)
            A[i]=a[i],id[i]=(i-1)/blo+1,sum[id[i]]+=a[i],Max[id[i]]=cmax(Max[id[i]],a[i]);
    }
    void Maintain(int f) {
        int l=(f-1)*blo+1,r=cmin(l+blo-1,len); Max[f]=0,sum[f]=0;
        for(int i=l;i<=r;i++) Max[f]=cmax(Max[f],A[i]),sum[f]+=A[i];
    }
    void Modify(int l,int x) {A[l]=x,Maintain(id[l]);}
    void Mod(int l,int r,int x) {
        if(id[l]==id[r]) {
            for(int i=l;i<=r;i++) A[i]%=x;
            return Maintain(id[l]);
        }
        for(int i=l;id[i]!=id[l]+1;i++) A[i]%=x;
        Maintain(id[l]);
        for(int i=r;id[i]!=id[r]-1;i--) A[i]%=x;
        Maintain(id[r]);
        for(int i=id[l]+1;i<id[r];i++) {
            if(Max[i]<x) continue;
            int L=(i-1)*blo+1,R=cmin(L+blo-1,len);
            for(int j=L;j<=R;j++) A[j]%=x;
            Maintain(i);
        }
    }
    int Qsum(int l,int r) {
        int ret=0;
        if(id[l]==id[r]) {
            for(int i=l;i<=r;i++) ret+=A[i];
            return ret;
        }
        for(int i=l;id[i]!=id[l]+1;i++) ret+=A[i];
        for(int i=r;id[i]!=id[r]-1;i--) ret+=A[i];
        for(int i=id[l]+1;i<id[r];i++) ret+=sum[i];
        return ret;
    }
    void Print() {
        puts("------------------------");
        for(int i=1;i<=len;i++) printf("%lld ",A[i]);
        puts("\n------------------------");
    }
}
using namespace Block;

int a[N+10];

signed main() {
    #ifndef ONLINE_JUDGE
    DEBUG=1;
    #endif
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    Init(a,n);
    while(m--) {
        int opt,l,r,x; cin>>opt>>l>>r;
        if(opt==1) cout<<Qsum(l,r)<<endl;
        else if(opt==2) cin>>x,Mod(l,r,x);
        else Modify(l,r);
        Debug Print();
    }
    return 0;
}