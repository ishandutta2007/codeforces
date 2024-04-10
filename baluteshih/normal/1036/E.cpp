#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define MP make_pair
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

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
double abs(const pdd&a)
{ return sqrt(dot(a,a));}

pair<pii,pii> dots[1000];
map<pii,int> mp;
const double eps=1e-9;

int ori(const pdd &p1,const pdd &p2,const pdd &p3)
{
	double a=cross(p2-p1,p3-p1);
	if(-eps<a && a<eps) return 0;
	return a > 0 ? 1 : -1;
}
bool btw(const pdd &p1,const pdd &p2,const pdd &p3)
{
	return dot(p1-p3,p2-p3)<eps;
}

bool seg_intersect(const pdd &p1,const pdd &p2,const pdd &p3,const pdd &p4)
{
	int a123=ori(p1,p2,p3);
	int a124=ori(p1,p2,p4);
	int a341=ori(p3,p4,p1);
	int a342=ori(p3,p4,p2);
	if(a123==0 && a124==0)
		return btw(p1,p2,p3)||btw(p1,p2,p4)||btw(p3,p4,p1)||btw(p3,p4,p2);
	else if(a123*a124<=0&&a341*a342<=0) return 1;
	return 0;
}

pdd intersect(const pdd &p1,const pdd &p2,const pdd &p3,const pdd &p4)
{
	double a123=cross(p2-p1,p3-p1);
	double a124=cross(p2-p1,p4-p1);
	return (p4*a123-p3*a124)/(a123-a124);
}

pdd rv(const pii &p)
{
	return MP((double)p.F,(double)p.S);
}

ll num[500000];

int main()
{jizz
	ll n,ans=0,g;
	cin >> n;
	for(int i=0;i<n;++i)
	{
		cin >> dots[i].F.F >> dots[i].F.S >> dots[i].S.F >> dots[i].S.S;
		g=__gcd((ll)abs(dots[i].F.F-dots[i].S.F),(ll)abs(dots[i].F.S-dots[i].S.S));
		ans+=g+1;
	}
	for(int i=2;i<=1000;++i)
		num[i*(i-1)/2]=i-1;
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
			if(seg_intersect(dots[i].F,dots[i].S,dots[j].F,dots[j].S))
			{
				pdd x=intersect(dots[i].F,dots[i].S,dots[j].F,dots[j].S);
				if(abs(x.F-round(x.F))<eps && abs(x.S-round(x.S))<eps) 
					++mp[MP((int)round(x.F),(int)round(x.S))];
			}
	//cout << ans << "\n";
	for(auto p:mp)
	{
		//cout << p.F.F << " " << p.F.S << " " << p.S << "\n";
		ans-=num[p.S];
	}
	cout << ans << "\n";
}