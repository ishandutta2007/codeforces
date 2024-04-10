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

string encode(int idx)
{
	string s="";
	s+=(char)(idx%8+'a');
	s+=(char)(idx/8+'1');
	return s;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int d[64][64];
	REP(i,64) REP(j,64)
		if (i==j)
			d[i][j]=0;
		else if (sqr(i/8-j/8)+sqr(i%8-j%8)==5)
			d[i][j]=1;
		else
			d[i][j]=100000;
	REP(k,64) REP(i,64) REP(j,64) ckmin(d[i][j],d[i][k]+d[k][j]);
	int n;
	while (cin>>n)
	{
		set<int> pos;
		REP(i,n)
		{
			string s;
			cin>>s;
			pos.insert((s[1]-'1')*8+(s[0]-'a'));
		}
		vector<string> ret;
		while (1)
		{
			int p=0;
			for (;p<n && pos.count(p);++p);
			if (p>=n) break;
			int s=*(--pos.end());
			vector<int> path;
			for (int k=p;k!=s;)
			{
				path.push_back(k);
				int np=-1;
				for (int dx=-2;dx<=2;dx++) for (int dy=-2;dy<=2;dy++) if (sqr(dx)+sqr(dy)==5)
				{
					int x=(k/8)+dx;
					int y=(k%8)+dy;
					if (x<0 || x>=8 || y<0 || y>=8) continue;
					if (d[k][s]==d[x*8+y][s]+1) np=x*8+y;
				}
				k=np;
			}
			path.push_back(s);
			REP(i,SIZE(path)-1)
			{
				int j=i+1;
				for (;!pos.count(path[j]);j++);
				for (int k=j;k>i;k--)
					ret.push_back(encode(path[k])+"-"+encode(path[k-1]));
				pos.insert(path[i]);
				pos.erase(path[j]);
				i=j-1;
			}
		}
		printf("%d\n",SIZE(ret));
		for (string s:ret) printf("%s\n",s.c_str());
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}