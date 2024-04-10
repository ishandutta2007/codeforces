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
	int64 cnt;
	while (cin>>n>>m>>cnt)
	{
		string s;
		cin>>s;
		vector<VI> lcs(n+1,VI(n+1));
		for (int i=n-1;i>=0;i--) for (int j=n-1;j>=0;j--)
			lcs[i][j]=(s[i]==s[j]?lcs[i+1][j+1]+1:0);
		vector<ipair> a;
		REP(i,n) FOR(l,1,n-i+1) a.push_back(MP(i,l));
		sort(ALL(a),[&](const ipair& a1,const ipair& a2) {
			int s1=a1.first;
			int l1=a1.second;
			int s2=a2.first;
			int l2=a2.second;
			if (s1==s2) return l1<l2;
			int l0=lcs[s1][s2];
			if (l0<l1 && l0<l2) return s[s1+l0]<s[s2+l0];
			return l1<l2;
		});
		int low=0;
		int high=SIZE(a);
		for (;low+1<high;)
		{
			int mid=(low+high)/2;
			vector<int64> f(n+1);
			VI l(n,n+1);
			FOR(i,mid,SIZE(a)) ckmin(l[a[i].first],a[i].first+a[i].second);
			f[0]=1;
			REP(step,m)
			{
				vector<int64> d(n+1);
				REP(i,n) if (f[i] && l[i]<=n) d[l[i]]=min(d[l[i]]+f[i],cnt);
				f[0]=d[0];
				FOR(i,1,n+1) f[i]=min(f[i-1]+d[i],cnt);
			}
			if (f[n]>=cnt)
				low=mid;
			else
				high=mid;
		}
		printf("%s\n",s.substr(a[low].first,a[low].second).c_str());
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}