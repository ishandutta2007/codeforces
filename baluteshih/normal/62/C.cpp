#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cerr << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

const double EPS=1e-12,INF=1e9;
pdd operator+(const pdd &a,const pdd &b)
{ return MP(a.F+b.F,a.S+b.S);}
pdd operator-(const pdd &a,const pdd &b)
{ return MP(a.F-b.F,a.S-b.S);}
pdd operator*(const pdd &a,const double &b)
{ return MP(a.F*b,a.S*b);}
pdd operator/(const pdd &a,const double &b)
{ return MP(a.F/b,a.S/b);}
double dot(const pdd &a,const pdd &b)
{ return a.F*b.F+a.S*b.S;}
double cross(const pdd &a,const pdd &b)
{ return a.F*b.S-a.S*b.F;}
double abs2(const pdd &a)
{ return dot(a,a);}
double abs(const pdd &a)
{ return sqrt(dot(a,a));}
int ori(const pdd &a,const pdd &b,const pdd &c){
	double res=cross(b-a,c-a);
	if(fabs(res)<EPS) return 0;
	return res > 0 ? 1 : -1;
}
bool collinearity(const pdd &p1, const pdd &p2, const pdd &p3){
	return fabs(cross(p1-p3,p2-p3))<EPS;
}
bool btw(const pdd &p1,const pdd &p2,const pdd &p3){
	if(!collinearity(p1,p2,p3)) return 0;
	return dot(p1-p3,p2-p3)<EPS;
}
bool seg_intersect(const pdd &p1,const pdd &p2,const pdd &p3,const pdd &p4){
	int a123=ori(p1,p2,p3);
	int a124=ori(p1,p2,p4);
	int a341=ori(p3,p4,p1);
	int a342=ori(p3,p4,p2);
	if(a123==0 && a124==0)
		return btw(p1,p2,p3)||btw(p1,p2,p4)||btw(p3,p4,p1)||btw(p3,p4,p2);
	return a123*a124<=0&&a341*a342<=0;
}
pdd intersect(const pdd &p1,const pdd &p2,const pdd &p3,const pdd &p4){
	double a123=cross(p2-p1,p3-p1);
	double a124=cross(p2-p1,p4-p1);
	return (p4*a123-p3*a124)/(a123-a124);
}

bool intri(pdd p,pdd p1,pdd p2,pdd p3)
{
	double org=fabs(cross(p2-p1,p3-p1)),a=fabs(cross(p1-p,p2-p)),b=fabs(cross(p1-p,p3-p)),c=fabs(cross(p2-p,p3-p));
	if(fabs(a+b+c-org)<EPS) return 1;
	return 0;
}

pdd arr[3][105];
vector<pair<pdd,pdd>> v;

void insert(pdd a,pdd b,pdd p1,pdd p2,pdd p3)
{
	int flag=0;
	pair<pdd,pdd> rt;
	if(intri(a,p1,p2,p3))
		if(flag) rt.S=a,flag=2;
		else rt.F=a,flag=1; 
	if(intri(b,p1,p2,p3))
		if(flag) rt.S=b,flag=2;
		else rt.F=b,flag=1;
	if(seg_intersect(a,b,p1,p2))
	{
		auto tmp=intersect(a,b,p1,p2);
		if(abs2(tmp-a)>=EPS&&abs2(tmp-b)>=EPS)
			if(flag) rt.S=tmp,flag=2;
			else rt.F=tmp,flag=1;
	}
	if(seg_intersect(a,b,p3,p2))
	{
		auto tmp=intersect(a,b,p3,p2);
		if(abs2(tmp-a)>=EPS&&abs2(tmp-b)>=EPS)
			if(flag) rt.S=tmp,flag=2;
			else rt.F=tmp,flag=1;
	}
	if(seg_intersect(a,b,p1,p3))
	{
		auto tmp=intersect(a,b,p1,p3);
		if(abs2(tmp-a)>=EPS&&abs2(tmp-b)>=EPS)
			if(flag) rt.S=tmp,flag=2;
			else rt.F=tmp,flag=1;
	}
	if(flag==2)
	{
		if(rt.F>rt.S) swap(rt.F,rt.S);
		v.pb(rt);
	}
}

double cal()
{
	sort(ALL(v));
	double rt=0;
	pdd nw=MP(-INF,-INF);
	for(pair<pdd,pdd> i:v)
		if(i.F>=nw)
			rt+=abs(i.S-i.F),nw=i.S;
		else if(i.S>nw)
			rt+=abs(i.S-nw),nw=i.S;
	return rt;
}

int main()
{jizz
	double ans=0;
	ll n;
	cin >> n;
	for(int i=0;i<n;++i)
		cin >> arr[0][i].F >> arr[0][i].S >> arr[1][i].F >> arr[1][i].S >> arr[2][i].F >> arr[2][i].S;
	for(int i=0;i<n;++i)
	{
		v.clear();
		for(int j=0;j<n;++j)
			if(i!=j)
				insert(arr[0][i],arr[1][i],arr[0][j],arr[1][j],arr[2][j]);
		ans+=abs(arr[0][i]-arr[1][i])-cal();
		v.clear();
		for(int j=0;j<n;++j)
			if(i!=j)
				insert(arr[2][i],arr[1][i],arr[0][j],arr[1][j],arr[2][j]);
		ans+=abs(arr[2][i]-arr[1][i])-cal();
		v.clear();
		for(int j=0;j<n;++j)
			if(i!=j)
				insert(arr[0][i],arr[2][i],arr[0][j],arr[1][j],arr[2][j]);
		ans+=abs(arr[0][i]-arr[2][i])-cal();
	}
	cout << fixed << setprecision(10) << ans << "\n";
}