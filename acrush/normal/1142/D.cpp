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

int n;
int a[maxn];
int length[maxn][11];
int last[maxn][11];

bool f(int& state,int c)
{
	if (c>=state%11) return false;
	state=(c+state*(state-1)*6+10)%11;
	return true;
}
void init(int id,int s,int t)
{
	if (s==t)
	{
		REP(k,11)
		{
			int state=k;
			if (f(state,a[s]))
				length[id][k]=1,last[id][k]=state;
			else
				length[id][k]=0,last[id][k]=k;
		}
		return;
	}
	int m=(s+t)/2;
	init(id*2+1,s,m);
	init(id*2+2,m+1,t);
	int h=m-s+1;
	REP(k,11)
	{
		int l=length[id*2+1][k];
		int w=last[id*2+1][k];
		if (l<h)
			length[id][k]=l,last[id][k]=w;
		else
		{
			length[id][k]=h+length[id*2+2][w];
			last[id][k]=last[id*2+2][w];
		}
	}
}
bool extend(int id,int s,int t,int &pos,int &state)
{
	if (s==pos)
	{
		pos+=length[id][state];
		state=last[id][state];
		return pos>t;
	}
	if (s==t) return false;
	int m=(s+t)/2;
	if (pos<=m && !extend(id*2+1,s,m,pos,state)) return false;
	return extend(id*2+2,m+1,t,pos,state);
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	string s;
	while (cin>>s)
	{
		n=LENGTH(s);
		REP(i,n) a[i]=(s[i]-'0');
		init(0,0,n-1);
		int64 ret=0;
		REP(i,n) if (a[i]!=0)
		{
			++ret;
			int j=i+1;
			if (j>=n || a[j]>=a[i]) continue;
			int state=(10+a[j]+(a[i]-1)*a[i]/2)%11;
			++j;
			if (j<n) extend(0,0,n-1,j,state);
			// for (++j;j<n && f(state,a[j]);++j);
			ret+=(j-i-1);
		}
		cout<<ret<<endl;
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}