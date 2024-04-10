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

const int maxn=100000+5;

int n,m;
int father[maxn],cnt[maxn];
int f[maxn];
int a[maxn];

int getfather(int p)
{
	return (father[p]<0)?p:(father[p]=getfather(father[p]));
}

bool islucky(int n)
{
	if (n==0) return true;
	return (n%10==4 || n%10==7) && islucky(n/10);
}

void addf(int key,int cost)
{
	for (int i=n;i>=key;i--) if (f[i-key]+cost<f[i]) f[i]=f[i-key]+cost;
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) father[i]=-1,cnt[i]=1;
	for (int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--;
		b--;
		a=getfather(a);
		b=getfather(b);
		if (a==b) continue;
		if (cnt[a]>cnt[b]) swap(a,b);
		father[a]=b;
		cnt[b]+=cnt[a];
	}
	m=0;
	for (int i=0;i<n;i++) if (father[i]<0) a[m++]=cnt[i];
	sort(a,a+m);
	for (int i=0;i<=n;i++) f[i]=100000000;
	f[0]=0;
	for (int i=0;i<m;i++) if (i==0 || a[i]!=a[i-1])
	{
		int c=0;
		for (int j=i;j<m && a[i]==a[j];j++) c++;
		for (int p=1;c>0;p*=2)
		{
			int d=min(c,p);
			addf(d*a[i],d);
			c-=d;
		}
	}
	int R=100000000;
	for (int i=1;i<=n;i++) if (islucky(i)) checkmin(R,f[i]);
	if (R>=100000000) R=0;
	printf("%d\n",R-1);
	return 0;
}