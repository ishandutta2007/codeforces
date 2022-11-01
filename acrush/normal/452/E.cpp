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

inline bool leq(int a1,int a2,int b1,int b2)
{
	return (a1<b1 || a1==b1 && a2<=b2);
}
inline bool leq(int a1,int a2,int a3,int b1,int b2,int b3)
{
	return (a1<b1 || a1==b1 && leq(a2,a3,b2,b3)); 
}
void RadixPass(int *a,int *b,int *r,int n,int K) 
{
	int *cnt=new int[K+1];
	memset(cnt,0,(K+1)*sizeof(int));
	for (int i=0;i<n;i++) cnt[r[a[i]]]++;
	for (int i=1;i<=K;i++) cnt[i]+=cnt[i-1];
	for (int i=n-1;i>=0;i--) b[--cnt[r[a[i]]]]=a[i];
	delete[] cnt;
}
void GetSuffixArray(int *s,int *SA,int n,int K)
{
	if (n<=8)
	{
		bool c[8][8];
		for (int i=n-1;i>=0;i--) for (int j=i+1;j<n;j++)
		{
			if (s[i]==s[j]) c[i][j]=(j+1<n && c[i+1][j+1]);
			else c[i][j]=(s[i]<s[j]);
			c[j][i]=!c[i][j];
		}
		for (int i=0;i<n;i++) SA[i]=i;
		for (int i=0;i<n;i++) for (int j=i+1;j<n;j++) if (c[SA[j]][SA[i]]) swap(SA[i],SA[j]);
		return;
	}
	int n0=(n+2)/3,n1=(n+1)/3,n2=n/3,n02=n0+n2;
	int *s12=new int[n02+3];
	s12[n02]=s12[n02+1]=s12[n02+2]=0; 
	int *SA12=new int[n02+3];
	SA12[n02]=SA12[n02+1]=SA12[n02+2]=0;
	int *s0=new int[n0];
	int *SA0=new int[n0];
	for (int i=0,j=0;i<n+(n0-n1);i++) if (i%3!=0) s12[j++]=i;
	RadixPass(s12,SA12,s+2,n02,K);
	RadixPass(SA12,s12,s+1,n02,K);  
	RadixPass(s12,SA12,s,n02,K);
	int name=0,c0=-1,c1=-1,c2=-1;
	for (int i=0;i<n02;i++)
	{
		if (s[SA12[i]]!=c0 || s[SA12[i]+1]!=c1 || s[SA12[i]+2]!=c2)
			name++,c0=s[SA12[i]],c1=s[SA12[i]+1],c2=s[SA12[i]+2];
		if (SA12[i]%3==1)
			s12[SA12[i]/3]=name;
		else 
			s12[SA12[i]/3+n0]=name;
	}
	if (name<n02)
	{
		GetSuffixArray(s12,SA12,n02,name);
		for (int i=0;i<n02;i++) s12[SA12[i]]=i+1;
	}
	else
	{
		for (int i=0;i<n02;i++) SA12[s12[i]-1]=i; 
	}
	for (int i=0,j=0;i<n02;i++) if (SA12[i]<n0) s0[j++]=3*SA12[i];
	RadixPass(s0,SA0,s,n0,K);
	for (int p=0,t=n0-n1,k=0;k<n;k++)
	{
		int i=(SA12[t]<n0?SA12[t]*3+1:(SA12[t]-n0)*3+2);
		int j=SA0[p];
		if (SA12[t]<n0?leq(s[i],s12[SA12[t]+n0],s[j],s12[j/3]):
			           leq(s[i],s[i+1],s12[SA12[t]-n0+1],s[j],s[j+1],s12[j/3+n0]))
		{
			SA[k]=i;
			if ((++t)==n02) for (k++;p<n0;p++,k++) SA[k]=SA0[p];
		}
		else
		{ 
			SA[k]=j;
			if ((++p)==n0) for (k++;t<n02;t++,k++) SA[k]=(SA12[t]<n0?SA12[t]*3+1:(SA12[t]-n0)*3+2); 
		}
	}
	delete[] s12;
	delete[] SA12;
	delete[] s0;
	delete[] SA0;
}
void SuffixArray(int n,char *s,int *SA,int *Rank)
{
	int *A=new int[n+3];
	for (int i=0;i<n;i++) A[i]=(int)((unsigned char)s[i]);
	A[n]=A[n+1]=A[n+2]=0;
	GetSuffixArray(A,SA,n,256);
	for (int i=0;i<n;i++) Rank[SA[i]]=i;
}
void SuffixArray(int n,int *s,int *SA,int *Rank)
{
	int maxs=0;
	for (int i=0;i<n;i++) if (s[i]>maxs) maxs=s[i];
	maxs++;
	int *A=new int[n+3];
	A[n]=A[n+1]=A[n+2]=0;
	if (maxs<(1<<16))
	{
		for (int i=0;i<n;i++) A[i]=s[i];
		GetSuffixArray(A,SA,n,maxs);
	}
	else
	{
		int *C=new int[1<<16];
		int *t=new int[n];
		memset(C,0,(1<<16)*sizeof(int));
		for (int i=0;i<n;i++) C[s[i]&65535]++;
		for (int i=1;i<(1<<16);i++) C[i]+=C[i-1];
		for (int i=n-1;i>=0;i--) A[--C[s[i]&65535]]=i;
		memset(C,0,(1<<16)*sizeof(int));
		for (int i=0;i<n;i++) C[s[i]>>16]++;
		for (int i=1;i<(1<<16);i++) C[i]+=C[i-1];
		for (int i=n-1;i>=0;i--) t[--C[s[A[i]]>>16]]=A[i];
		for (int d=0,i=0;i<n;i++) A[t[i]]=(i>0 && s[t[i]]!=s[t[i-1]])?(++d):d;
		GetSuffixArray(A,SA,n,n);
		delete[] C;
		delete[] t;
	}
	for (int i=0;i<n;i++) Rank[SA[i]]=i;
}
void PrepareD(int *s,int *SA,int *Rank,int *D,int n)
{
	for (int k=0,i=0;i<n;i++)
		if (Rank[i]==n-1)
			D[n-1]=k=0;
		else
		{
			if (k>0) k--;
			int t=SA[Rank[i]+1];
			for (;i+k<n && i+k<n && s[i+k]==s[t+k];k++);
			D[Rank[i]]=k;
		}
}
void PrepareD(char *s,int *SA,int *Rank,int *D,int n)
{
	for (int k=0,i=0;i<n;i++)
		if (Rank[i]==n-1)
			D[n-1]=k=0;
		else
		{
			if (k>0) k--;
			int t=SA[Rank[i]+1];
			for (;i+k<n && i+k<n && s[i+k]==s[t+k];k++);
			D[Rank[i]]=k;
		}
}

const int maxn=1000000+5;

int n,n1,n2,n3;
char s1[maxn],s2[maxn],s3[maxn];
int sa[maxn],rank[maxn],d[maxn];
char s[maxn];
vector<int> g[maxn];
int f[maxn],c1[maxn],c2[maxn],c3[maxn];
int ret[maxn];

int getf(int p)
{
	return (f[p]<0)?p:(f[p]=getf(f[p]));
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%s%s%s",s1,s2,s3);
	n1=strlen(s1);
	n2=strlen(s2);
	n3=strlen(s3);
	n=n1+n2+n3+2;
	memcpy(s,s1,n1*sizeof(char));
	s[n1]='#';
	memcpy(s+n1+1,s2,n2*sizeof(char));
	s[n1+n2+1]='$';
	memcpy(s+n1+n2+2,s3,n3*sizeof(char));
	SuffixArray(n,s,sa,rank);
	PrepareD(s,sa,rank,d,n);
	int w=min(n1,min(n2,n3));
	for (int i=0;i<=w;i++) g[i].clear();
	for (int i=0;i<n-1;i++) g[min(w,d[i])].push_back(i);
	for (int i=0;i<n;i++) 
	{
		f[i]=-1;
		c1[i]=c2[i]=c3[i]=0;
		int k=sa[i];
		if (k<n1) c1[i]++;
		if (k>=n1+1 && k<n1+n2+1) c2[i]++;
		if (k>=n1+n2+2) c3[i]++;
	}
	int64 r=0;
	for (int k=w;k>0;k--)
	{
		for (int i=SIZE(g[k])-1;i>=0;i--)
		{
			int p=g[k][i];
			int a=getf(p);
			int b=getf(p+1);
			if (a==b) continue;
			if (rand()&1) swap(a,b);
			r-=(int64)c1[a]*(int64)c2[a]*(int64)c3[a];
			r-=(int64)c1[b]*(int64)c2[b]*(int64)c3[b];
			f[a]=b;
			c1[b]+=c1[a];
			c2[b]+=c2[a];
			c3[b]+=c3[a];
			r+=(int64)c1[b]*(int64)c2[b]*(int64)c3[b];
		}
		ret[k]=(int)(r%1000000007);
	}
	for (int k=1;k<=w;k++)
	{
		if (k>1) printf(" ");
		printf("%d",ret[k]);
	}
	printf("\n");
	return 0;
}