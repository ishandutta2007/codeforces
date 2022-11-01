#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio> 
#include <iostream> 
#include <cmath> 
#include <string> 
#include <list> 
#include <vector> 
#include <algorithm> 
#include <functional> 
#include <utility> 
#include <set> 
#include <map> 
#include <complex> 
#include <queue> 
#include <stack> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 
#include <string.h> 
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std; 

typedef unsigned int uint; 
typedef long long int64; 
typedef unsigned long long uint64; 
typedef unsigned short ushort; 
typedef unsigned char uchar; 
typedef pair<int,int> ipair; 
typedef vector<int> VI; 
typedef vector<string> VS; 
typedef vector<double> VD; 
#define SIZE(A) ((int)(A.size()))
#define LENGTH(A) ((int)(A.length()))
#define MP(A,B) make_pair(A,B)
const double pi=acos(-1.0); 
const double eps=1e-11; 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(a) (a).begin(),(a).end()

template<class T> T sqr(const T &x) { return x*x; } 
template<class T> T lowbit(const T &x) { return (x^(x-1))&x; } 
template<class T> int countbit(const T &n) { return (n==0)?0:(1+countbit(n&(n-1))); } 
template<class T> void ckmin(T &a,const T &b) { if (b<a) a=b; } 
template<class T> void ckmax(T &a,const T &b) { if (b>a) a=b; } 

const int maxn=(1<<20);

int n;
int a[maxn];
int sa[maxn];
int l[maxn],h[maxn];

int simulate(int l1,int l2)
{
	int s=0;
	int src=min(l1,l2);
	int dst=max(l1,l2);
	int c=sa[src+1];
	for (int i=src+1;i<=dst;)
	{
		int d=a[i];
		int z=min(dst+1-i,l[i]);
		if (d==1 && i<=l1 || d==2 && i<=l2) 
			c+=d*z;
		else
		{
			int w=min(c,d*z*10);
			c-=w;
			s+=w; 
		}
		i+=z;
	}
	s+=min((sa[n]-sa[dst+1])*10,c);
	return sa[n]*10-s;
}
int solve()
{
	sa[0];
	REP(i,n) sa[i+1]=sa[i]+a[i];
	for (int i=n-1;i>=0;i--) l[i]=((i+1<n && a[i]==a[i+1])?l[i+1]+1:1);
	REP(i,n) h[i]=((i-1>=0 && a[i]==a[i-1])?h[i-1]+1:1);
	int ret=1000000000;
	for(int key=-1;key<n;key++) if (key<0 || a[key]==1)
	{
		set<int> wset;
		for (int c=max(0,key),step=0;c<n && step<5;step++,c+=l[c]) wset.insert(c);
		for (int c=min(n-1,key),step=0;step<5;step++,c-=h[c])
		{
			if (c<0)
			{
				int s=simulate(key,-1);
				ckmin(ret,s);
				break;
			}
			wset.insert(c); 
		}
		for (int src:wset)
		{
			if (a[src]!=2) continue;
			int low=src-h[src]+1;
			int high=src+l[src]-1;
			while (high-low>5)
			{
				int m1=(low*2+high)/3;
				int m2=(low+high*2)/3; 
				int s1=simulate(key,m1);
				int s2=simulate(key,m2);
				ckmin(ret,s1);
				ckmin(ret,s2);
				if (s1<s2) high=m2;
				else low=m1;
			}
			for (int other=low;other<=high;other++)
			{
				assert(a[other]==2);
				int s=simulate(key,other);
				ckmin(ret,s);
			}
		}
	}
	return ret;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	while (cin>>n) 
	{
		REP(i,n) { cin>>a[i]; a[i]/=1000; }
		int ret=solve();
		cout<<(int64)ret*100<<endl;
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}