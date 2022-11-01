#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)		(a).begin(),(a).end()
#define sz(a)		int((a).size())
#define FOR(i,a,b)	for(int i=a;i<b;++i)
#define REP(i,n)	FOR(i,0,n)
#define UN(v)		sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)		memset(a,b,sizeof a)
#define pb			push_back
#define X			first
#define Y			second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

double a,v,l,d,w;

double minT(double h,double v0){
	return (sqrt(v0*v0+2*a*h)-v0)/a;
}

double maxV(double h,double v0){
	return v0+minT(h,v0)*a;
}

double f(double x,double u,double v){
	u=min(u,v);
	double t=(v-u)/a;
	if(u*t+a*t*t/2<=x)return t+(x-(u*t+a*t*t/2))/v;
	return minT(x,u);
}

double Solve(double h,double v0,double v1,double maxv){
	v0=min(v0,maxv),v1=min(v1,maxv);
	double t=minT(h,v0);
	double L=0,R=h,x;
	REP(kk,1024){
		x=(L+R)/2;
		double t1=minT(x,v0);
		double t2=minT(h-x,v1);
		v0+a*t1<v1+a*t2?L=x:R=x;
	}
	x=(L+R)/2;
	return f(x,v0,maxv)+f(h-x,v1,maxv);
}

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	cin>>a>>v>>l>>d>>w;
	w=min(w,v);
	double v1=min(w,maxV(d,0));
	printf("%.12lf\n",Solve(d,0,v1,v)+Solve(l-d,v1,maxV(l-d,v1),v));
	return 0;
}