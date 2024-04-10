#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)

const int maxn=100000+5;

int n;
int a[maxn],sa[maxn];
int w[1<<20];
int *x[1<<20];
int *y[1<<20];
int buffer_pos=0;
int buffer[50<<20];
int c1,c2;

int64 outer(int64 x0,int64 y0,int64 x1,int64 y1,int64 x2,int64 y2)
{
	return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);
}
void init(int id,int s,int t)
{
	if (s<t)
	{
		int m=(s+t)/2;
		init(id*2+1,s,m);
		init(id*2+2,m+1,t);
	}
	int size=(t-s+1);
	x[id]=buffer+buffer_pos;
	buffer_pos+=size+1;
	y[id]=buffer+buffer_pos;
	buffer_pos+=size+1;
	w[id]=size;
	for (int k=0;k<size;k++)
	{
		int i=s+k;
		x[id][k]=a[i];
		y[id][k]=a[i]*i-sa[i];
	}
	vector<ipair> q;
	for (int k=0;k<size;k++) q.push_back(MP(x[id][k],y[id][k]));
	sort(q.begin(),q.end());
	w[id]=0;
	for (int k=0;k<SIZE(q);k++) if (k==0 || q[k].first!=q[k-1].first)
	{
		for (;w[id]>=2 && outer(x[id][w[id]-2],y[id][w[id]-2],x[id][w[id]-1],y[id][w[id]-1],q[k].first,q[k].second)<=0;w[id]--);
		x[id][w[id]]=q[k].first;
		y[id][w[id]]=q[k].second;
		w[id]++;
	}
}
int solve(int id,int s,int t,int left,int right)
{
	if (s>=left && t<=right)
	{
		int ret=2100000000;
		int H=0,T=w[id];
		for (;T-H>4;)
		{
			int M1=H+(T-H)/3;
			int M2=T-(T-H)/3;
			int v1=x[id][M1]*c1+y[id][M1]+c2;
			int v2=x[id][M2]*c1+y[id][M2]+c2;
			if (v1<v2) T=M2;
			else H=M1;
		}
		for (int i=H;i<=T;i++) checkmin(ret,x[id][i]*c1+y[id][i]+c2);
		return ret;
	}
	int m=(s+t)/2;
	int ret=2100000000;
	if (m>=left) checkmin(ret,solve(id*2+1,s,m,left,right));
	if (m<right) checkmin(ret,solve(id*2+2,m+1,t,left,right));
	return ret;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	sa[0]=0;
	for (int i=0;i<n;i++) sa[i+1]=sa[i]+a[i];
	init(0,0,n-1);
	int m;
	for (scanf("%d",&m);m>0;m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		y--;
		c1=x-y-1;
		c2=sa[y+1];
		int ret=solve(0,0,n-1,y-x+1,y);
		printf("%d\n",ret);
	}
	return 0;
}