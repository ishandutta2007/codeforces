#include <cstdio>
#include <cctype>
#include <string>
#include <algorithm>

#define debug(...) fprintf(stderr,__VA_ARGS__);
#define Debug if(DEBUG)

using std::vector;
using std::string;

namespace Template {
    struct IN {
        template<class T>void fr(T &a) {
            T s=0; int w=1; char ch=getchar();
            while(ch<'0'||ch>'9') {if(ch=='-') w=-1; ch=getchar();}
            while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
            a=w*s;
        }
        template<class T>T fr() {T a; fr(a); return a;}
        IN& operator >> (long long &x) {return fr(x),*this;}
        IN& operator >> (signed &x) {return fr(x),*this;}
        IN& operator >> (unsigned &x) {return fr(x),*this;}
        IN& operator >> (char &c) {
            while(isspace(c=getchar()));
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
            static char C[20];static int f;
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

const int N=2e5;

int n,a[N+10],a1[N+10];

int unique() {
	a1[0]=a[0];
	int ret=1;
	for(int i=1;i<n;i++)
		if(a[i]!=a[i-1])a1[ret]=a[i],ret++;
	return ret;
}

int search(int l,int r,int k) {
	int ret=l;
	while(l<=r) {
		int mid=(l+r)/2;
		if(a1[mid]>=k)r=mid-1;
		else ret=cmax(l,mid),l=mid+1;
		Debug printf("mid=%d\n",mid);
	}
	return ret;
}

int solve(int x) {
	int f=0,ret=0;
	for(int i=x*2;f<n-1;i+=x) f=search(f,n-1,i),ret=cmax(ret,a1[f]%x);
	return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
    DEBUG=1;
    #endif
    int ans=0; cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    std::sort(a,a+n),n=unique();
	for(int i=0;i<n-1;i++) ans=cmax(ans,solve(a1[i]));
    return cout<<ans<<endl,0;
}