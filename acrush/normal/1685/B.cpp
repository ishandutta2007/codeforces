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

int solve()
{
	int cA,cB,cAB,cBA;
	cin>>cA>>cB>>cAB>>cBA;
	string s;
	cin>>s;
	int n=LENGTH(s);
	if (cA+cB+2*(cAB+cBA)!=n) return 0;
	int gA=0;
	int gB=0;
	for (char c:s)
		if (c=='A') ++gA;
		else ++gB;
	if (cA+cAB+cBA!=gA) return 0;
	if (cB+cAB+cBA!=gB) return 0;
	VI pA;
	VI pB;
	int pC=0;
	REP(i,n)
	{
		int j=i;
		for (;j<n && (s[j]==s[i])==((j-i)%2==0);++j);
		if ((j-i)%2==1)
			pC+=(j-i)/2;
		else
			(s[i]=='A'?pA:pB).push_back((j-i)/2-1);
		i=j-1;
	}
	sort(ALL(pA));
	sort(ALL(pB));
	int sA=0;
	int sB=0;
	int sC=pC;
	int dA=0;
	for (;dA<SIZE(pA) && sA+pA[dA]+1<=cAB;dA++) sA+=pA[dA]+1;
	FOR(i,dA,SIZE(pA)) sC+=pA[i];
	int dB=0;
	for (;dB<SIZE(pB) && sB+pB[dB]+1<=cBA;dB++) sB+=pB[dB]+1;
	FOR(i,dB,SIZE(pB)) sC+=pB[i];
	if (sA+sB+sC>=cAB+cBA) return 1;
	/*
	REP(dA,SIZE(pA)+1)
		REP(dB,SIZE(pB)+1)
		{
			REP(i,dA) sA+=pA[i]+1;
			FOR(i,dA,SIZE(pA)) sC+=pA[i];
			REP(i,dB) sB+=pB[i]+1;
			FOR(i,dB,SIZE(pB)) sC+=pB[i];
			sA=min(sA,cAB);
			sB=min(sB,cBA);
			if (sA+sB+sC>=cAB+cBA) return 1;
		}
	*/
	return 0;
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
		if (solve())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}