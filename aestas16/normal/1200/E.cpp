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

const int N=1e6;

char a[N+10],str[(N<<1)+10],ans[N+10];
int z[(N<<1)+10];

int main() {
    #ifndef ONLINE_JUDGE
    DEBUG=1;
    #endif
    int n,anslen=0; cin>>n;
    for(int i=1;i<=n;i++) {
        scanf("%s",a);
        int len=strlen(a),sz=cmin(len,anslen),siz=(sz<<1)+1;
        for(int j=0;j<sz;j++)
            str[j]=a[j],str[j+sz+1]=ans[anslen-sz+j];
        str[sz]='$',str[siz]=0;
        int l=0,r=0,len1=0;
        for(int j=1;j<siz;j++) {
            z[j]=0;
            if(j<r)z[j]=cmin(r-j,z[j-l]);
            while(str[z[j]]==str[j+z[j]]) z[j]++;
            if(j+z[j]>r)l=j,r=j+z[j];
        }
        for(int j=sz;j>=1;j--) if(z[siz-j]==j) {len1=j; break;}
        for(int j=len1;j<len;j++) ans[anslen++]=a[j];
    }
    return !printf("%s\n",ans);
}