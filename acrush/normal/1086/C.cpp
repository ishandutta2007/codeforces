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

int m;
int n;
string s,sa,sb;
int r[26];
int used[26];

int dfs(int pos,int ok_a,int ok_b,int p1,int p2)
{
	while (1)
	{
		if (ok_a && ok_b) return 1;
		if (pos>=n) return 1;
		int key=s[pos]-'a';
		int a=sa[pos]-'a';
		int b=sb[pos]-'a';
		if (r[key]<0)
		{
			for (;p1<m && used[p1];++p1);
			for (;p2>=0 && used[p2];--p2);
			vector<int> g;
			if (ok_a)
				g.push_back(p1);
			else if (ok_b)
				g.push_back(p2);
			else
			{
				if (a>b) return 0;
				int p=-1;
				for (int k=a+1;k<=b-1;k++) if (!used[k]) { p=k; break; }
				if (p>=0)
					g.push_back(p);
				else
				{
					if (!used[a]) g.push_back(a);
					if (a!=b && !used[b]) g.push_back(b);
				}
			}
			for (int x:g)
			{
				r[key]=x;
				used[x]=1;
				if (dfs(pos,ok_a,ok_b,p1,p2)) return 1;
				r[key]=-1;
				used[x]=0;
			}
			return 0;
		}
		int c=r[key];
		if (!ok_a) { if (c<a) return 0; ok_a=(c>a); }
		if (!ok_b) { if (c>b) return 0; ok_b=(c<b); }
		++pos;
	}
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int testcase;
	for (cin>>testcase;testcase>0;testcase--)
	{
		cin>>m>>s>>sa>>sb;
		n=LENGTH(s);
		REP(i,m) r[i]=-1,used[i]=0;
		if (dfs(0,0,0,0,m-1))
		{
			printf("YES\n");
			int k=0;
			REP(i,m) if (r[i]<0)
			{
				for (;used[k];++k);
				r[i]=k;
				used[k]=1;
			}
			REP(i,m) printf("%c",'a'+r[i]);
			printf("\n");
		}
		else
			printf("NO\n");
	}
	return 0;
}