#include <cstdio>
#include <cctype>
#include <string>
#include <cstring>

#define debug(...) fprintf(stderr,__VA_ARGS__);
#define Debug if(DEBUG)

using std::string;

namespace Template {
    struct IN {
        template<class T>void fr(T &a) {
            T s=0; int w=1; char ch=getchar();
            while(ch<'0'||ch>'9') {if(ch=='-')w=-1; ch=getchar();}
            while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
            a=w*s;
        }
        template<class T>T fr() {T a; fr(a); return a;}
        IN& operator >> (long long &x) {return fr(x),*this;}
        IN& operator >> (signed &x) {return fr(x),*this;}
        IN& operator >> (unsigned &x) {return fr(x),*this;}
        IN& operator >> (char &c) {
            while(isspace(c=getchar())) ;
            return *this;
        }
        IN& operator >> (string &str) {
            char ch;
            while(isspace(ch=getchar())) ; str=ch;
            while(!isspace(ch=getchar())) str+=ch;
            return *this;
        }
    }cin;
    struct OUT {
        char D[1<<27],*A=D-1;
        ~OUT() {fwrite(D,1,A-D+1,stdout);}
        template<class T>void fw(T x) {
            static char C[20]; static int f;
            x<0?*++A='-',x=-x:0;
            while(C[++f]=48+x%10,x/=10) ;
            while(*++A=C[f],--f) ;
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
    template<class T>void cswp(T &a,T &b) {T t=a; a=b; b=t;}
}
using namespace Template;

const int N=1e3;

int cnt[N+10][300];

int main() {
    #ifndef ONLINE_JUDGE
    DEBUG=1;
    #endif
    int n,m,ans=0; cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {
            char c; cin>>c;
            cnt[j][c]++;
        }
    // for(int i=1;i<=m;i++,puts(""))
    //     for(int j='A';j<='E';j++) printf("%d ",cnt[i][j]);
    // for(int i='A';i<='E';i++)
    for(int i=1;i<=m;i++) {
        int Max=0,pts; cin>>pts;
        for(int j='A';j<='E';j++) Max=cmax(Max,cnt[i][j]);
        ans+=Max*pts;
    }
    return cout<<ans<<endl,0;
}