#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio> 
#include <iostream> 
#include <cmath> 
#include <string> 
#include <list> 
#include <vector> 
#include <algorithm> 
#include <functional> 
#include <utility> 
#include <set> 
#include <map> 
#include <complex> 
#include <queue> 
#include <stack> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 
#include <string.h> 

using namespace std; 

typedef unsigned int uint; 
typedef long long int64; 
typedef unsigned long long uint64; 
typedef unsigned short ushort; 
typedef unsigned char uchar; 
typedef pair<int,int> ipair; 
typedef vector<int> VI; 
typedef vector<string> VS; 
typedef vector<double> VD; 
#define SIZE(A) ((int)(A.size()))
#define LENGTH(A) ((int)(A.length()))
#define MP(A,B) make_pair(A,B)
const double pi=acos(-1.0); 
const double eps=1e-11; 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(a) (a).begin(),(a).end()

template<class T> T sqr(const T &x) { return x*x; } 
template<class T> T lowbit(const T &x) { return (x^(x-1))&x; } 
template<class T> int countbit(const T &n) { return (n==0)?0:(1+countbit(n&(n-1))); } 
template<class T> void ckmin(T &a,const T &b) { if (b<a) a=b; } 
template<class T> void ckmax(T &a,const T &b) { if (b>a) a=b; } 

int n;
map<string,vector<string>> queries;
map<vector<string>,vector<string>> groups;

int main()
{
#ifdef _MSC_VER
	freopen("c.in","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	cin>>n;
	queries.clear();
	REP(i,n)
	{
		string s;
		cin>>s;
		int l=LENGTH(s);
		int p=7;
		for (;p<l && s[p]!='/';p++);
		queries[s.substr(7,p-7)].push_back(s.substr(p));
	}
	groups.clear();
	for (auto& q:queries)
	{
		auto& key=q.second;
		sort(ALL(key));
		key.resize(unique(ALL(key))-key.begin());
		groups[key].push_back(q.first);
	}
	int cnt=0;
	for (auto& g:groups) if (SIZE(g.second)>=2) cnt++;
	printf("%d\n",cnt);
	for (auto& g:groups) if (SIZE(g.second)>=2)
	{
		bool first=true;
		for (auto& e:g.second) 
		{
			if (first) first=false;
			else printf(" ");
			printf("http://%s",e.c_str());
		}
		printf("\n");
	}
	return 0;
}