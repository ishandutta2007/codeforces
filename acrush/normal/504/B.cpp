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

const int maxn=200000+16;

int n;
int a[maxn],b[maxn];
int s[maxn];

int getsum(int p)
{
	int r=0;
	for (;p>0;p&=(p-1)) r+=s[p];
	return r;
}
void updatesum(int p,int d)
{
	for (;p<=n;p=(p|(p-1))+1) s[p]+=d;
}
void solve(int a[])
{
	memset(s,0,sizeof(s));
	for (int i=1;i<=n;i++) updatesum(i,1);
	for (int i=0;i<n;i++) 
	{
		int p=getsum(a[i]);
		updatesum(a[i]+1,-1);
		a[i]=p;
	}
}
void solve2(int a[])
{
	memset(s,0,sizeof(s));
	for (int i=1;i<=n;i++) updatesum(i,1);
	for (int i=0;i<n;i++)
	{
		int p=a[i];
		int h=0,t=n+1;
		for (;h+1<t;)
		{
			int m=(h+t)/2;
			if (getsum(m)>p) t=m;
			else h=m;
		}
		a[i]=t-1;
		updatesum(t,-1);
	}
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n;i++) cin>>b[i];
	solve(a);
	solve(b);
	int c=0;
	for (int i=n-1;i>=0;i--)
	{
		c+=a[i]+b[i];
		a[i]=c%(n-i);
		c/=(n-i);
	}
	solve2(a);
	for (int i=0;i<n;i++)
	{
		cout<<a[i];
		if (i+1<n) cout<<" ";
	}
	cout<<endl;
	return 0;
}