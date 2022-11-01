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

const int oo=1000000000;

int n,a[20];
int f[21][1<<10],f2[21][1<<10];
int L[21];
int s[4],c[4][21];

int calc(int d,int set);
int calc2(int d,int set)
{
	if (d<0) return 0;
	int &ret=f2[d][set];
	if (ret>=0) return ret;
	ret=oo;
	for (int subset=0;subset<two(L[d+1]);subset++) checkmin(ret,calc(d,subset)+calc(d,set^subset));
	return ret;
}
int calc(int d,int set)
{
	if (d<0) return 0;
	int &ret=f[d][set];
	if (ret>=0) return ret;
	ret=oo;
	if (d==0 || a[d]!=a[d-1])
	{
		for (int subset=0;subset<two(L[d]);subset++) checkmin(ret,calc(d-1,subset)+calc(d-1,set^subset)+1);
	}
	else
	{
		if (!contain(set,L[d+1]-1))
		{
			for (int subset=0;subset<two(L[d]);subset++) checkmin(ret,calc(d-1,subset)+calc(d-1,set^subset)+1);
			int d2=d-1;
			for (;d2>=0 && a[d2]==a[d];d2--);
			for (int subset=0;subset<two(L[d2+1]);subset++) checkmin(ret,calc(d2,subset)+calc2(d2,set^subset)+(d-d2)*2);
		}
		else 
		{
			int newset=set-two(L[d+1]-1);
			int d2=d-1;
			for (;d2>=0 && a[d2]==a[d];d2--);
			for (int subset=0;subset<two(L[d2+1]);subset++) checkmin(ret,calc(d2,subset)+calc(d2,newset^subset)+(d-d2));
		}
	}
	return ret;
}

int counter=0;

void move(int src,int dest)
{
	counter--;
	if (s[src]==0 || s[dest]>0 && a[c[src][s[src]-1]]>a[c[dest][s[dest]-1]])
	{
		printf("ERROR\n");
		exit(0);
	}
	c[dest][s[dest]++]=c[src][--s[src]];
}

void construct(int d,int set,int src,int tmp,int dest);
void construct2(int d,int set,int src,int tmp,int dest,int cnt)
{
	int ret=calc2(d,set);
	for (int subset=0;subset<two(L[d+1]);subset++) if (ret==calc(d,subset)+calc(d,set^subset))
	{
		construct(d,subset,src,tmp,dest);
		for (int i=0;i<cnt;i++) 
		{
			move(tmp,src);
			printf("%d %d\n",tmp,src);
		}
		construct(d,set^subset,dest,tmp,src);
		return;
	}
}

void construct(int d,int set,int src,int tmp,int dest)
{
	if (d<0) return;
	int ret=calc(d,set);
	if (d==0 || a[d]!=a[d-1])
	{
		for (int subset=0;subset<two(L[d]);subset++) if (ret==calc(d-1,subset)+calc(d-1,set^subset)+1)
		{
			construct(d-1,subset,src,dest,tmp);
			move(src,dest);
			printf("%d %d\n",src,dest);
			construct(d-1,set^subset,tmp,src,dest);
			return;
		}
	}
	else
	{
		if (!contain(set,L[d+1]-1)) 
		{
			for (int subset=0;subset<two(L[d]);subset++) if (ret==calc(d-1,subset)+calc(d-1,set^subset)+1)
			{
				construct(d-1,subset,src,dest,tmp);
				move(src,dest);
				printf("%d %d\n",src,dest);
				construct(d-1,set^subset,tmp,src,dest);
				return;
			}
			int d2=d-1;
			for (;d2>=0 && a[d2]==a[d];d2--);
			for (int subset=0;subset<two(L[d2+1]);subset++) if (ret==calc(d2,subset)+calc2(d2,set^subset)+(d-d2)*2)
			{
				construct(d2,subset,src,tmp,dest);
				for (int i=0;i<d-d2;i++)
				{
					move(src,tmp);
					printf("%d %d\n",src,tmp);
				}
				construct2(d2,set^subset,dest,tmp,src,d-d2);
				return;
			}
		}
		else 
		{
			int newset=set-two(L[d+1]-1);
			int d2=d-1;
			for (;d2>=0 && a[d2]==a[d];d2--);
			for (int subset=0;subset<two(L[d2+1]);subset++) if (ret==calc(d2,subset)+calc(d2,newset^subset)+(d-d2))
			{
				construct(d2,subset,src,dest,tmp);
				for (int i=0;i<d-d2;i++) 
				{
					move(src,dest);
					printf("%d %d\n",src,dest);
				}
				construct(d2,newset^subset,tmp,src,dest);
				return;
			}
		}
	}
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	memset(f,255,sizeof(f));
	memset(f2,255,sizeof(f2));
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	for (int i=0;i<=n;i++)
	{
		L[i]=0;
		for (int j=0;j<i;j++) if (j==0 || a[j]!=a[j-1])
		{
			int c=0;
			for (int k=j;k<i && a[k]==a[j];k++) c++;
			if (c>=2) L[i]++;
		}
	}
	int R=calc(n-1,0);
	counter=R;
	printf("%d\n",R);
	s[1]=s[2]=s[3]=0;
	for (int i=n-1;i>=0;i--) c[1][s[1]++]=i;
	construct(n-1,0,1,2,3);
#ifdef _MSC_VER
	printf("R = %d\n",R);
#endif
	if (counter!=0) printf("ERROR\n");
	if (s[3]!=n) printf("ERROR\n");
	for (int i=0;i<n;i++) if (c[3][i]!=n-1-i) printf("ERROR\n");
	return 0;
}