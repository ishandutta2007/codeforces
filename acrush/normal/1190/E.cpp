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

double ck(double p)
{
	p=fmod(p,pi*2);
	if (p<0) p+=pi*2;
	return p;
}
bool solve(const VI& x,const VI& y,double r,int m)
{
	int n=SIZE(x);
	vector<double> s(n),t(n),w(n);
	REP(i,n)
	{
		double d=sqrt(sqr((double)x[i])+sqr((double)y[i]));
		double p=atan2((double)y[i],(double)x[i]);
		double dp=acos(r/d);
		s[i]=ck(p-dp);
		t[i]=ck(p+dp);
		w[i]=dp*2;
	}
	vector<pair<double,int>> pts(n+n);
	REP(i,n) pts[i]=MP(s[i],i),pts[i+n]=MP(t[i],i+n);
	sort(ALL(pts));
	VI sg(n),tg(n);
	REP(i,n+n) 
		if (pts[i].second<n)
			sg[pts[i].second]=i;
		else
			tg[pts[i].second-n]=i;
	REP(i,n) if (sg[i]>tg[i]) tg[i]+=n*2;
	VI other(n*4,-1);
	REP(i,n)
	{
		other[sg[i]]=tg[i];
		other[sg[i]+n*2]=tg[i]+n*2;
	}
	VI next(n*4);
	int minp=n*4;
	for (int i=n*2;i<n*4;i++) if (other[i]>=0) ckmin(minp,other[i]);
	for (int i=n*2-1;i>=0;i--)
	{
		next[i]=minp;
		if (other[i]>=0) ckmin(minp,other[i]);
	}
	REP(i,n*2) next[i+n*2]=next[i]+n*2;
	VI f[20];
	f[0]=next;
	FOR(k,1,20)
	{
		f[k]=VI(n*4);
		REP(i,n*4)
		{
			int t=f[k-1][i];
			f[k][i]=(t>=n*4?n*4:f[k-1][t]);
		}
	}
	REP(s,n*2)
	{
		int p=s;
		REP(k,20) if (contain(m,k))
		{ 
			p=f[k][p]; 
			if (p>=s+n*2) break;
		}
		/*
		REP(step,m)
		{
			p=next[p];
			if (p>=s+n*2) break;
		}
		*/
		if (p>=s+n*2) return true;
	}
	return false;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n,m;
	while (cin>>n>>m)
	{
		set<ipair> p;
		double low=0;
		double high=1e100;
		REP(i,n)
		{
			int x,y;
			cin>>x>>y;
			p.insert(MP(x,y));
			ckmin(high,sqrt(sqr((double)x)+sqr((double)y)));
		}
		double ret=0;
		if (p.count(MP(0,0))) 
			ret=0;
		else
		{
			VI x,y;
			for (auto w:p) x.push_back(w.first),y.push_back(w.second);
			REP(step,60)
			{
				double mid=(low+high)/2;
				if (solve(x,y,mid,m))
					low=mid;
				else
					high=mid;
			}
			ret=low;
		}
		printf("%.18lf\n",ret);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}