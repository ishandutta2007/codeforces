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

int n;
char a[100005];
int next4[100005],next7[100005];

int compare(int c4,int c7,int pos)
{
	int l7=next7[pos]-pos;
	if (l7<c7) return 7-(a[pos+l7]-'0');
	pos+=c7;
	int l4=next4[pos]-pos;
	if (l4==c4) return 0;
	return 4-(a[pos+l4]-'0');
}
void prepare(int next[],int key)
{
	next[n]=n;
	for (int i=n-1;i>=0;i--) next[i]=(a[i]==key+'0')?next[i+1]:i;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%s",&a);
	n=strlen(a);
	prepare(next4,4);
	prepare(next7,7);
	if (n%2==1 || compare(n/2,n/2,0)<0) 
	{
		n++;
		if (n&1) n++;
		for (int i=0;i<n/2;i++) printf("4");
		for (int i=0;i<n/2;i++) printf("7");
		printf("\n");
		return 0;
	}
	int c4=n/2,c7=n/2;
	bool ed=false;
	for (int i=0;i<n;i++)
		if (c4>0 && (ed || a[i]<'4' || a[i]=='4' && compare(c4-1,c7,i+1)>=0))
		{
			if (a[i]<'4') ed=true;
			printf("4");
			c4--;
		}
		else
		{
			if (a[i]<'7') ed=true;
			printf("7");
			c7--;
		}
	printf("\n");
	return 0;
}