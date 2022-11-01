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

const int M=60;
const int maxn=200000+16;
const int maxsize=1<<19;

int n;
int a[maxn];
int tree[maxsize][M];

void check1(int v,int d)
{
	for (int i=0;i<M;i++) tree[v][i]=1+(int)(i%d==0);
}
void check2(int v)
{
	int *p1=tree[v*2+1];
	int *p2=tree[v*2+2];
	int *p=tree[v];
	for (int i=0;i<M;i++) p[i]=p1[i]+p2[(i+p1[i])%M];
}
void init(int v,int s,int t)
{
	if (s==t) { check1(v,a[s]); return; }
	int m=(s+t)/2;
	init(v*2+1,s,m);
	init(v*2+2,m+1,t);
	check2(v);
}
void update(int v,int s,int t,int key)
{
	if (s==t) { check1(v,a[s]); return; }
	int m=(s+t)/2;
	if (key<=m)
		update(v*2+1,s,m,key);
	else
		update(v*2+2,m+1,t,key);
	check2(v);
}
void solve(int v,int s,int t,int low,int high,int &ret)
{
	if (s>high || t<low) return;
	if (s>=low && t<=high) { ret+=tree[v][ret%M]; return; }
	int m=(s+t)/2;
	solve(v*2+1,s,m,low,high,ret);
	solve(v*2+2,m+1,t,low,high,ret);
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	init(0,0,n-1);
	int m;
	for (scanf("%d",&m);m>0;m--)
	{
		char s[16];
		int x,y;
		scanf("%s%d%d",s,&x,&y);
		if (s[0]=='C')
		{
			x--;
			a[x]=y;
			update(0,0,n-1,x);
		}
		else
		{
			if (x>y) swap(x,y);
			x--;
			y--;
			int ret=0;
			if (x<y) solve(0,0,n-1,x,y-1,ret);
			printf("%d\n",ret);
		}
	}
	return 0;
}