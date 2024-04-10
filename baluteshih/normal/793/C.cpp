#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define pb push_back
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define F first
#define S second
#define MP make_pair
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef pair<double,double> pdd;
const double eps=1e-12,INF=1e18;
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
int ori(const pdd &b,const pdd &a,const pdd &c){
	double res=cross(a-b,c-b);
	if(fabs(res)<eps) return 0;
	return res > 0 ? 1 : -1;
}
bool collinearity(const pdd &p1, const pdd &p2, const pdd &p3){
	return fabs(cross(p1-p3,p2-p3))<eps;
}
bool btw(const pdd &p1,const pdd &p2,const pdd &p3){
	if(!collinearity(p1,p2,p3)) return 0;
	return dot(p1-p3,p2-p3)<eps;
}
bool seg_intersect(const pdd &p1,const pdd &p2,const pdd &p3,const pdd &p4){
	int a123=ori(p1,p2,p3);
	int a124=ori(p1,p2,p4);
	int a341=ori(p3,p4,p1);
	int a342=ori(p3,p4,p2);
	if(a123==0 && a124==0)
		return btw(p1,p2,p3)||btw(p1,p2,p4)||btw(p3,p4,p1)||btw(p3,p4,p2);
	else if(a123*a124<=0&&a341*a342<=0) return 1;
	return 0;
}
pdd intersect(const pdd &p1,const pdd &p2,const pdd &p3,const pdd &p4){
	double a123=cross(p2-p1,p3-p1);
	double a124=cross(p2-p1,p4-p1);
	return (p4*a123-p3*a124)/(a123-a124);
}

pdd rect1,rect2;
pll irect1,irect2;

bool check(pdd x)
{
	return x.F+eps>rect1.F && x.F<rect2.F+eps && x.S+eps>rect1.S && x.S<rect2.S+eps;
}

bool check(double x,double y)
{
	return check(MP(x,y));
}

bool check(pll x)
{
	return x.F>irect1.F && x.F<irect2.F && x.S>irect1.S && x.S<irect2.S;
}

bool check(ll x,ll y)
{
	return check(MP(x,y));
}

int main()
{jizz
	ll n,flag,af=1;
	double dead=INF,live=-INF,x,y,vx,vy,tmp,lf,rg;
	cin >> n;
	cin >> irect1.F >> irect1.S >> irect2.F >> irect2.S;
	rect1=(pdd)irect1,rect2=(pdd)irect2;
	while(n--)
	{
		cin >> x >> y >> vx >> vy;
		lf=INF,rg=-INF,flag=0;
		if((ll)vx==0&&(ll)vy==0)
			if(check((ll)x,(ll)y))
			{
				live=0;
				continue;
			}
			else
				return cout << "-1\n",0;
		if(check((ll)x,(ll)y))
			lf=0,flag=1;
		else af=0;
		if((ll)vx!=0)
		{
			tmp=(rect1.F-x)/vx;
			if(((ll)vx>=0&&(ll)rect1.F>=(ll)x)||((ll)vx<=0&&(ll)rect1.F<=(ll)x))
				if(check(rect1.F,y+tmp*vy))
					lf=min(lf,tmp),rg=max(rg,tmp),flag=1;
			tmp=(rect2.F-x)/vx;
			if(((ll)vx>=0&&(ll)rect2.F>=(ll)x)||((ll)vx<=0&&(ll)rect2.F<=(ll)x))
				if(check(rect2.F,y+tmp*vy))
					lf=min(lf,tmp),rg=max(rg,tmp),flag=1;
		}
		else
		{
			if((ll)x==irect1.F||(ll)x==irect2.F)
				return cout << "-1\n",0;
		}
		if((ll)vy!=0)
		{
			tmp=(rect1.S-y)/vy;
			if(((ll)vy>=0&&(ll)rect1.S>=(ll)y)||((ll)vy<=0&&(ll)rect1.S<=(ll)y))
				if(check(x+tmp*vx,rect1.S))
					lf=min(lf,tmp),rg=max(rg,tmp),flag=1;
			tmp=(rect2.S-y)/vy;
			if(((ll)vy>=0&&(ll)rect2.S>=(ll)y)||((ll)vy<=0&&(ll)rect2.S<=(ll)y))
				if(check(x+tmp*vx,rect2.S))
					lf=min(lf,tmp),rg=max(rg,tmp),flag=1;
		}
		else
		{
			if((ll)y==irect1.S||(ll)y==irect2.S)
				return cout << "-1\n",0;
		}
		if(!flag||fabs(lf-rg)<eps)
			return cout << "-1\n",0;
		live=max(live,lf),dead=min(dead,rg);
	}
	if(live+eps>dead) cout << "-1\n";
	else cout << fixed << setprecision(20) << live  << "\n";
}