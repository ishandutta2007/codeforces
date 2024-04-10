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

const int maxn=3200;
struct Bitset
{
	unsigned a[maxn];
	void reset(){memset(a,0,sizeof(a));}
	Bitset(){reset();}
	void flip(int x){a[x>>5]^=1u<<(x&31);}
	void set(int x){a[x>>5]|=1u<<(x&31);}
	void reset(int x){a[x>>5]&=~(1u<<(x&31));}
	int test(int x){return (a[x>>5]>>(x&31))&1;}
	Bitset operator ~()const
	{
		Bitset ret;
		for(int i=0;i<maxn;i++)ret.a[i]=~a[i];
		return ret;
	}
	Bitset operator &(const Bitset &b)const
	{
		Bitset ret;
		for(int i=0;i<maxn;i++)ret.a[i]=a[i]&b.a[i];
		return ret;
	}
	Bitset operator |(const Bitset &b)const
	{
		Bitset ret;
		for(int i=0;i<maxn;i++)ret.a[i]=a[i]|b.a[i];
		return ret;
	}
	Bitset operator ^(const Bitset &b)const
	{
		Bitset ret;
		for(int i=0;i<maxn;i++)ret.a[i]=a[i]^b.a[i];
		return ret;
	}
	Bitset operator <<(const int t)const
	{
		Bitset ret;
		unsigned last=0;
		int high=t>>5,low=t&31;
		for(int i=0;i+high<maxn;i++)
		{
			ret.a[i+high]=last|(a[i]<<low);
			if(low)last=a[i]>>(32-low);
		}
		return ret;
	}
	Bitset operator >>(const int t)const
	{
		Bitset ret;
		unsigned last=0;
		int high=t>>5,low=t&31;
		for(int i=maxn-1;i>=high;i--)
		{
			ret.a[i-high]=last|(a[i]>>low);
			if(low)last=a[i]<<(32-low);
		}
		return ret;
	}
	int popcount()
	{
		int ret=0;
		for(int i=0;i<maxn;i++)ret+=__builtin_popcount(a[i]);
		return ret;
	}
	vector<int> ones()const
	{
		vector<int> ret;
		for(int i=0;i<maxn;i++)
		{
			unsigned tmp=a[i];
			while(tmp)
			{
				int t=__builtin_ctz(tmp);
				ret.pb(t|(i<<5));
				tmp^=1u<<t;
			}
		}
		return ret;
	}
};
Bitset occ[26],now,all;
char s[100111],t[100111];int n,q;

int main()
{
	scanf("%s",s);n=strlen(s);
	for(int i=0;i<n;i++)occ[s[i]-'a'].set(i);
	get1(q);
	for(int i=0;i<n;i++)all.set(i);
	for(int i=0,op,x,y;i<q;i++)
	{
		get1(op);
		if(op==1)
		{
			scanf("%d%s",&x,t);x--;
			occ[s[x]-'a'].reset(x);
			s[x]=t[0];
			occ[s[x]-'a'].set(x);
		}
		else
		{
			scanf("%d%d%s",&x,&y,t);int m=strlen(t);y=y-m+1;x--;y--;
			now=all;
			for(int j=0;j<m;j++)now=now&(occ[t[j]-'a']>>j);
//			vector<int> t=now.ones();for(auto v:t)printf("match at %d\n",v);
			now=(now>>x)<<x;
			now=(now<<(n-y-1))&all;
			printf("%d\n",now.popcount());
		}
	}
	return 0;
}