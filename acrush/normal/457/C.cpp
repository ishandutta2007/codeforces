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
#include <cassert>
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

const int maxn=100000+16;

int n;
map<int,int> idx;
int a[maxn],b[maxn];
priority_queue<ipair> g[maxn];
vector<int> sg[maxn];
int sum[1<<20],cnt[1<<20];

int get_idx(int n)
{
	if (idx.find(n)!=idx.end()) return idx[n];
	int m=SIZE(idx);
	return idx[n]=m;
}

void update(int id,int s,int t,int key,int d)
{
	cnt[id]+=d;
	sum[id]+=d*key;
	if (s==t) return;
	int m=(s+t)/2;
	if (key<=m)
		update(id*2+1,s,m,key,d);
	else
		update(id*2+2,m+1,t,key,d);
}

int getsum(int id,int s,int t,int w)
{
	if (s==t) return s*min(cnt[id],w);
	if (w<=0 || sum[id]<=0) return 0;
	if (w>=cnt[id]) return sum[id];
	int m=(s+t)/2;
	int ret=getsum(id*2+1,s,m,w);
	if (w>cnt[id*2+1]) ret+=getsum(id*2+2,m+1,t,w-cnt[id*2+1]);
	return ret;
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	idx[0]=0;
	for (int i=0;i<n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		a[i]=get_idx(a[i]);
	}
	int m=SIZE(idx);
	int s=0;
	for (int i=0;i<n;i++)
		if (a[i]==0)
			s++;
		else
			g[a[i]].push(MP(-b[i],i));
	for (int i=1;i<m;i++)
		sg[SIZE(g[i])].push_back(i);
	memset(sum,0,sizeof(sum));
	memset(cnt,0,sizeof(cnt));
	for (int i=0;i<n;i++) if (a[i]>0) update(0,0,100000,b[i],1);
	int ret=2000000000;
	vector<int> pw;
	int base=0;
	for (int k=n;k>0;k--)
	{
		for (int i=0;i<SIZE(sg[k]);i++) pw.push_back(sg[k][i]);
		for (int i=0;i<SIZE(pw);i++)
		{
			int z=pw[i];
			assert(SIZE(g[z])==k);
			int top=g[z].top().second;
			g[z].pop();
			base+=b[top];
			s++;
			update(0,0,100000,b[top],-1);
		}
		int additional=0;
		if (s<k) additional=getsum(0,0,100000,k-s);
		checkmin(ret,base+additional);
	}
	printf("%d\n",ret);
	return 0;
}