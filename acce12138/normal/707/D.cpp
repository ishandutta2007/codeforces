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

struct query
{
	int tp,i,j,ans;
	void in()
	{
		get2(tp,i);
		if(tp<3)get1(j);
	}
}qry[100111];
int n,m,q,cur;
bool flip[1111],c[1111][1111];
int cnt[1111];
#define get(i,j) (flip[i]^(c[i][j]))
vector<int> g[100111];
void dfs(int x)
{
	bool change=0;
	if(qry[x].tp==1)
	{
		change=get(qry[x].i,qry[x].j)^1;
		if(change)
		{
			c[qry[x].i][qry[x].j]^=1;
			cur++;
			cnt[qry[x].i]++;
		}
	}
	else if(qry[x].tp==2)
	{
		change=get(qry[x].i,qry[x].j);
		if(change)
		{
			c[qry[x].i][qry[x].j]^=1;
			cur--;
			cnt[qry[x].i]--;
		}
	}
	else if(qry[x].tp==3)
	{
		flip[qry[x].i]^=1;
		cur+=m-cnt[qry[x].i]*2;
		cnt[qry[x].i]=m-cnt[qry[x].i];
	}
	qry[x].ans=cur;
	for(int i=0;i<(int)g[x].size();i++)
		dfs(g[x][i]);
	if(qry[x].tp==1)
	{
		if(change)
		{
			c[qry[x].i][qry[x].j]^=1;
			cur--;
			cnt[qry[x].i]--;
		}
	}
	else if(qry[x].tp==2)
	{
		if(change)
		{
			c[qry[x].i][qry[x].j]^=1;
			cur++;
			cnt[qry[x].i]++;
		}
	}
	else if(qry[x].tp==3)
	{
		flip[qry[x].i]^=1;
		cur+=m-cnt[qry[x].i]*2;
		cnt[qry[x].i]=m-cnt[qry[x].i];
	}
}
int main()
{
	qry[0].tp=0;
	get3(n,m,q);
	for(int i=1;i<=q;i++)
	{
		qry[i].in();
		if(qry[i].tp==4)g[qry[i].i].pb(i);
		else g[i-1].pb(i);
	}
	dfs(0);
	for(int i=1;i<=q;i++)printendl(qry[i].ans);
	return 0;
}