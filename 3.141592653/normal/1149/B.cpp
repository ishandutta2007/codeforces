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

int n,q;
char s[1111111];

int nxt[111111][28];

int dp[255][255][255];

void init()
{
	register int i,ii;
	for(i=1;i<=26;i++)nxt[n][i]=nxt[n+1][i]=n+1;
	for(i=n;i;i--)
	{
		int c0=s[i]-96;
		for(ii=1;ii<=26;ii++)nxt[i-1][ii]=nxt[i][ii];
		nxt[i-1][c0]=i;
	}
}
int lea,leb,lec;

int a[1111],b[1111],c[1111];

void emin(int&x,int y){x<y?0:x=y;}

void ins(int x,int y)
{
	register int i,ii;
	if(x==1)
	{
		a[++lea]=y;
		for(i=0;i<=leb;i++)
			for(ii=0;ii<=lec;ii++)
			{
				dp[lea][i][ii]=nxt[dp[lea-1][i][ii]][y];
				if(i)
				{
					emin(dp[lea][i][ii],nxt[dp[lea][i-1][ii]][b[i]]);
				}
				if(ii)
				{
					emin(dp[lea][i][ii],nxt[dp[lea][i][ii-1]][c[ii]]);
				}
			}
	}
	else if(x==2)
	{
		b[++leb]=y;
		for(i=0;i<=lea;i++)
			for(ii=0;ii<=lec;ii++)
			{
				dp[i][leb][ii]=nxt[dp[i][leb-1][ii]][y];
				if(i)
				{
					emin(dp[i][leb][ii],nxt[dp[i-1][leb][ii]][a[i]]);
				}
				if(ii)
				{
					emin(dp[i][leb][ii],nxt[dp[i][leb][ii-1]][c[ii]]);
				}
			}
	}
	else
	{
		c[++lec]=y;
		for(i=0;i<=lea;i++)
			for(ii=0;ii<=leb;ii++)
			{
				dp[i][ii][lec]=nxt[dp[i][ii][lec-1]][y];
				if(i)
				{
					emin(dp[i][ii][lec],nxt[dp[i-1][ii][lec]][a[i]]);
				}
				if(ii)
				{
					emin(dp[i][ii][lec],nxt[dp[i][ii-1][lec]][b[ii]]);
				}
			}
	}
}

void exec()
{
	//fprintf(stderr,"%d\n",sizeof dp>>20);
	scanf("%d%d%s",&n,&q,s+1);
	register int i;
	init();
	for(i=1;i<=q;i++)
	{
		char op[11],y[11];
		int x;
		scanf("%s%d",op,&x);
		if(*op=='+')
		{
			scanf("%s",y),ins(x,*y-96);
		}else
		{
			if(x==1)lea--;
			if(x==2)leb--;
			if(x==3)lec--; 
		}puts((dp[lea][leb][lec]<=n)?"YES":"NO");
	}
}
int main()
{
	int T=1;
//	scanf("%d",&T);
	for(;T--;)exec();
}