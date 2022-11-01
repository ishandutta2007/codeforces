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

const int maxsize=200000+16;

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n,f;
	while (cin>>n>>f)
	{
		vector<int> is_prime(maxsize,1);
		vector<int> p;
		bitset<maxsize> d;
		FOR(i,2,maxsize) if (is_prime[i])
		{
			p.push_back(i); 
			d.set(i);
			for (int j=i+i;j<maxsize;j+=i) is_prime[j]=0; 
		}
		REP(i,SIZE(p)) FOR(j,i,SIZE(p))
		{
			if ((int64)p[i]*p[j]>=maxsize) break;
			d.set(p[i]*p[j]);
		}
		d.reset(f);
		vector<int> sg(maxsize);
		bitset<maxsize> mask[128];
		REP(i,maxsize)
		{
			for (sg[i]=0;mask[sg[i]][i];++sg[i]);
			assert(sg[i]<128);
			mask[sg[i]]|=(d<<i);
		}
		int w=0;
		REP(i,n)
		{
			int a,b,c;
			cin>>a>>b>>c;
			w^=sg[b-a-1];
			w^=sg[c-b-1];
		}
		string player1="Alice";
		string player2="Bob";
		if (!w) swap(player1,player2);
		printf("%s\n%s\n",player1.c_str(),player2.c_str());
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}