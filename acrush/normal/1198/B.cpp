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

int getf(VI& f,int p)
{
	return (f[p]<0)?p:(f[p]=getf(f,f[p]));
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	while (cin>>n)
	{
		VI tmp_a(n);
		REP(i,n) cin>>tmp_a[i];
		int nq;
		cin>>nq;
		VI f(n+nq,-1);
		VI c(n+nq);
		VI roots;
		set<ipair> w_roots;
		REP(i,n) 
		{
			roots.push_back(i);
			c[i]=tmp_a[i];
			w_roots.insert(MP(c[i],i));
		}
		REP(cl,nq)
		{
			int tp;
			cin>>tp;
			if (tp==1)
			{
				int p,x;
				cin>>p>>x;
				--p;
				if (f[p]<0) w_roots.erase(MP(c[p],p));
				c[p]=x;
				f[p]=-1;
				w_roots.insert(MP(c[p],p));
			}
			else
			{
				int x;
				cin>>x;
				c[cl+n]=x;
				for (;!w_roots.empty() && w_roots.begin()->first<x;)
				{
					int idx=w_roots.begin()->second;
					f[idx]=cl+n;
					w_roots.erase(w_roots.begin());
				}
				w_roots.insert(MP(x,cl+n));
			}
		}
		REP(i,n) printf("%d ",c[getf(f,i)]);
		printf("\n");
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}