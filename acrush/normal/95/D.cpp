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

int k;
int f[1005][1005];
int n;
int a[1005];
char buffer[1005];

int add(int a,int b)
{
	int c=a+b;
	if (c>=MOD) c-=MOD;
	return c;
}
int mul(int a,int b)
{
	return (int)((int64)a*b%MOD);
}
int del(int a,int b)
{
	int c=a-b;
	if (c<0) c+=MOD;
	return c;
}
void readin()
{
	scanf("%s",buffer);
	memset(a,0,sizeof(a));
	n=strlen(buffer);
	for (int i=0;i<n;i++) a[i]=buffer[n-1-i]-'0';
}
void addone()
{
	a[0]++;
	n++;
	for (int p=0;a[p]==10;p++) a[p]=0,a[p+1]++;
	for (;a[n-1]==0;n--);
}
void addto(int &a,int b)
{
	a+=b;
	if (a>=MOD) a-=MOD;
}
int calcf(int d,int p)
{
	if (d==0) return 1;
	if (p>k) p=k;
	int &ret=f[d][p];
	if (ret>=0) return ret;
	ret=mul(calcf(d-1,p+1),8);
	if (p>=k) addto(ret,mul(calcf(d-1,0),2));
	return ret;
}
int calcg(int d)
{
	if (d==0) return 1;
	return add(mul(calcf(d-1,100000000),7),mul(calcf(d-1,0),2));
}
int solve()
{
	for (;a[n-1]==0;n--);
	int R=0;
	for (int i=1;i<n;i++) addto(R,calcg(i));
	int last=100000000;
	for (int i=n-1;i>=0;i--)
	{
		for (int b=(int)(i==n-1);b<a[i];b++)
		{
			if ((b==4 || b==7) && last-i<=k) continue;
			addto(R,calcf(i,(b==4 || b==7)?0:(last-i)));
		}
		if ((a[i]==4 || a[i]==7) && last-i<=k) break;
		if (a[i]==4 || a[i]==7) last=i;
	}
	int C=0;
	for (int i=n-1;i>=0;i--) C=add(mul(C,10),a[i]);
	return del(del(C,1),R);
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	int testcases;
	scanf("%d%d",&testcases,&k);
	memset(f,255,sizeof(f));
	for (;testcases>0;testcases--)
	{
		readin();
		int R1=solve();
		readin();
		addone();
		int R2=solve();
		int R=del(R2,R1);
		printf("%d\n",R);
	}
	return 0;
}