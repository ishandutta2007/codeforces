//  This code is written by Eric Sunli Chen ( OhWeOnFire ).
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <map>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T>
void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
}
template<typename T>
void print_int(T x)
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
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

int n,m;
struct BIT
{
	LL bit[2111][2111];
	void add(int xx,int yy,int v)
	{
		for(int x=xx;x<=n;x+=(x&-x))
			for(int y=yy;y<=m;y+=(y&-y))
				bit[x][y]+=v;
	}
	LL query(int xx,int yy)
	{
		LL ret=0;
		for(int x=xx;x>0;x-=(x&-x))
			for(int y=yy;y>0;y-=(y&-y))
				ret+=bit[x][y];
		return ret;
	}
	LL query(int x1,int y1,int x2,int y2)
	{
		return query(x2,y2)+query(x1-1,y1-1)-query(x1-1,y2)-query(x2,y1-1);
	}
}bit;
LL val[2111][2111];
vector<pair<pii,int> > gar[2111];
vector<int> he;
struct query
{
	int tp,x1,y1,x2,y2,i;
	void in()
	{
		char s[10];
		scanf("%s",s);
		if(s[0]=='S')
		{
			tp=1;
			get1(i);
		}
		else
		{
			tp=2;
			get2(x1,y1);get2(x2,y2);
		}
	}
}q[1000111];
int k;
bool cur[2111];
int main()
{
	get3(n,m,k);
	for(int i=1,l,x,y,w;i<=k;i++)
	{
		get1(l);
		while(l--)
		{
			get3(x,y,w);
			gar[i].pb(mp(mp(x,y),w));
		}
	}
	int Q;
	get1(Q);
	for(int i=1;i<=Q;i++)
	{
		q[i].in();
		if(q[i].tp==2){q[i].i=(int)he.size();he.pb(i);}
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<(int)gar[i].size();j++)
		{
			bit.add(gar[i][j].ff.ff,gar[i][j].ff.ss,gar[i][j].ss);
		}
		for(int j=0;j<(int)he.size();j++)
			val[i][j]=bit.query(q[he[j]].x1,q[he[j]].y1,q[he[j]].x2,q[he[j]].y2);
		for(int j=0;j<(int)gar[i].size();j++)
			bit.add(gar[i][j].ff.ff,gar[i][j].ff.ss,-gar[i][j].ss);
		cur[i]=1;
	}
	for(int i=1;i<=Q;i++)
	{
		if(q[i].tp==1)cur[q[i].i]^=1;
		else
		{
			LL ans=0;
			for(int j=1;j<=k;j++)
			{
				if(cur[j])
					ans+=val[j][q[i].i];
			}
			printendl(ans);
		}
	}
	return 0;
}