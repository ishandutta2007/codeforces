#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <string.h>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void ckmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	string g,s;
	while (cin>>g>>s)
	{
		int m=LENGTH(g);
		int c1=0;
		REP(i,m) if (g[i]=='1') ++c1;
		int n=LENGTH(s);
		vector<int> c(n+1);
		c[0]=0;
		for (int i=1;i<=n;i++) c[i]=c[i-1]+(s[i-1]-'0');
		vector<int> p(n+1);
		p[0]=p[1]=0;
		for (int k=0,i=2;i<=n;i++)
		{
			for (;k>0 && s[k]!=s[i-1];k=p[k]);
			if (s[k]==s[i-1]) k++;
			p[i]=k;
		}
		int low=0,high=m+1;
		int pos=-1;
		for (;low+1<high;)
		{
			int cnt=(low+high)/2;
			bool ok=false;
			for (int i=p[n];;i=p[i])
			{
				int64 l=n+(int64)(cnt-1)*(n-i);
				if (l<=m)
				{
					int64 w=c[n]+(int64)(cnt-1)*(c[n]-c[i]);
					if (w<=c1 && w+(m-l)>=c1) { ok=true; pos=i; break; }
				}
				if (i==0) break;
			}
			if (ok)
				low=cnt;
			else
				high=cnt;
		}
		if (low==0)
			printf("%s\n",g.c_str());
		else
		{
			g=s;
			REP(i,low-1) g+=s.substr(pos);
			for (char c:g) if (c=='1') --c1;
			g+=string(c1,'1');
			g+=string(m-LENGTH(g),'0');
			printf("%s\n",g.c_str());
		}
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}