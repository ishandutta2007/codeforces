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

const int MODE=2520;

int id[two(10)],g[two(10)];
int64 f[22][80][MODE];

int gcd(int a,int b)
{
	return (b==0)?a:gcd(b,a%b);
}
int lcm(int a,int b)
{
	return a*b/gcd(a,b);
}
void init()
{
	int counter=0;
	for (int set=0;set<two(10);set++)
	{
		int new_set=0;
		for (int i=2;i<10;i++) if (contain(set,i))
		{
			bool exists=false;
			for (int j=i+i;j<10;j+=i) if (contain(set,j)) exists=true;
			if (!exists) new_set|=two(i);
		}
		id[set]=(new_set==set)?(counter++):id[new_set];
		g[set]=1;
		for (int i=2;i<10;i++) if (contain(set,i)) g[set]=lcm(g[set],i);
	}
}
int64 calc(int d,int set,int left)
{
	if (d==0) return (int)(left%g[set]==0);
	int64 &ret=f[d][id[set]][left];
	if (ret>=0) return ret;
	ret=0;
	for (int i=0;i<10;i++) ret+=calc(d-1,set|two(i),(left*10+i)%MODE);
	return ret;
}
int64 solve(int64 n)
{
	int a[20],L=0;
	for (int64 m=n;m>0;m/=10) a[L++]=(int)(m%10);
	int64 R=0;
	for (int i=1;i<=L-1;i++) for (int k=1;k<10;k++) R+=calc(i-1,two(k),k%MODE);
	for (int i=0;i<=L-1;i++) for (int d=0;d<a[i];d++)
	{
		if (i==L-1 && d==0) continue;
		int set=0,left=0;
		for (int k=L-1;k>=i;k--) 
		{
			int key=(k==i)?d:a[k];
			set|=two(key);
			left=(left*10+key)%MODE;
		}
		R+=calc(i,set,left);
	}
	return R;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	init();
	memset(f,255,sizeof(f));
	int testcase;
	for (cin>>testcase;testcase>0;testcase--)
	{
		int64 s,t;
		cin>>s>>t;
		cout<<solve(t+1)-solve(s)<<endl;
	}
	return 0;
}