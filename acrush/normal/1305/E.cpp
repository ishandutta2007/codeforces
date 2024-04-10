#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

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
using VI=vector<int>;

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n,m;
	while (cin>>n>>m)
	{
		VI cnt(16<<20);
		vector<priority_queue<int>> heap(n+1);
		VI ret;
		REP(round,n)
		{
			int val=-1;
			for (int i=min(n,m);i>0;i--)
			{
				for (;!heap[i].empty() && cnt[-heap[i].top()]!=i;heap[i].pop());
				if (!heap[i].empty()) { val=-heap[i].top(); heap[i].pop(); break; }
			}
			if (val<0) 
			{
				val=(ret.empty()?1:ret.back()+1);
				for (;cnt[val]>0;++val);
			}
			m-=cnt[val];
			for (int x:ret) heap[++cnt[x+val]].push(-(x+val));
			ret.push_back(val);
		}
		if (m>0)
			printf("-1\n");
		else
			REP(i,n) printf("%d%c",ret[i],(i==n-1)?'\n':' ');
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}