#include <cstdio>
#include <cctype>
#include <string>
#include <cstring>

#define debug(...) fprintf(stderr,__VA_ARGS__);
#define Debug if(DEBUG)
#define ll long long

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
            while(isspace(ch=getchar())) ;
            str=ch;
            while(!isspace(ch=getchar())) str+=ch;
            return *this;
        }
        IN& operator >> (char *str) {
            char ch; int tot=strlen(str);
            for(int i=0;i<tot;i++) str[i]=0;
            tot=0;
            while(isspace(ch=getchar())) ;
            str[tot++]=ch;
            while(!isspace(ch=getchar())) str[tot++]=ch;
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
    char endl='\n'; int DEBUG=0;
    template<class T>T sqr(T a) {return a*a;}
    template<class T>T abs(T a) {return a<0?-a:a;}
    template<class T>T cmin(T a,T b) {return a<b?a:b;}
    template<class T>T cmax(T a,T b) {return a>b?a:b;}
    template<class T>void cswp(T &a,T &b) {T t=a; a=b; b=t;}
}
using namespace Template;

const int N=1e5;

char x[N+10],y[N+10];

int main() {
    #ifndef ONLINE_JUDGE
    DEBUG=1;
    #endif
    int t; cin>>t;
    while(t--) {
        cin>>x>>y;
        int n=strlen(x),m=strlen(y),q=m-1,p;
        while(y[q]=='0') q--;
        q+=n-m,p=q;
        while(x[p]=='0') p--;
        cout<<q-p<<endl;
    }
    return 0;
}