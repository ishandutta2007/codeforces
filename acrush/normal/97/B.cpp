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

const int maxsize=200000+5;

int n;
vector<ipair> a,result;

void solve(vector<ipair> a)
{
	int n=SIZE(a);
	if (n==0) return;
	set<int> sx,sy;
	for (int i=0;i<n;i++) 
	{
		sx.insert(a[i].first);
		sy.insert(a[i].second);
	}
	if (SIZE(sx)==1 || SIZE(sy)==1)
	{
		for (int i=0;i<n;i++) result.push_back(a[i]);
		return;
	}
	if (SIZE(sx)>SIZE(sy))
	{
		int counter=SIZE(sx)/2,key=-1;
		for (set<int>::iterator it=sx.begin();it!=sx.end();++it) if ((counter--)==0) key=*it;
		vector<ipair> b,c;
		for (int i=0;i<n;i++) 
			if (a[i].first<key)
				b.push_back(a[i]);
			else if (a[i].first>key)
				c.push_back(a[i]);
		for (set<int>::iterator it=sy.begin();it!=sy.end();++it) result.push_back(MP(key,*it));
		solve(b);
		solve(c);
	}
	else
	{
		int counter=SIZE(sy)/2,key=-1;
		for (set<int>::iterator it=sy.begin();it!=sy.end();++it) if ((counter--)==0) key=*it;
		vector<ipair> b,c;
		for (int i=0;i<n;i++) 
			if (a[i].second<key)
				b.push_back(a[i]);
			else if (a[i].second>key)
				c.push_back(a[i]);
		for (set<int>::iterator it=sx.begin();it!=sx.end();++it) result.push_back(MP(*it,key));
		solve(b);
		solve(c);
	}
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a.push_back(MP(x,y));
	}
	solve(a);
	printf("%d\n",SIZE(result));
	for (int i=0;i<SIZE(result);i++) printf("%d %d\n",result[i].first,result[i].second);
	return 0;
}