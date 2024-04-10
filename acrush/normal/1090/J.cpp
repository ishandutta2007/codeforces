#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

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
#include <memory>
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
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void ckmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()

namespace SA
{

inline bool leq(int a1,int a2,int b1,int b2)
{
	return (a1<b1 || a1==b1 && a2<=b2);
}
inline bool leq(int a1,int a2,int a3,int b1,int b2,int b3)
{
	return (a1<b1 || a1==b1 && leq(a2,a3,b2,b3)); 
}

// 0<=a[i]<=K.
void radix_pass(int *a,int *b,int *r,int n,int K)
{
	auto cnt=make_unique<int[]>(K+1);
	memset(cnt.get(),0,(K+1)*sizeof(int));
	for (int i=0;i<n;i++) cnt[r[a[i]]]++;
	for (int i=1;i<=K;i++) cnt[i]+=cnt[i-1];
	for (int i=n-1;i>=0;i--) b[--cnt[r[a[i]]]]=a[i];
}

// Requires a[n]=a[n+1]=a[n+2]=0
// a[i]>0 && a[i]<=K
void get_suffix_array_internal(int *a,int *sa,int n,int K)
{
	if (n<=8)
	{
		bool c[8][8];
		for (int i=n-1;i>=0;i--) for (int j=i+1;j<n;j++)
		{
			if (a[i]==a[j]) c[i][j]=(j+1<n && c[i+1][j+1]);
			else c[i][j]=(a[i]<a[j]);
			c[j][i]=!c[i][j];
		}
		for (int i=0;i<n;i++) sa[i]=i;
		for (int i=0;i<n;i++) for (int j=i+1;j<n;j++) if (c[sa[j]][sa[i]]) swap(sa[i],sa[j]);
		return;
	}
	int n0=(n+2)/3,n1=(n+1)/3,n2=n/3,n02=n0+n2;
	auto buffer=make_unique<int[]>((n02+3+n0)*2);
	int* p_buffer=buffer.get();
	int *a12=p_buffer; p_buffer+=n02+3;
	a12[n02]=a12[n02+1]=a12[n02+2]=0; 
	int *sa12=p_buffer; p_buffer+=n02+3;
	sa12[n02]=sa12[n02+1]=sa12[n02+2]=0;
	int *a0=p_buffer; p_buffer+=n0;
	int *sa0=p_buffer; p_buffer+=n0;
	for (int i=0,j=0;i<n+(n0-n1);i++) if (i%3!=0) a12[j++]=i;
	radix_pass(a12,sa12,a+2,n02,K);
	radix_pass(sa12,a12,a+1,n02,K);  
	radix_pass(a12,sa12,a,n02,K);
	int name=0,c0=-1,c1=-1,c2=-1;
	for (int i=0;i<n02;i++)
	{
		if (a[sa12[i]]!=c0 || a[sa12[i]+1]!=c1 || a[sa12[i]+2]!=c2)
			name++,c0=a[sa12[i]],c1=a[sa12[i]+1],c2=a[sa12[i]+2];
		if (sa12[i]%3==1)
			a12[sa12[i]/3]=name;
		else 
			a12[sa12[i]/3+n0]=name;
	}
	if (name<n02)
	{
		get_suffix_array_internal(a12,sa12,n02,name);
		for (int i=0;i<n02;i++) a12[sa12[i]]=i+1;
	}
	else
	{
		for (int i=0;i<n02;i++) sa12[a12[i]-1]=i; 
	}
	for (int i=0,j=0;i<n02;i++) if (sa12[i]<n0) a0[j++]=3*sa12[i];
	radix_pass(a0,sa0,a,n0,K);
	for (int p=0,t=n0-n1,k=0;k<n;k++)
	{
		int i=(sa12[t]<n0?sa12[t]*3+1:(sa12[t]-n0)*3+2);
		int j=sa0[p];
		if (sa12[t]<n0?leq(a[i],a12[sa12[t]+n0],a[j],a12[j/3]):
			           leq(a[i],a[i+1],a12[sa12[t]-n0+1],a[j],a[j+1],a12[j/3+n0]))
		{
			sa[k]=i;
			if ((++t)==n02) for (k++;p<n0;p++,k++) sa[k]=sa0[p];
		}
		else
		{ 
			sa[k]=j;
			if ((++p)==n0) for (k++;t<n02;t++,k++) sa[k]=(sa12[t]<n0?sa12[t]*3+1:(sa12[t]-n0)*3+2); 
		}
	}
}

vector<int> get_rank(const vector<int>& sa)
{
	int n=sa.size();
	vector<int> rank(n);
	for (int i=0;i<n;i++) rank[sa[i]]=i;
	return rank;
}

template<class T>
vector<int> get_suffix_array(const vector<T>& s)
{
	if (s.empty()) return {};
	int n=s.size();
	int mins=s[0],maxs=s[0];
	for (int i=0;i<n;i++) 
	{
		if (s[i]<mins) mins=s[i];
		if (s[i]>maxs) maxs=s[i];
	}
	auto buffer=make_unique<int[]>((n+3)*2+(1<<16)+n);
	int *p_buffer=buffer.get();
	int *a=p_buffer; p_buffer+=n+3;
	int *sa=p_buffer; p_buffer+=n+3;
	a[n]=a[n+1]=a[n+2]=0;
	if (maxs-mins+1<=(1<<16))
	{
		for (int i=0;i<n;i++) a[i]=s[i]-mins+1;
		get_suffix_array_internal(a,sa,n,maxs-mins+1);
	}
	else
	{
		int *c=p_buffer; p_buffer+=(1<<16);
		int *t=p_buffer; p_buffer+=n;
		memset(c,0,(1<<16)*sizeof(int));
		for (int i=0;i<n;i++) c[(s[i]-mins)&65535]++;
		for (int i=1;i<(1<<16);i++) c[i]+=c[i-1];
		for (int i=n-1;i>=0;i--) a[--c[(s[i]-mins)&65535]]=i;
		memset(c,0,(1<<16)*sizeof(int));
		for (int i=0;i<n;i++) c[(s[i]-mins)>>16]++;
		for (int i=1;i<(1<<16);i++) c[i]+=c[i-1];
		for (int i=n-1;i>=0;i--) t[--c[(s[a[i]]-mins)>>16]]=a[i];
		int d=0;
		for (int i=0;i<n;i++) a[t[i]]=(i==0 || s[t[i]]!=s[t[i-1]])?(++d):d;
		get_suffix_array_internal(a,sa,n,d);
	}
	return vector<int>(sa,sa+n);
}

template<class T>
vector<int> compute_d(const vector<T>& s,const vector<int>& sa)
{
	if (s.empty()) return {};
	vector<int> rank=get_rank(sa);
	int n=s.size();
	vector<int> d(n);
	for (int k=0,i=0;i<n;i++)
		if (rank[i]==n-1)
			d[n-1]=k=0;
		else
		{
			if (k>0) k--;
			int t=sa[rank[i]+1];
			for (;i+k<n && i+k<n && s[i+k]==s[t+k];k++);
			d[rank[i]]=k;
		}
	return d;
}

template<class T>
vector<int> prepare_rmq(const vector<T>& s,const vector<int>& sa,const vector<int>& d)
{
	if (s.empty()) return {};
	int n=s.size();
	int e=0;
	for (;(1<<(e+1))<=n;e++);
	vector<int> buffer(n*(e+2)+1);
	buffer[0]=n;
	int *p_buffer=&buffer.front()+1;
	int *highbit=p_buffer; p_buffer+=n;
	for (int i=1,k=0;i<=n;i++) highbit[i-1]=(((1<<(k+1))<=i)?(++k):k);
	for (int i=0;i<n;i++) p_buffer[i]=d[i];
	p_buffer+=n;
	for (int p=1;p*2<=n;p*=2)
	{
		int* prev=p_buffer-n;
		for (int i=0;i<n-p;i++) p_buffer[i]=min(prev[i],prev[i+p]);
		for (int i=n-p;i<n;i++) p_buffer[i]=prev[i];
		p_buffer+=n;
	}
	return buffer;
}

template<class T>
vector<int> prepare_rmq(const vector<T>& s,const vector<int>& sa)
{
	return prepare_rmq(s,sa,compute_d(s,sa));
}

int rmq_query(const vector<int>& rmq,int a,int b)
{
	if (a>b) swap(a,b);
	int n=rmq[0];
	int l=b-a+1;
	int d=rmq[l];
	const int *f=&rmq.front()+(d+1)*n+1;
	return min(f[a],f[b-(1<<d)+1]);
}

int lca(const vector<int>& rmq,const vector<int>& rank,int a,int b)
{
	if (a==b) return rmq[0]-a;
	a=rank[a];
	b=rank[b];
	if (a>b) swap(a,b);
	return rmq_query(rmq,a,b-1);
}

}  // SA

vector<int> a;
vector<int> sa,rank2,rmq;

int lca(int a,int b)
{
	return SA::lca(rmq,rank2,a,b);
}

int n1,n2;
string s1,s2;

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	while (cin>>s1>>s2)
	{
		n1=LENGTH(s1);
		n2=LENGTH(s2);
		a.resize(n1+n2+2);
		REP(i,n1) a[i]=s1[i];
		a[n1]='$';
		REP(i,n2) a[n1+1+i]=s2[i];
		a[n1+n2+1]='#';
		sa=SA::get_suffix_array(a);
		rmq=SA::prepare_rmq(a,sa);
		rank2=SA::get_rank(sa);
		vector<vector<int>> g(n1+1);
		vector<int> delta(n1+1);
		FOR(i,1,n1+1)
		{
			int l=lca(i,n1+1);
			g[i+l].push_back(l);
			if (l>0)
			{
				++delta[i];
				--delta[i+l];
			}
		}
		int64 ret=0;
		int s_delta=0;
		REP(i,n1)
		{
			s_delta+=delta[i];
			if (s_delta>0) ++ret;
		}
		FOR(i,1,n1+1)
		{
			vector<int> a=g[i];
			if (SIZE(a)==0) continue;
			sort(ALL(a),[](int x,int y) { return rank2[n1+1+x]<rank2[n1+1+y]; });
			REP(k,SIZE(a))
			{
				int p=a[k];
				int l=0;
				if (k>0) l=lca(n1+1+p,n1+1+a[k-1]);
				ret+=max(0,n2-p-l);
			}
		}
		cout<<ret<<endl;
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}