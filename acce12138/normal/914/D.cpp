// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

int g[2100111],a[500111];
#define ls (t<<1)
#define rs ((t<<1)|1)
void build(int l,int r,int t)
{
	if(l==r){g[t]=a[l];return;}
	int mid=(l+r)>>1;
	build(l,mid,ls);
	build(mid+1,r,rs);
	g[t]=__gcd(g[ls],g[rs]);
}
void modify(int p,int v,int l,int r,int t)
{
	if(l==r){g[t]=v;return;}
	int mid=(l+r)>>1;
	if(p<=mid)modify(p,v,l,mid,ls);
	else modify(p,v,mid+1,r,rs);
	g[t]=__gcd(g[ls],g[rs]);
}
int query(int ql,int qr,int v,int l,int r,int t)
{
	if(g[t]%v==0)return 0;
	if(l==r)return 1;
	int mid=(l+r)>>1,ret=0;
	if(ql<=mid)ret+=query(ql,qr,v,l,mid,ls);
	if(ret>=2)return ret;
	if(qr>mid)ret+=query(ql,qr,v,mid+1,r,rs);
	return ret;
}
void debug(int l,int r,int t)
{
	printf("t= %d l= %d r= %d gcd= %d\n",t,l,r,g[t]);
	if(l==r)return;
	int mid=(l+r)>>1;
	debug(l,mid,ls);
	
	debug(mid+1,r,rs);
}

int n,q;
int main()
{
	get1(n);
	for(int i=1;i<=n;i++)get1(a[i]);
	build(1,n,1);
	get1(q);
	for(int i=1,tp,x,y,v;i<=q;i++)
	{
		get1(tp);
		if(tp==1)
		{
			get3(x,y,v);
			puts(query(x,y,v,1,n,1)<=1?"YES":"NO");
		}
		else
		{
			get2(x,v);
			modify(x,v,1,n,1);
		}
	}
	return 0;
}