#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

#define POW2(X) (1<<(X))
#define CKBIT(S,X) (((S)&POW2(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){ a=min(a,b); }
template<class T> inline void ckmax(T &a,T b){ a=max(a,b); }
template<class T> inline T sqr(T x){ return x*x; }
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()
using uint=unsigned int;
using int64=long long;
using uint64=unsigned long long;
using ipair=pair<int,int>;
using VI=vector<int>;
using VD=vector<double>;

int process()
{
	int n,m;
	string a;
	cin>>n>>m>>a;
	int c=0;
	REP(i,n) if (a[i]=='W') ++c;
	if (c==0) return max(0,2*m-1);
	c+=m;
	if (c>=n) return 2*n-1;
	vector<pair<int,ipair>> w;
	REP(i,n) if (a[i]=='L')
	{
		int j=i;
		for (;j<n && a[j]=='L';j++);
		--j;
		if (i!=0 && j!=n-1) w.push_back(MP(j-i+1,MP(i,j)));
		i=j;
	}
	sort(ALL(w));
	for (auto z:w) for (int i=z.second.first;i<=z.second.second;i++) if (m>0) --m,a[i]='W';
	if (m>0) return 2*c-1;
	int r=0;
	REP(i,n) if (a[i]=='W') r+=(i>0 && a[i-1]=='W')?2:1;
	return r;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int testcase;
	for (cin>>testcase;testcase>0;testcase--)
	{
		int r=process();
		printf("%d\n",r);
	}
	return 0;
}