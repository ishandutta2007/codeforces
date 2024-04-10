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
#include <string.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)

map<string,int> M;

int getl(string s)
{
	if (M.find(s)==M.end()) return M[s]=-1000000000;
	return M[s];		
}
int main()
{
#ifdef _MSC_VER
	freopen("B.in","r",stdin);
#endif
	int n;
	char s[1024];
	gets(s);
	sscanf(s,"%d",&n);
	M["void"]=0;
	M["errtype"]=-1000000000;
	for (int i=0;i<n;i++)
	{
		gets(s);
		istringstream sin(s);
		string cmd;
		sin>>cmd;
		if (cmd=="typeof")
		{
			string key;
			sin>>key;
			int delta=0;
			for (;LENGTH(key)>0 && key[0]=='&';key=key.substr(1)) delta--;
			for (;LENGTH(key)>0 && key[LENGTH(key)-1]=='*';key=key.substr(0,LENGTH(key)-1)) delta++;
			int l=getl(key);
			l+=delta;
			if (l<0)
				printf("errtype\n");
			else
			{
				printf("void");
				for (int j=0;j<l;j++) printf("*");
				printf("\n");
			}
		}
		else
		{
			string key,other;
			sin>>key>>other;
			int delta=0;
			for (;LENGTH(key)>0 && key[0]=='&';key=key.substr(1)) delta--;
			for (;LENGTH(key)>0 && key[LENGTH(key)-1]=='*';key=key.substr(0,LENGTH(key)-1)) delta++;
			int l=getl(key);
			l+=delta;
			if (l<0) l=-1000000000;
			M[other]=l;
		}
	}
	return 0;
}