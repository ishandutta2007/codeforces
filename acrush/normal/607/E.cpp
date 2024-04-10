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

const int maxn=100000+16;

int n,m;
double la[maxn],lb[maxn],lc[maxn],ld[maxn],lp[maxn];
double cx,cy;
double r;
int c,ids[maxn];
double sp[maxn],tp[maxn];
int length;
int s[maxn],t[maxn];
int w[maxn],cw[maxn];
int sw[maxn];
vector<ipair> h[maxn];

double ck(double p)
{
	for (;p<0;p+=pi*2);
	for (;p>=pi*2;p-=pi*2);
	return p;
}
void prepare()
{
	c=0;
	REP(i,n) if (ld[i]<r)
	{
		double d=acos(ld[i]/r);
		double s=ck(lp[i]+d);
		double t=ck(lp[i]-d);
		if (s>t) swap(s,t);
		sp[c]=s;
		tp[c]=t;
		ids[c++]=i;
	}
	vector<pair<double,int>> order;
	order.resize(c*2);
	REP(i,c) order[i]=MP(sp[i],i);
	REP(i,c) order[i+c]=MP(tp[i],i+c);
	sort(ALL(order));
	REP(i,c+c) 
		if (order[i].second<c) s[order[i].second]=i;
		else t[order[i].second-c]=i;
}
void addsum(int p)
{
	if (p<=0) return;
	for (;p<length;p=(p|(p-1))+1) sw[p]++;
}
int getsum(int p)
{
	int r=0;
	for (;p>0;p&=(p-1)) r+=sw[p];
	return r;
}
int64 getcount()
{
	if (c<2) return 0;
	//int64 ret2=0;
	//REP(i,c) REP(j,c) if (i!=j && s[i]<s[j] && s[j]<t[i] && t[i]<t[j]) ++ret2;
	//return ret2;
	int64 ret=((int64)c)*(c-1)/2;
	length=c+c+2;
	memset(w,255,length*sizeof(int));
	REP(i,c) w[t[i]]=s[i];
	cw[0]=0;
	REP(i,length) cw[i+1]=cw[i]+(int)(w[i]>=0);
	REP(i,length) sw[i]=0;
	REP(i,length) if (w[i]>=0)
	{
		int p=w[i];
		ret-=cw[p];
		ret-=cw[i]-getsum(p+1);
		addsum(p+1);
	}
	return ret;
}

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios_base::sync_with_stdio(false);
	while (cin>>n)
	{
		cin>>cx>>cy>>m;
		cx/=1000;
		cy/=1000;
		REP(i,n) { cin>>la[i]>>lc[i]; lb[i]=-1000; }
		REP(i,n) ld[i]=fabs(la[i]*cx+lb[i]*cy+lc[i])/hypot(la[i],lb[i]);
		REP(i,n) 
		{
			lp[i]=atan2(lb[i],la[i]);
			double x1=cx+cos(lp[i])*ld[i],y1=cy+sin(lp[i])*ld[i];
			double x2=cx+cos(lp[i]+pi)*ld[i],y2=cy+sin(lp[i]+pi)*ld[i];
			double t1=fabs(la[i]*x1+lb[i]*y1+lc[i]);
			double t2=fabs(la[i]*x2+lb[i]*y2+lc[i]);
			if (t1>t2) lp[i]=ck(lp[i]+pi);
		}
		double low=0,high=2.1e9;
		for (int step=0;step<60;step++)
		{
			r=(low+high)/2.0;
			prepare();
			int64 cnt=getcount();
			if (cnt>m) high=r;
			else low=r;
		}
		r=low;
		prepare();
		int cnt=0;
		double ret=0;
		length=c+c+2;
		memset(w,255,length*sizeof(int));
		REP(i,c) w[t[i]]=s[i],cw[t[i]]=ids[i];
		REP(i,length) h[i].clear();
		REP(i,length) if (w[i]>=0)
		{
			int id1=cw[i];
			int p=w[i]+1;
			for (int k=p-1;k>0;k&=(k-1)) for (int j=SIZE(h[k])-1;j>=0;j--)
			{
				auto val=h[k][j];
				if (val.first<p) break;
				int id2=val.second;
				double a1=la[id1],b1=lb[id1],c1=lc[id1];
				double a2=la[id2],b2=lb[id2],c2=lc[id2];
				double tx=a1*b2-a2*b1;
				if (tx==0) continue;
				double x=+(b1*c2-b2*c1)/tx;
				double y=-(a1*c2-a2*c1)/tx;
				cnt++;
				ret+=hypot(x-cx,y-cy);
			}
			for (int k=p;k<length;k=(k|(k-1))+1)
				h[k].emplace_back(i,id1);
		}
		/*
		REP(i,c) REP(j,c) if (i!=j && s[i]<s[j] && s[j]<t[i] && t[i]<t[j])
		{
			double a1=la[ids[i]],b1=lb[ids[i]],c1=lc[ids[i]];
			double a2=la[ids[j]],b2=lb[ids[j]],c2=lc[ids[j]];
			double t=a1*b2-a2*b1;
			if (t==0) continue;
			double x=+(b1*c2-b2*c1)/t;
			double y=-(a1*c2-a2*c1)/t;
			cnt++;
			ret+=hypot(x-cx,y-cy);
		}
		*/
		printf("%.18lf\n",ret+r*abs(cnt-m));
	}
	return 0;
}