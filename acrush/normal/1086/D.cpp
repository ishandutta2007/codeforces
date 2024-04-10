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

const int maxn=(1<<20);

int n,nq;
int a[maxn];
set<int> p[3];
int s[3][maxn];

bool win_prefix(int length,int key)
{
	int w=(key+1)%3;
	if (!p[w].empty() && *p[w].begin()<length) return true;
	int l=(key+2)%3;
	if (!p[l].empty() && *p[l].begin()<length) return false;
	return true;
}
bool win_suffix(int length,int key)
{
	int w=(key+1)%3;
	if (!p[w].empty() && *p[w].rbegin()>=n-length) return true;
	int l=(key+2)%3;
	if (!p[l].empty() && *p[l].rbegin()>=n-length) return false;
	return true;
}
bool win(int at,int key)
{
	return win_prefix(at,key) && win_suffix(n-1-at,key);
}
int calc(int s[],int p);
int solve(int key)
{
	int w=(key+1)%3;
	int l=(key+2)%3;
	set<int> pos;
	if (!p[w].empty()) 
	{
		pos.insert(*p[w].begin());
		pos.insert(*p[w].rbegin());
	}
	if (!p[l].empty()) 
	{
		pos.insert(*p[l].begin());
		pos.insert(*p[l].rbegin());
	}
	set<int> extended_pos;
	extended_pos.insert(0);
	extended_pos.insert(n);
	for (int p:pos) for (int d=-2;d<=2;d++) if (p+d>=0 && p+d<=n) extended_pos.insert(p+d);
	vector<int> wpos(ALL(extended_pos));
	int ret=0,last_s=-1,last_t=-1;
	REP(i,SIZE(wpos)-1)
		if (win(wpos[i],key))
			if (last_t==wpos[i])
				last_t=wpos[i+1];
			else 
			{
				if (last_s>=0) ret+=calc(s[key],last_t)-calc(s[key],last_s);
				last_s=wpos[i];
				last_t=wpos[i+1];
			}
	if (last_s>=0)
		ret+=calc(s[key],last_t)-calc(s[key],last_s);
	return ret;
}
int solve()
{
	int ret=0;
	REP(k,3) ret+=solve(k);
	return ret;
}
void update(int s[],int p,int d)
{
	for (;p<=n;p=(p|(p-1))+1) s[p]+=d;
}
int calc(int s[],int p)
{
	int r=0;
	for (;p;p&=(p-1)) r+=s[p];
	return r;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	while (cin>>n>>nq)
	{
		string s0;
		cin>>s0;
		REP(i,n) a[i]=(s0[i]=='R'?2:(s0[i]=='P'?1:0));
		REP(k,3) p[k].clear();
		REP(i,n) p[a[i]].insert(i);
		REP(k,3) memset(s[k],0,(n+1)*sizeof(int));
		REP(i,n) update(s[a[i]],i+1,1);
		int ret=solve();
		printf("%d\n",ret);
		REP(cl,nq)
		{
			int pos;
			string s0;
			cin>>pos>>s0;
			int key=(s0[0]=='R'?2:(s0[0]=='P'?1:0));
			--pos;
			p[a[pos]].erase(pos);
			update(s[a[pos]],pos+1,-1);
			a[pos]=key;
			p[a[pos]].insert(pos);
			update(s[a[pos]],pos+1,1);
			int ret=solve();
			printf("%d\n",ret);
		}
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}