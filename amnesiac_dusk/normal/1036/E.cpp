/*
 * 	The way if it's all predetermined
 * 		And the way i should go all my life
 * 			I swear to go wherever will be
 * 				'Cause there'll be something to see and to find
 * 	I don't know the meaning of life
 * 		But i know what's truly precious
 * 			The way it's leading me to be in love
 * 				No fear i can find me always in my heart
 * 	The life it's not for comparing things
 * 		So i hold both of light and shadow
 * 			The rays of stars will bring me to you
 * 				Throught the dark night skies
 * 					See the way to be shined
 * 	I dont know what's right for our lives
 * 		But i know the truth of my love
 * 			The way it feels our breaths at the wind
 * 				And the way i should go all my life
 * 					I swear to go wherever will be
 * 						Thus the grace i wouldn't have
 * 							Will always in my heart
 * 								Thus the grace i wouldn't have
 * 									Will always in my heart
 */
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef rd
#define endl '\n'
#endif
#ifdef rd
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma=strchr(names+1,',');
	cout.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}
#else
#define trace(...)
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef long double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=1e9;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef tree<int, null_type, less<int>, rb_tree_tag,
		tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
f80 INF=1e100;
f80 EPS=1e-7;
const f80 PI=acos(-1);
struct PT {
	f80 x,y;
	PT() {
	}
	PT(f80 x, f80 y) :
			x(x), y(y) {
	}
	PT(const PT &p) :
			x(p.x), y(p.y) {
	}
	PT operator +(const PT &p) const {
		return PT(x+p.x,y+p.y);
	}
	PT operator -(const PT &p) const {
		return PT(x-p.x,y-p.y);
	}
	PT operator *(f80 c) const {
		return PT(x*c,y*c);
	}
	PT operator /(f80 c) const {
		return PT(x/c,y/c);
	}
};
f80 dot(PT p, PT q) {
	return p.x*q.x+p.y*q.y;
}
f80 dist2(PT p, PT q) {
	return dot(p-q,p-q);
}
f80 dist(PT p, PT q) {
	return sqrtl(dist2(p,q));
}
f80 cross(PT p, PT q) {
	return p.x*q.y-p.y*q.x;
}
f80 abs2(PT a) {
	return a.x*a.x+a.y*a.y;
}
f80 abs(PT a) {
	return sqrtl(abs2(a));
}
ostream &operator<<(ostream &os, const PT &p) {
	return os<<"("<<p.x<<","<<p.y<<")";
}
// rotate a point CCW or CW around the origin
PT RotateCCW90(PT p) {
	return PT(-p.y,p.x);
}
PT RotateCW90(PT p) {
	return PT(p.y,-p.x);
}
PT RotateCCW(PT p, f80 t) {
	return PT(p.x*cos(t)-p.y*sin(t),p.x*sin(t)+p.y*cos(t));
}
// project point c onto line through a and b
// assuming a != b
PT ProjectPointLine(PT a, PT b, PT c) {
	return a+(b-a)*dot(c-a,b-a)/dot(b-a,b-a);
}
// project point c onto line segment through a and b
PT ProjectPointSegment(PT a, PT b, PT c) {
	f80 r=dot(b-a,b-a);
	if(fabs(r)<EPS)
		return a;
	r=dot(c-a,b-a)/r;
	if(r<0)
		return a;
	if(r>1)
		return b;
	return a+(b-a)*r;
}
// compute distance from c to segment between a and b
f80 DistancePointSegment(PT a, PT b, PT c) {
	return sqrtl(dist2(c,ProjectPointSegment(a,b,c)));
}
f80 DistancePointPlane(f80 x, f80 y, f80 z, f80 a, f80 b, f80 c, f80 d) {
	return fabs(a*x+b*y+c*z-d)/sqrtl(a*a+b*b+c*c);
}
bool LinesParallel(PT a, PT b, PT c, PT d) {
	return fabs(cross(b-a,c-d))<EPS;
}
bool LinesCollinear(PT a, PT b, PT c, PT d) {
	return LinesParallel(a,b,c,d)&&fabs(cross(a-b,a-c))<EPS
			&&fabs(cross(c-d,c-a))<EPS;

}
// determine if line segment from a to b intersects with
// line segment from c to d
bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
	if(LinesCollinear(a,b,c,d)) {
		if(dist2(a,c)<EPS||dist2(a,d)<EPS||dist2(b,c)<EPS||dist2(b,d)<EPS)
			return 1;
		if(dot(c-a,c-b)>0&&dot(d-a,d-b)>0&&dot(c-b,d-b)>0)
			return 0;
		return 1;
	}
	if(cross(d-a,b-a)*cross(c-a,b-a)>0)
		return 0;
	if(cross(a-c,d-c)*cross(b-c,d-c)>0)
		return 0;
	return 1;
}
// compute intersection of line passing through a and b
// with line passing through c and d, assuming that unique
// intersection exists; for segment intersection, check if
// segments intersect first
PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
	b=b-a;
	d=c-d;
	c=c-a;
	assert(dot(b,b)>EPS&&dot(d,d)>EPS);
	return a+b*cross(c,d)/cross(b,d);
}
// compute center of circle given three points
PT ComputeCircleCenter(PT a, PT b, PT c) {
	b=(a+b)/2;
	c=(a+c)/2;
	return ComputeLineIntersection(b,b+RotateCW90(a-b),c,c+RotateCW90(a-c));
}
bool PointInPolygon(const vector<PT> &p, PT q) {
	bool c=0;
	fr(i, 0, p.size() - 1)
	{
		int j=(i+1)%p.size();
		if(((p[i].y<=q.y&&q.y<p[j].y)||(p[j].y<=q.y&&q.y<p[i].y))
				&&q.x<p[i].x+(p[j].x-p[i].x)*(q.y-p[i].y)/(p[j].y-p[i].y))
			c=!c;
	}
	return c;
}
// determine if point is on the boundary of a polygon
bool PointOnPolygon(const vector<PT> &p, PT q) {
	fr(i, 0, p.size() - 1)
		if(dist2(ProjectPointSegment(p[i],p[(i+1)%p.size()],q),q)<EPS)
			return 1;
	return 0;
}
// compute intersection of line through points a and b with
// circle centered at c with radius r > 0
vector<PT> CLIntersection(PT a, PT b, PT c, f80 r) {
	vector<PT> ret;
	b=b-a;
	a=a-c;
	f80 A=dot(b,b);
	f80 B=dot(a,b);
	f80 C=dot(a,a)-r*r;
	f80 D=B*B-A*C;
	if(D<-EPS)
		return ret;
	ret.pb(c+a+b*(-B+sqrtl(D+EPS))/A);
	if(D>EPS)
		ret.pb(c+a+b*(-B-sqrtl(D))/A);
	return ret;
}
// compute intersection of circle centered at a with radius r
// with circle centered at b with radius R
vector<PT> CCIntersection(PT a, PT b, f80 r, f80 R) {
	vector<PT> ret;
	f80 d=sqrtl(dist2(a,b));
	if(d>r+R||d+min(r,R)<max(r,R))
		return ret;
	f80 x=(d*d-R*R+r*r)/(2*d);
	f80 y=sqrtl(r*r-x*x);
	PT v=(b-a)/d;
	ret.pb(a+v*x+RotateCCW90(v)*y);
	if(y>0)
		ret.pb(a+v*x-RotateCCW90(v)*y);
	return ret;
}
f80 ComputeSignedArea(const vector<PT> &p) {
	f80 area=0;
	fr(i,0,p.size() - 1)
	{
		int j=(i+1)%p.size();
		area+=p[i].x*p[j].y-p[j].x*p[i].y;
	}
	return area/2.0;
}
f80 ComputeArea(const vector<PT> &p) {
	return fabs(ComputeSignedArea(p));
}
PT ComputeCentroid(const vector<PT> &p) {

	PT c(0,0);
	f80 scale=6.0*ComputeSignedArea(p);
	fr(i, 0, p.size() - 1)
	{
		int j=(i+1)%p.size();
		c=c+(p[i]+p[j])*(p[i].x*p[j].y-p[j].x*p[i].y);
	}
	return c/scale;
}
bool IsSimple(const vector<PT> &p) {
	fr(i,0,p.size() - 1)
	{
		fr(k,i + 1,p.size() - 1)
		{
			int j=(i+1)%p.size();
			int l=(k+1)%p.size();
			if(i==l||j==k)
				continue;
			if(SegmentsIntersect(p[i],p[j],p[k],p[l]))
				return 0;
		}
	}
	return 1;
}
bool RayOnPoint(PT a, PT v, PT b) {
	b=b-a;
	if(abs(b.x*v.y-b.y*v.x)<EPS) { // A and B in same line
		if(b.x*v.x>=-EPS&&b.y*v.y>=-EPS) // in same ray
			return 1;
		return 0;
	}
	return 0;
}
int sign(PT a, PT b, PT c) {
	return (cross(b-a,c-b)<0?-1:1);
}
f80 ArcArea(PT a, PT b, PT c, f80 r) {
	f80 cosa=dot(a-c,b-c)/(abs(a-c)*abs(b-c));
	f80 ang=acos(cosa);
	if(ang>2*PI)
		ang=2*PI-ang;
	return 0.5*r*r*ang;
}
f80 TCArea(PT a1, PT a2, PT c, f80 r) {
	f80 ans=0;
	f80 d1=dist2(a1,c),d2=dist2(a2,c);
	if(d1>d2)
		swap(d1,d2),swap(a1,a2);
	if(d2<=r*r) {
		ans=0.5*abs(cross(a1-c,a2-c));
	} else if(d1<=r*r) {
		auto vv=CLIntersection(a1,a2,c,r);
		PT C=vv[0];
		if(vv.size()>1&&dot(vv[1]-a1,vv[1]-a2)<0)
			C=vv[1];
		vv=CLIntersection(a2,c,c,r);
		PT D=vv[0];
		if(vv.size()>1&&dot(vv[1]-a2,vv[1]-c)<0)
			D=vv[1];
		ans=ArcArea(C,D,c,r)+0.5*abs(cross(C-c,a1-c));
	} else {
		auto vv=CLIntersection(a1,a2,c,r);
		if(vv.size()<=1||dot(a1-vv[0],a2-vv[0])>0) {
			ans=ArcArea(a1,a2,c,r);
		} else {
			if(dist2(a1,vv[1])<dist2(a1,vv[0]))
				swap(vv[0],vv[1]);
			ans=ArcArea(a1,vv[0],c,r)+ArcArea(a2,vv[1],c,r)
					+0.5*abs(cross(vv[0]-c,vv[1]-c));
		}
	}
	return abs(ans);
}
f80 PolyCircArea(vector<PT> &a, PT c, f80 r) { //

	int n=a.size();
	if(n<=2)
		return 0;
	f80 ans=0;
	fr(i, 0, n - 1)
		ans+=TCArea(a[i],a[(i+1)%n],c,r)*sign(c,a[i],a[(i+1)%n]);
	return abs(ans);
}
struct line {
	f80 a,b,c;
	line() {
	}
	line(f80 A, f80 B, f80 C) {
		a=A,b=B,c=C;
	}
};
bool areParallel(line l1, line l2) {
	return fabs(l1.a-l2.a)<EPS&&fabs(l1.b-l2.b)<EPS;
}
bool areSame(line l1, line l2) {
	return areParallel(l1,l2)&&fabs(l1.c-l2.c)<EPS;
}
struct Circle: PT {
	f80 r;
	Circle() {
	}
	Circle(PT c, f80 r) :
			PT(c.x,c.y), r(r) {
	}
	bool strictContains(PT p) {
		return dist2((*this),p)<r*r;
	}
	bool onBorder(PT p) {
		return abs(dist2((*this),p)-r*r)<EPS;
	}
	bool contains(PT p) {
		return strictContains(p)||onBorder(p);
	}
};
#define sqr(x) ((x) * (x))
// Find common tangents to 2 circles
// Helper method
void tangents(PT c, f80 r1, f80 r2, vector<line> & ans) {
	f80 r=r2-r1;
	f80 z= sqr(c.x)+sqr(c.y);
	f80 d=z-sqr(r);

	if(d<-EPS)
		return;
	d=sqrt(fabs(d));
	line l((c.x*r+c.y*d)/z,(c.y*r-c.x*d)/z,r1);
	ans.push_back(l);
}
vector<line> tangents(Circle a, Circle b) { // a != b
	vector<line> ans;
	ans.clear();
	for(int i=-1;i<=1;i+=2)
		for(int j=-1;j<=1;j+=2)
			tangents(b-a,a.r*i,b.r*j,ans);
	for(int i=0;i<ans.size();++i)
		ans[i].c-=ans[i].a*a.x+ans[i].b*a.y;
	vector<line> ret;
	for(int i=0;i<(int)ans.size();++i) {
		bool ok=true;
		for(int j=0;j<i;++j)
			if(areSame(ret[j],ans[i])) {
				ok=false;
				break;
			}
		if(ok)
			ret.push_back(ans[i]);
	}
	return ret;
}
int A[1005][2],B[1005][2];
PT a[1005],b[1005];
int sqrtt(int i) {
	int ans=sqrt(i);
	while(ans*ans>i)
		ans--;
	while(ans*ans<i)
		ans++;
	return ans;
}
void solve() {
	int n,xx,yy;
	cin>>n;
	fr(i,1,n)
	{
		cin>>xx>>yy;
		a[i].x=xx;
		a[i].y=yy;
		A[i][0]=xx;
		A[i][1]=yy;
		cin>>xx>>yy;
		b[i].x=xx;
		b[i].y=yy;
		B[i][0]=xx;
		B[i][1]=yy;
	}
	PT te;
	map<pii,int> lolol;
	fr(i,1,n)
		fr(j,i+1,n) {
			if(SegmentsIntersect(a[i],b[i],a[j],b[j])) {
				te=(ComputeLineIntersection(a[i], b[i], a[j], b[j]));
				if(abs(round(te.x)-te.x)+abs(round(te.y)-te.y)<EPS)
					lolol[{(int)round(te.x),(int)round(te.y)}]++;
			}
		}
	int ans=0;
	fr(i,1,n) {
		ans+=gcd(abs(A[i][0]-B[i][0]),abs(A[i][1]-B[i][1]))+1;
	}
	for(auto &pts:lolol) {
		ans-=(sqrtt(1+8*pts.se)-1)/2;
	}
	cout<<ans<<endl;
}

signed main() {
ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
srand(chrono::high_resolution_clock::now().time_since_epoch().count());
cout<<fixed<<setprecision(10);
int t=1;
//	cin>>t;
while(t--)
	solve();
#ifdef rd
	cout<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
return 0;
}