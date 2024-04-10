#include <cstdio>
#include <cctype>
#include <string>
#include <cmath>
#include <vector>

#define debug(...) fprintf(stderr,__VA_ARGS__);
#define Debug if(DEBUG)

using std::vector;
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

const int N=1e5;

int n,blo,tot=0,fa[N+10],len[N+10],arr[N+10];

vector<int>E[N+10];

void adde(int u,int v) {E[u].push_back(v);}



void dfs(int u,int f) {
    fa[u]=f,arr[++tot]=u;
    for(int v:E[u]) if(v!=f) dfs(v,u);
}

int calc(int k) {
    int ret=0;
    for(int i=1;i<=n;i++) len[i]=1;
    for(int i=n;i>1;i--) {
        int u=arr[i],f=fa[u];
        if(len[f]!=-1&&len[u]!=-1) {
            if(len[f]+len[u]>=k) ret++,len[f]=-1;
            else len[f]=cmax(len[f],len[u]+1);
        }
    }
    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
    DEBUG=1;
    #endif
    cin>>n; blo=sqrt(n*log2(n));
    for(int i=1;i<n;++i) {
        int u,v; cin>>u>>v;
        adde(u,v),adde(v,u);
    }
    dfs(1,0),cout<<n<<endl;
    for(int i=2;i<=blo;i++) cout<<calc(i)<<endl;
    for(int i=blo+1;i<=n;) {
        int f=calc(i),l=i,r=n,pos=0;
        while(l<=r) {
            int mid=(l+r)>>1;
            if(calc(mid)==f) l=mid+1,pos=mid;
            else r=mid-1;
        }
        for(;i<=pos;i++) cout<<f<<endl;
    }
    return 0;
}

// duliu RMJ