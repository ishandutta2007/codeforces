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
#include <unordered_set>
#include <unordered_map>
#include <cassert>

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

const int maxn=200000+16;

int n,m;
int length;
vector<ipair> a[maxn],b[maxn];
vector<pair<int,ipair>> wa;
vector<ipair> wb;
int ca[maxn],za,cb[maxn];
int64 sa,sb;

int64 solve()
{
	REP(i,n)
	{
		auto& p=b[i];
		sort(ALL(p));
		int size=0;
		for (auto w:p)
		{
			for (;size>0 && w.second<=p[size-1].second;--size);
			p[size++]=w;
		}
		p.resize(size);
	}
	wa.clear();
	REP(i,n) for (auto x:a[i]) wa.push_back(MP(x.first,MP(i,x.second)));
	wb.clear();
	REP(i,n) for (auto x:b[i]) wb.push_back(MP(x.first,i));
	sort(ALL(wa));
	sort(ALL(wb));

	int64 ret=-1;
	REP(i,n) ca[i]=-1;
	za=n;
	sa=0;
	sb=0;
	REP(i,n) 
	{
		cb[i]=SIZE(b[i]);
		if (cb[i]==0) return -1;
		sb+=b[i][0].second;
	}
	int pb=0;
	REP(pa,SIZE(wa))
	{
		int time=wa[pa].first;
		int idx=wa[pa].second.first;
		int cost=wa[pa].second.second;
		if (ca[idx]<0)
		{
			--za;
			ca[idx]=cost;
			sa+=cost;
		}
		else
		{
			sa-=ca[idx];
			ckmin(ca[idx],cost);
			sa+=ca[idx];
		}
		bool ok=true;
		for (;pb<SIZE(wb) && wb[pb].first<=time+length;pb++)
		{
			int z=wb[pb].second;
			sb-=b[z][SIZE(b[z])-cb[z]].second;
			--cb[z];
			if (cb[z]==0) { ok=false; break; }
			sb+=b[z][SIZE(b[z])-cb[z]].second;
		}
		if (!ok) break;
		if (za==0 && (ret<0 || sa+sb<ret)) ret=sa+sb;
	}
	return ret;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	while (cin>>n>>m>>length) 
	{
		REP(i,n) a[i].clear();
		REP(i,n) b[i].clear();
		REP(i,m)
		{
			int d,s,t,c;
			cin>>d>>s>>t>>c;
			if (s==0)
				b[t-1].emplace_back(d,c);
			else
				a[s-1].emplace_back(d,c);
		}
		int64 ret=solve();
		cout<<ret<<endl;
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}