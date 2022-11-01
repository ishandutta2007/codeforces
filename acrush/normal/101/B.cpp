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

const int MOD=1000000007;

const int maxn=500000+5;

int m,n,s[maxn],t[maxn];
int f[maxn],sum[maxn];
vector<int> g[maxn];

int del(int a,int b)
{
	int c=a-b;
	if (c<0) c+=MOD;
	return c;
}
void addto(int &a,int b)
{
	a+=b;
	if (a>=MOD) a-=MOD;
}
void addsum(int p,int c)
{
	for (;p<maxn;p=(p|(p-1))+1) addto(sum[p],c);
}
int getsum(int p)
{
	int s=0;
	for (;p>0;p&=(p-1)) addto(s,sum[p]);
	return s;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&m,&n);
	for (int i=0;i<n;i++) scanf("%d%d",&s[i],&t[i]);
	set<int> S;
	S.insert(0);
	S.insert(m);
	for (int i=0;i<n;i++) 
	{
		S.insert(s[i]);
		S.insert(t[i]);
	}
	vector<int> G(S.begin(),S.end());
	map<int,int> M;
	for (int i=0;i<SIZE(G);i++) M[G[i]]=i+1;
	for (int i=0;i<n;i++) s[i]=M[s[i]],t[i]=M[t[i]];
	m=SIZE(G);
	for (int i=0;i<m;i++) g[i].clear();
	for (int i=0;i<n;i++) g[t[i]].push_back(s[i]);
	memset(f,0,sizeof(f));
	memset(sum,0,sizeof(sum));
	f[1]=1;
	addsum(1,1);
	for (int i=2;i<=m;i++)
	{
		int total=0;
		for (int k=SIZE(g[i])-1;k>=0;k--)
			addto(total,del(getsum(i-1),getsum(g[i][k]-1)));
		f[i]=total;
		addsum(i,total);
	}
	printf("%d\n",f[m]);
	return 0;
}