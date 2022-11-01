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

const int maxn=100000+5;

int n,m;
int L[maxn],R[maxn],T[maxn];
int q[maxn],ret[maxn];

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	ios::sync_with_stdio(false);
	cin>>m>>n;
	for (int i=0;i<n;i++) cin>>L[i]>>R[i]>>T[i];
	for (int i=0;i<m;i++) cin>>q[i];
	vector<ipair> events;
	for (int i=0;i<n;i++)
	{
		events.push_back(MP(L[i],i));
		events.push_back(MP(R[i],i));
	}
	set<ipair> S;
	int last=0;
	sort(events.begin(),events.end());
	vector<ipair> update1,update2;
	for (int i=0;i<SIZE(events);i++)
	{
		if (last!=events[i].first && SIZE(S)>0)
		{
			int next=events[i].first;
			int key=S.begin()->first;
			update1.push_back(MP(key-last,key-last));
			update2.push_back(MP(key-next,1));
			update2.push_back(MP(key-last,-1));
			update1.push_back(MP(key-next,-(key-next)));
		}
		last=events[i].first;
		int idx=events[i].second;
		if (last==L[idx])
			S.insert(MP(T[idx],idx));
		else
			S.erase(MP(T[idx],idx));
	}
	vector<ipair> order;
	for (int i=0;i<m;i++) order.push_back(MP(q[i],i));
	sort(order.begin(),order.end());
	sort(update1.begin(),update1.end());
	sort(update2.begin(),update2.end());
	int64 d1=0,d2=0;
	int p1=0,p2=0;
	for (int i=0;i<m;i++)
	{
		int key=order[i].first;
		for (;p1<SIZE(update1) && update1[p1].first<=key;p1++) d1+=update1[p1].second;
		for (;p2<SIZE(update2) && update2[p2].first<=key;p2++) d2+=update2[p2].second;
		ret[order[i].second]=(int)(d1+d2*key);
	}
	for (int i=0;i<m;i++) printf("%d\n",ret[i]);
	return 0;
}