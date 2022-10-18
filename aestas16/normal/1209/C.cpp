#include <cstdio>
#include <algorithm>
 
#define reg register
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug(s) debug("In line %d,Function %s(): \
%s\n",__LINE__,__FUNCTION__,s)
#ifndef ONLINE_JUDGE
#define inline __inline__ __attribute__((always_inline))
#endif
 
namespace FastIO {
	#define Fread fread(B,1,1<<20,stdin)
	char B[1<<20],*S=B,*T=B,D[1<<25],*A=D-1;
	// inline char getc() {
		// return (S==T&&(T=(S=B)+Fread,S==T)?0:*S++);
	// }
	// #ifndef ONLINE_JUDGE
	#define getc getchar
	// #endif
	template<class T>inline void fr(reg T &a) {
		reg T s=0,w=1;reg char c=getc();
		while(c<'0'||c>'9') {if(c=='-')w=-1;c=getc();}
		while(c>='0'&&c<='9') s=s*10+c-'0',c=getc();
		a=w*s;
	}
	template<class T>inline T fr() {T a;fr(a);return a;}
	#define R() fr<int>()
	template<class T>inline void fw(reg T x) {
		static char C[20];static int F;
		while(C[++F]=48+x%10,x/=10);
		while(*++A=C[F],--F);
		// *++A='\n';
	}
	inline void putc(reg char x) {*++A=x;}
	inline int flush() {fwrite(D,1,A-D,stdout);return 0;}
};
using namespace FastIO;
 
char s[200010]; 
int a[200010],ans[200010];
int main() {
    reg int t=R();
    while(t--) {
    	reg int n=R(),f=1;scanf("%s",s);
    	for(reg int i=1;i<=n;i++) a[i]=s[i-1]-='0';
    	std::sort(a+1,a+n+1),a[n+1]=-1;
    	for(reg int i=1;i<=n;i++)
    		if(a[f]==s[i-1])f++,ans[i]=1;
    	for(reg int i=1;i<=n;i++)
    		if(a[f]==s[i-1])f++,ans[i]=2;
    	if(f<=n)putc('-');
    	else for(reg int i=1;i<=n;i++) fw(ans[i]);
    	putc('\n');
    }
    return flush();
}