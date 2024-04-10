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

string tolower(string s)
{
	string r="";
	for (int i=0;i<LENGTH(s);i++) r+=tolower(s[i]);
	return r;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	int n;
	string a[105];
	char str[1024];
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%s",str);
		a[i]=str;
	}
	scanf("%s",str);
	string s=str;
	scanf("%s",str);
	char key=str[0];
	string r=s;
	for (int i=0;i<n;i++)
		for (int k=0;k<=LENGTH(s)-LENGTH(a[i]);k++)
			if (tolower(s.substr(k,LENGTH(a[i])))==tolower(a[i]))
				for (int j=0;j<LENGTH(a[i]);j++)
				{
					char rep=key;
					if (tolower(s[k+j])==key) rep=(key=='a')?'b':'a';
					r[k+j]=(islower(s[k+j])?rep:(rep-32));
				}
	printf("%s\n",r.c_str());
	return 0;
}