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

vector<int> g[100111];
int n,m,s,pre[100111][2];
bool ok[100111][2],use[100111],inst[100111];
bool cycle(int x,int d=1)
{
	use[x]=inst[x]=1;
	for(auto v:g[x])
	{
		if(!use[v]&&cycle(v,d))return true;
		else if(inst[v])return true;
	}
	inst[x]=0;
	return false;
}
void dfs(int x,int t)
{
	ok[x][t]=1;
	for(auto v:g[x])if(!ok[v][t^1])
	{
		pre[v][t^1]=x;
		dfs(v,t^1);
	}
}
int main()
{
	get2(n,m);
	for(int i=1;i<=n;i++)
	{
		int c,x;get1(c);
		while(c--)
		{
			get1(x);
			g[i].pb(x);
		}
	}
	get1(s);
	dfs(s,0);
	for(int i=1;i<=n;i++)if(ok[i][1]&&(int)g[i].size()==0)
	{
		puts("Win");vector<int>v;int t1=i,t2=1;
		while(t1!=s||t2)
		{
			v.pb(t1);
			t1=pre[t1][t2];
			t2^=1;
		}
		v.pb(s);reverse(v.begin(),v.end());
		for(auto tv:v)printf("%d ",tv);
		return 0;
	}
	if(cycle(s))puts("Draw");
	else puts("Lose");
	return 0;
}