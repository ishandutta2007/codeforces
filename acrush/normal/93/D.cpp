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

int a[30][30],c[30][30];

void addto(int &a,int b)
{
	a+=b;
	if (a>=MOD) a-=MOD;
}
int add(int a,int b)
{
	int c=a+b;
	if (c>=MOD) c-=MOD;
	return c;
}
int del(int a,int b)
{
	int c=a-b;
	if (c<0) c+=MOD;
	return c;
}
int mul(int a,int b)
{
	return (int64)a*b%MOD;
}
void multiply(int c[30][30],int _a[30][30],int _b[30][30])
{
	int a[30][30],b[30][30];
	for (int i=0;i<30;i++) for (int j=0;j<30;j++) a[i][j]=_a[i][j],b[i][j]=_b[i][j];
	for (int i=0;i<30;i++) for (int j=0;j<30;j++) c[i][j]=0;
	for (int i=0;i<30;i++) for (int j=0;j<30;j++) for (int k=0;k<30;k++) addto(c[i][j],mul(a[i][k],b[k][j]));
}
bool valid(int a,int b)
{
	if (a!=4 && b!=4 && a==b) return false;
	if (a>b) swap(a,b);
	if (a==0 && b==3) return false;
	if (a==1 && b==2) return false;
	return true;
}
bool valid(int a,int b,int c)
{
	if (!valid(a,b)) return false;
	if (!valid(b,c)) return false;
	if (a>c) swap(a,c);
	if (a==1 && b==0 && c==2) return false;
	return true;
}
void mypower(int e)
{
	if (e==0)
	{
		memset(c,0,sizeof(c));
		for (int i=0;i<30;i++) c[i][i]=1;
		return;
	}
	if (e&1)
	{
		mypower(e-1);
		multiply(c,c,a);
	}
	else
	{
		mypower(e/2);
		multiply(c,c,c);
	}
}
int getS(int target,int e)
{
	mypower(e);
	return c[24][target];
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	memset(a,0,sizeof(a));
	a[26][26]++;
	a[27][27]++;
	for (int s=0;s<25;s++)
	{
		int c1=s/5;
		int c2=s%5;
		for (int c3=0;c3<4;c3++)
		{
			if (!valid(c1,c2,c3)) continue;
			a[s][26]++;
			a[s][c2*5+c3]++;
			if (valid(c2,c3,c2)) a[s][27]++;
		}
	}
	int L,R;
	scanf("%d%d",&L,&R);
	int R1=getS(26,R);
	int R2=getS(26,L-1);
	int R3=getS(27,(R+1)/2);
	int R4=getS(27,L/2);
	int result=add(del(R1,R2),del(R3,R4));
	result=mul(result,(MOD+1)/2);
	printf("%d\n",result);
	return 0;
}