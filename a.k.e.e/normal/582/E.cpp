#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=505,MAXV=70005,MOD=1000000007;
inline int dmy(int x){return x>=MOD?x-MOD:x;}

int n,m,b[MAXN],c[MAXN];
char a[MAXN];
int stot,f[MAXN][MAXV],lf[MAXV],rf[MAXV];
void fwt_or(int *b,int *a)
{
	for(int i=0;i<(1<<m);++i)a[i]=b[i];
	for(int d=1;d<(1<<m);d<<=1)
		for(int i=0;i<(1<<m);i+=(d<<1))
			for(int j=0;j<d;j++)
				a[i+j+d]=dmy(a[i+j]+a[i+j+d]);
}
void fwt_and(int *b,int *a)
{
	for(int i=0;i<(1<<m);++i)a[i]=b[i];
	for(int d=1;d<(1<<m);d<<=1)
		for(int i=0;i<(1<<m);i+=(d<<1))
			for(int j=0;j<d;j++)
				a[i+j]=dmy(a[i+j]+a[i+j+d]);
}
void ifwt_or(int *a)
{
	for(int d=1;d<(1<<m);d<<=1)
		for(int i=0;i<(1<<m);i+=(d<<1))
			for(int j=0;j<d;j++)
				a[i+j+d]=dmy(a[i+j+d]-a[i+j]+MOD);
}
void ifwt_and(int *a)
{
	for(int d=1;d<(1<<m);d<<=1)
		for(int i=0;i<(1<<m);i+=(d<<1))
			for(int j=0;j<d;j++)
				a[i+j]=dmy(a[i+j]-a[i+j+d]+MOD);
}
int solve(int l,int r)
{
	if(l==r)
	{
		int id=++stot;
		if(a[l]=='?')
		{
			for(int x=0;x<4;++x)
			{
				int y=0;
				for(int i=0;i<m;++i)
					if((b[i]>>x)&1)y|=(1<<i);
				++f[id][y];
				++f[id][y^((1<<m)-1)];
			}
		}
		else if(isupper(a[l]))
		{
			int x=a[l]-'A',y=0;
			for(int i=0;i<m;++i)
				if((b[i]>>x)&1)y|=(1<<i);
//cerr<<b[0]<<" "<<c[0]<<" "<<x<<" "<<y<<endl;
			f[id][y]=1;
		}
		else
		{
			int x=a[l]-'a',y=0;
			for(int i=0;i<m;++i)
				if(!((b[i]>>x)&1))y|=(1<<i);
			f[id][y]=1;
		}
		return id;
	}
	int cur=0,pos=0;
	for(int i=l;i<=r;++i)
		if(a[i]=='(')++cur;
		else if(a[i]==')')--cur;
		else if(!cur){pos=i;break;}
	if(!pos)return solve(l+1,r-1);
	int id=++stot,lch=solve(l,pos-1),rch=solve(pos+1,r);
	if(a[pos]!='&')
	{
		fwt_or(f[lch],lf),fwt_or(f[rch],rf);
		for(int i=0;i<(1<<m);++i)f[id][i]=(f[id][i]+1ll*lf[i]*rf[i])%MOD;
		ifwt_or(f[id]);
	}
	if(a[pos]!='|')
	{
		fwt_and(f[lch],lf),fwt_and(f[rch],rf);
		if(a[pos]=='?')fwt_and(f[id],f[id]);
		for(int i=0;i<(1<<m);++i)f[id][i]=(f[id][i]+1ll*lf[i]*rf[i])%MOD;
		ifwt_and(f[id]);
	}
	return id;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int all=0;
	scanf("%s",a+1);
	n=strlen(a+1);
	readint(m);
	for(int i=0;i<m;++i)
	{
		int x,y=0;
		for(int j=0;j<4;++j)
		{
			readint(x);
			if(x)y|=(1<<j);
		}
		b[i]=y;
		readint(c[i]);
		all|=(c[i]<<i);
	}
	int id=solve(1,n);
	printf("%d\n",f[id][all]);
	return 0;
}