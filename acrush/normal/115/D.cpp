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

const int maxn=2000+5;
const int MOD=1000003;

int n,a[maxn];
char s[maxn];
int f[maxn][maxn],g[maxn][maxn];

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%s",s);
	n=0;
	int L=strlen(s);
	for (int i=0;i<L;i++)
		if (s[i]=='+' || s[i]=='-')
			a[n++]=1;
		else if (s[i]=='*' || s[i]=='/')
			a[n++]=2;
		else 
		{
			a[n++]=0;
			for (;s[i]>='0' && s[i]<='9';i++);
			i--;
		}
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	for (int i=n-1;i>=0;i--) 
	{
		if (a[i]==0) f[i][i]=g[i][i]=1;
		for (int j=i+1;j<n;j++) if (a[j]==0)
		{
			int64 e=0;
			if (a[i]==1) e+=f[i+1][j];
			int *p1=f[i]-1;
			int *p2=g[j]+1;
			for (int k=i+1;k<j;k++) if (a[k]) e+=(int64)p1[k]*p2[k];
			f[i][j]=g[j][i]=(int)(e%MOD);
		}
	}
	printf("%d\n",f[0][n-1]);
	return 0;
}