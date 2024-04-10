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

char buffer[1<<20];

string readline()
{
	fgets(buffer,1<<20,stdin);
	int L=strlen(buffer);
	for (;L>0 && buffer[L-1]<32;--L);
	buffer[L]=0;
	return buffer;
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	string sp="\\begin{thebibliography}{99}";
	string tp="\\end{thebibliography}";
	string cp="\\cite{";
	string bp="\\bibitem{";
	std::ios::sync_with_stdio(false);
	string s="";
	while (1)
	{
		string s0=readline();
		if (s0==sp) break;
		s+=s0;
	}
	vector<string> expected;
	REP(i,LENGTH(s)-LENGTH(cp))
		if (s.substr(i,LENGTH(cp))==cp)
		{
			string s0="";
			for (int k=i+LENGTH(cp);s[k]!='}';k++) s0+=s[k];
			expected.push_back(s0);
		}
	vector<string> actual;
	map<string,string> content;
	while (1)
	{
		string s0=readline();
		if (s0==tp) break;
		int p=s0.find('}');
		string key=s0.substr(LENGTH(bp),p-LENGTH(bp));
		actual.push_back(key);
		content[key]=s0.substr(p+1);
	}
	if (actual==expected)
		printf("Correct\n");
	else
	{
		printf("Incorrect\n");
		printf("%s\n",sp.c_str());
		REP(i,SIZE(expected))
		{
			string key=expected[i];
			printf("%s%s}%s\n",bp.c_str(),key.c_str(),content[key].c_str());
		}
		printf("%s\n",tp.c_str());
	}
	return 0;
}