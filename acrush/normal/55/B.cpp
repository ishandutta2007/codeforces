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

string s[3];

int64 solve(int64 g[],int d)
{
	int s=4-d;
	if (s==1) return g[0];
	int64 R=-1;
	for (int i=0;i<s;i++) for (int j=i+1;j<s;j++)
	{
		int64 h[4];
		int c=0;
		for (int k=0;k<s;k++) if (i!=k && j!=k) h[c++]=g[k];
		h[c++]=(::s[d][0]=='+')?(g[i]+g[j]):(g[i]*g[j]);
		int64 t=solve(h,d+1);
		if (R<0 || t<R) R=t;
	}
	return R;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	int64 g[4];
	cin>>g[0]>>g[1]>>g[2]>>g[3]>>s[0]>>s[1]>>s[2];
	cout<<solve(g,0)<<endl;
	return 0;
}