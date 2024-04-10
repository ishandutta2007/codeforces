#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
 
using namespace std;
 
typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) ((S&two(X))>0)
#define containL(S,X) ((S&twoL(X))>0)
typedef pair<int,int> ipair;
int countbit(int n) {return (n==0)?0:(1+countbit(n&(n-1)));}
int lowbit(int n) {return (n^(n-1))&n;}
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> T sqr(T x) {return x*x;}
template<class T> void checkmin(T &a,T b) {if (b<a) a=b;}
template<class T> void checkmax(T &a,T b) {if (b>a) a=b;}
#define SIZE(X) ((int)((X).size()))
#define LENGTH(X) ((int)((X).length()))
#define MP(A,B) make_pair(A,B)

const int64 oo=100000000LL*100000000LL;
const int maxn=200000+5;
const int maxsize=2<<20;

int n,m,c[maxn];
pair<ipair,int> d[maxn];
int64 delta[maxsize],best[maxsize];

void update(int v)
{
	if (delta[v]==0) return;
	int64 d=delta[v];
	delta[v*2+1]+=d;
	best[v*2+1]+=d;
	delta[v*2+2]+=d;
	best[v*2+2]+=d;
	delta[v]=0;
}
void update1(int v,int s,int t,int gs,int gt,int64 d)
{
	if (s>=gs && t<=gt)
	{
		delta[v]+=d;
		best[v]+=d;
		return;
	}
	update(v);
	int m=s+(t-s)/2;
	if (m>=gs) update1(v*2+1,s,m,gs,gt,d);
	if (m<gt) update1(v*2+2,m+1,t,gs,gt,d);
	best[v]=max(best[v*2+1],best[v*2+2])+delta[v];
}
void update2(int v,int s,int t,int key,int64 d)
{
	if (s==t)
	{
		delta[v]=best[v]=d;
		return;
	}
	update(v);
	int m=s+(t-s)/2;
	if (key<=m) 
		update2(v*2+1,s,m,key,d);
	else
		update2(v*2+2,m+1,t,key,d);
	best[v]=max(best[v*2+1],best[v*2+2])+delta[v];
}
int64 query(int v,int s,int t,int gs,int gt)
{
	if (s>=gs && t<=gt) return best[v];
	update(v);
	int m=s+(t-s)/2;
	int64 ret=-oo;
	if (m>=gs) 
		checkmax(ret,query(v*2+1,s,m,gs,gt));
	if (m<gt) 
		checkmax(ret,query(v*2+2,m+1,t,gs,gt));
	return ret;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	for (int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		d[i]=MP(MP(b,a),c);
	}
	sort(d,d+m);
	memset(delta,0,sizeof(delta));
	memset(best,0,sizeof(best));
	update1(0,0,n,1,n,-oo);
	for (int k=0,i=1;i<=n;i++)
	{
		int64 key=query(0,0,n,0,i-1);
		update1(0,0,n,0,i-1,-c[i]);
		update2(0,0,n,i,key);
		for (;k<m && d[k].first.first==i;k++)
			update1(0,0,n,0,d[k].first.second-1,d[k].second);
	}
	int64 R=query(0,0,n,0,n);
	cout<<R<<endl;
	return 0;
}