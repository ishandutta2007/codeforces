#include<bits/stdc++.h>
typedef unsigned unt;
typedef long long ll;
typedef double db;
typedef unsigned long long ull;

namespace io
{
	const int N=1<<25;
	char buf[N],*t1=buf,*t2=buf;
	#ifdef StdIO
	#define getc() getchar()
	#else
	#define getc() t1==t2&&(t2=(t1=buf)+fread(buf,1,N,stdin),t1==t2)?EOF:*t1++
	#endif
	inline int read()
	{
		static int an,f;an=0,f=1;
		static char ch;ch=getc();
		while(ch<48||ch>57)ch=='-'?f=-1:0,ch=getc();
		while(ch>=48&&ch<=57)an=(an<<3)+(an<<1)+(ch^48),ch=getc();
		return an*f;
	}
	inline ll readll()
	{
		static ll an,f;an=0,f=1;
		static char ch;ch=getc();
		while(ch<48||ch>57)ch=='-'?f=-1:0,ch=getc();
		while(ch>=48&&ch<=57)an=(an<<3)+(an<<1)+(ch^48),ch=getc();
		return an*f;
	}
	char buff[N],*T=buff;
	void flush(){fwrite(buff,1,T-buff,stdout);T=buff;}
	inline void putc(char ch){if(T==buff+N)flush();*T++=ch;}
	template<typename o>
	inline void print(o x)
	{
		if(x<0)putc('-'),x=-x;
		if(!x)return putc('0'),void();
		static int st[20],tp;
		while(x)st[++tp]=x%10,x/=10;
		while(tp)putc(st[tp]^48),--tp;
	}
}
using io::read;
using io::print;
using io::putc;
using io::flush;
using std::sort;
using std::swap;
using std::min;
using std::max;
using std::reverse;
using std::next_permutation;
using std::map;
using std::unordered_map;
using std::vector;
using std::set;
using std::multiset;
using std::deque;
using std::queue;

int n,a[1111111];

void exec()
{
	n=read();
	register int i;
	int c1=0,c2=0;
	for(i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i]==1)c1++;
		else c2++;
	}
	if(c1&&c2)
	{
		c1--,c2--;
		printf("2 1");
		for(i=1;i<=c2;i++)printf(" 2");
		for(i=1;i<=c1;i++)printf(" 1");
		puts("");
	}
	else
	{
		for(i=1;i<=n;i++)
			printf("%d ",a[i]);
		puts("");
	}
	
}
int main()
{
	int T=1;
//	scanf("%d",&T);
	for(;T--;)exec();
}