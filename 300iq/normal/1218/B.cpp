#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

void myassert(bool a) {
	if (!a) while (1);
}

typedef double db;
const db EPS = 1e-9;
const db pi=acos(-1.0)  ;

inline int sign(db a) { return a < -EPS ? -1 : a > EPS; }
  
inline int cmp(db a, db b){ return sign(a-b); }
  
struct P {
	db x, y;
	P() {}
	P(db _x, db _y) : x(_x), y(_y) {}
	P operator+(P p) { return {x + p.x, y + p.y}; }
	P operator-(P p) { return {x - p.x, y - p.y}; }
	P operator*(db d) { return {x * d, y * d}; }
	P operator/(db d) { return {x / d, y / d}; }
 
	bool operator<(P p) const { 
		int c = cmp(x, p.x);
		if (c) return c == -1;
		return cmp(y, p.y) == -1;
	}
 
	bool operator==(P o) const{
		return cmp(x,o.x) == 0 && cmp(y,o.y) == 0;
	}
 
	db dot(P p) { return x * p.x + y * p.y; }
	db det(P p) { return x * p.y - y * p.x; }
	 
	db distTo(P p) { return (*this-p).abs(); }
	db alpha() { return atan2(y, x); }
	void read() { cin>>x>>y; }
	void write() {cout<<"("<<x<<","<<y<<")"<<endl;}
	db abs() { return sqrt(abs2());}
	db abs2() { return x * x + y * y; }
	P rot90() { return P(-y,x);}
	P unit() { return *this/abs(); }
	int quad() const { return sign(y) == 1 || (sign(y) == 0 && sign(x) >= 0); }
	P rot(db an){ return {x*cos(an)-y*sin(an),x*sin(an) + y*cos(an)}; }
};
  
struct L{ //ps[0] -> ps[1]
	P ps[2];
	P operator[](int i) const { return ps[i]; }
	P dir() { return ps[1] - ps[0]; }
	L (P a,P b) {
		ps[0]=a;
		ps[1]=b;
	}
	bool include(P p) { return sign((ps[1] - ps[0]).det(p - ps[0])) > 0; }
	L push(){ // push eps outward
		const double eps = 1e-8;
		P delta = (ps[1] - ps[0]).rot90().unit() * eps;
		return {ps[0] + delta, ps[1] + delta};
	}
};

#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))
#define crossOp(p1,p2,p3) sign(cross(p1,p2,p3))
  
bool chkLL(P p1, P p2, P q1, P q2) {
	db a1 = cross(q1, q2, p1), a2 = -cross(q1, q2, p2);
	return sign(a1+a2) != 0;
}
 
P isLL(P p1, P p2, P q1, P q2) {
	db a1 = cross(q1, q2, p1), a2 = -cross(q1, q2, p2);
	return (p1 * a2 + p2 * a1) / (a1 + a2);
}
  
P isLL(L l1,L l2){ return isLL(l1[0],l1[1],l2[0],l2[1]); }
  
bool intersect(db l1,db r1,db l2,db r2){
	if(l1>r1) swap(l1,r1); if(l2>r2) swap(l2,r2); 
	return !( cmp(r1,l2) == -1 || cmp(r2,l1) == -1 );
}
  
bool isSS(P p1, P p2, P q1, P q2){
	return intersect(p1.x,p2.x,q1.x,q2.x) && intersect(p1.y,p2.y,q1.y,q2.y) && 
	crossOp(p1,p2,q1) * crossOp(p1,p2,q2) <= 0 && crossOp(q1,q2,p1)
			* crossOp(q1,q2,p2) <= 0;
}
  
bool isSS_strict(P p1, P p2, P q1, P q2){
	return crossOp(p1,p2,q1) * crossOp(p1,p2,q2) < 0 && crossOp(q1,q2,p1)
			* crossOp(q1,q2,p2) < 0;
}
  
bool isMiddle(db a, db m, db b) {
	return sign(a - m) == 0 || sign(b - m) == 0 || (a < m != b < m);
}
  
bool isMiddle(P a, P m, P b) {
	return isMiddle(a.x, m.x, b.x) && isMiddle(a.y, m.y, b.y);
}
  
bool onSeg(P p1, P p2, P q){
	return crossOp(p1,p2,q) == 0 && isMiddle(p1, q, p2);
}
 
bool onSeg_strict(P p1, P p2, P q){
	return crossOp(p1,p2,q) == 0 && sign((q-p1).dot(p1-p2)) * sign((q-p2).dot(p1-p2)) < 0;
}
  
P proj(P p1, P p2, P q) {
	P dir = p2 - p1;
	return p1 + dir * (dir.dot(q - p1) / dir.abs2());
}
  
P reflect(P p1, P p2, P q){
	return proj(p1,p2,q) * 2 - q;
}
  
db nearest(P p1,P p2,P q){
	P h = proj(p1,p2,q);
	if(isMiddle(p1,h,p2))
		return q.distTo(h);
	return min(p1.distTo(q),p2.distTo(q));
}
  
db disSS(P p1, P p2, P q1, P q2){
	if(isSS(p1,p2,q1,q2)) return 0;
	return min(min(nearest(p1,p2,q1),nearest(p1,p2,q2)), min(nearest(q1,q2,p1),nearest(q1,q2,p2)));
}
  
db rad(P p1,P p2){
	return atan2l(p1.det(p2),p1.dot(p2));
}
  
db incircle(P p1, P p2, P p3){
	db A = p1.distTo(p2);
	db B = p2.distTo(p3);
	db C = p3.distTo(p1);
	return sqrtl(A*B*C/(A+B+C));
}
  
//polygon
  
db area(vector<P> ps){
	db ret = 0; rep(i,0,ps.size()) ret += ps[i].det(ps[(i+1)%ps.size()]); 
	return ret/2;
}
  
int contain(vector<P> ps, P p){ //2:inside,1:on_seg,0:outside
	int n = ps.size(), ret = 0; 
	rep(i,0,n){
		P u=ps[i],v=ps[(i+1)%n];
		if(onSeg(u,v,p)) return 1;
		if(cmp(u.y,v.y)<=0) swap(u,v);
		if(cmp(p.y,u.y) >0 || cmp(p.y,v.y) <= 0) continue;
		ret ^= crossOp(p,u,v) > 0;
	}
	return ret*2;
}
  
vector<P> convexHull(vector<P> ps) {
	int n = ps.size(); if(n <= 1) return ps;
	sort(ps.begin(), ps.end());
	vector<P> qs(n * 2); int k = 0;
	for (int i = 0; i < n; qs[k++] = ps[i++]) 
		while (k > 1 && crossOp(qs[k - 2], qs[k - 1], ps[i]) <= 0) --k;
	for (int i = n - 2, t = k; i >= 0; qs[k++] = ps[i--])
		while (k > t && crossOp(qs[k - 2], qs[k - 1], ps[i]) <= 0) --k;
	qs.resize(k - 1);
	return qs;
}
  
vector<P> convexHullNonStrict(vector<P> ps) {
	//caution: need to unique the Ps first
	int n = ps.size(); if(n <= 1) return ps;
	sort(ps.begin(), ps.end());
	vector<P> qs(n * 2); int k = 0;
	for (int i = 0; i < n; qs[k++] = ps[i++]) 
		while (k > 1 && crossOp(qs[k - 2], qs[k - 1], ps[i]) < 0) --k;
	for (int i = n - 2, t = k; i >= 0; qs[k++] = ps[i--])
		while (k > t && crossOp(qs[k - 2], qs[k - 1], ps[i]) < 0) --k;
	qs.resize(k - 1);
	return qs;
}
  
db convexDiameter(vector<P> ps){
	int n = ps.size(); if(n <= 1) return 0;
	int is = 0, js = 0; rep(k,1,n) is = ps[k]<ps[is]?k:is, js = ps[js] < ps[k]?k:js;
	int i = is, j = js;
	db ret = ps[i].distTo(ps[j]);
	do{
		if((ps[(i+1)%n]-ps[i]).det(ps[(j+1)%n]-ps[j]) >= 0)
			(++j)%=n;
		else
			(++i)%=n;
		ret = max(ret,ps[i].distTo(ps[j]));
	}while(i!=is || j!=js);
	return ret;
}
  
vector<P> convexCut(const vector<P>&ps, P q1, P q2) {
	vector<P> qs;
	int n = ps.size();
	rep(i,0,n){
		P p1 = ps[i], p2 = ps[(i+1)%n];
		int d1 = crossOp(q1,q2,p1), d2 = crossOp(q1,q2,p2);
		if(d1 >= 0) qs.pb(p1);
		if(d1 * d2 < 0) qs.pb(isLL(p1,p2,q1,q2));
	}
	return qs;
}
  
//min_dist
  
db min_dist(vector<P>&ps,int l,int r){
	if(r-l<=5){
		db ret = 1e100;
		rep(i,l,r) rep(j,l,i) ret = min(ret,ps[i].distTo(ps[j]));
		return ret;
	}
	int m = (l+r)>>1;
	db ret = min(min_dist(ps,l,m),min_dist(ps,m,r));
	vector<P> qs; rep(i,l,r) if(abs(ps[i].x-ps[m].x)<= ret) qs.pb(ps[i]);
	sort(qs.begin(), qs.end(),[](P a,P b) -> bool {return a.y<b.y; });
	rep(i,1,qs.size()) for(int j=i-1;j>=0&&qs[j].y>=qs[i].y-ret;--j)
		ret = min(ret,qs[i].distTo(qs[j]));
	return ret;
}
  
int type(P o1,db r1,P o2,db r2){
	db d = o1.distTo(o2);
	if(cmp(d,r1+r2) == 1) return 4;
	if(cmp(d,r1+r2) == 0) return 3;
	if(cmp(d,abs(r1-r2)) == 1) return 2;
	if(cmp(d,abs(r1-r2)) == 0) return 1;
	return 0;
}
  
vector<P> isCL(P o,db r,P p1,P p2){
	if (cmp(abs((o-p1).det(p2-p1)/p1.distTo(p2)),r)>0) return {};
	db x = (p1-o).dot(p2-p1), y = (p2-p1).abs2(), d = x * x - y * ((p1-o).abs2() - r*r);
	d = max(d,0.0); P m = p1 - (p2-p1)*(x/y), dr = (p2-p1)*(sqrt(d)/y);
	return {m-dr,m+dr}; //along dir: p1->p2
}
  
vector<P> isCC(P o1, db r1, P o2, db r2) { //need to check whether two circles are the same
	db d = o1.distTo(o2); 
	if (cmp(d, r1 + r2) == 1) return {};
	if (cmp(d,abs(r1-r2))==-1) return {};
	d = min(d, r1 + r2);
	db y = (r1 * r1 + d * d - r2 * r2) / (2 * d), x = sqrt(r1 * r1 - y * y);
	P dr = (o2 - o1).unit();
	P q1 = o1 + dr * y, q2 = dr.rot90() * x;
	return {q1-q2,q1+q2};//along circle 1
}
  
vector<P> tanCP(P o, db r, P p) {
	db x = (p - o).abs2(), d = x - r * r;
	if (sign(d) <= 0) return {}; // on circle => no tangent
	P q1 = o + (p - o) * (r * r / x);
	P q2 = (p - o).rot90() * (r * sqrt(d) / x);
	return {q1-q2,q1+q2}; //counter clock-wise
}
  
  
vector<L> extanCC(P o1, db r1, P o2, db r2) {
	vector<L> ret;
	if (cmp(r1, r2) == 0) {
		P dr = (o2 - o1).unit().rot90() * r1;
		ret.pb(L(o1 + dr, o2 + dr)), ret.pb(L(o1 - dr, o2 - dr));
	} else {
		P p = (o2 * r1 - o1 * r2) / (r1 - r2);
		vector<P> ps = tanCP(o1, r1, p), qs = tanCP(o2, r2, p);
		rep(i,0,min(ps.size(),qs.size())) ret.pb(L(ps[i], qs[i])); //c1 counter-clock wise
	}
	return ret;
}
  
vector<L> intanCC(P o1, db r1, P o2, db r2) {
	vector<L> ret;
	P p = (o1 * r2 + o2 * r1) / (r1 + r2);
	vector<P> ps = tanCP(o1,r1,p), qs = tanCP(o2,r2,p);
	rep(i,0,min(ps.size(),qs.size())) ret.pb(L(ps[i], qs[i])); //c1 counter-clock wise
	return ret;
}
  
db areaCT(db r, P p1, P p2){
	vector<P> is = isCL(P(0,0),r,p1,p2);
	if(is.empty()) return r*r*rad(p1,p2)/2;
	bool b1 = cmp(p1.abs2(),r*r) == 1, b2 = cmp(p2.abs2(), r*r) == 1;
	if(b1 && b2){
		if(sign((p1-is[0]).dot(p2-is[0])) <= 0 &&
			sign((p1-is[0]).dot(p2-is[0])) <= 0)
		return r*r*(rad(p1,is[0]) + rad(is[1],p2))/2 + is[0].det(is[1])/2;
		else return r*r*rad(p1,p2)/2;
	}
	if(b1) return (r*r*rad(p1,is[0]) + is[0].det(p2))/2;
	if(b2) return (p1.det(is[1]) + r*r*rad(is[1],p2))/2;
	return p1.det(p2)/2;
}

 
P inCenter(P A, P B, P C) {
	double a = (B - C).abs(), b = (C - A).abs(), c = (A - B).abs();
	return (A * a + B * b + C * c) / (a + b + c);
}
 
P circumCenter(P a, P b, P c) { 
	P bb = b - a, cc = c - a;
	double db = bb.abs2(), dc = cc.abs2(), d = 2 * bb.det(cc);
	return a - P(bb.y * dc - cc.y * db, cc.x * db - bb.x * dc) / d;
}
 
P othroCenter(P a, P b, P c) { 
	P ba = b - a, ca = c - a, bc = b - c;
	double Y = ba.y * ca.y * bc.y,
	A = ca.x * ba.y - ba.x * ca.y,
	x0 = (Y + ca.x * ba.y * b.x - ba.x * ca.y * c.x) / A,
	y0 = -ba.x * (x0 - c.x) / ba.y + ca.y;
	return {x0, y0};
}

struct segment {
	db ag;
	int ty;
	P u,v;
};

db AG;
P o(0,0);
int n,k;

bool operator < (const L& a,const L& b) {
	P x(cos(AG),sin(AG));
	P f1=isLL(o,x,a[0],a[1]),f2=isLL(o,x,b[0],b[1]);
	//a[1]write.(), b[1].write();
	return cmp(f1.dot(x),f2.dot(x))==-1;
}

set<L> st;

vector<segment> evt;

int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%d",&k);
		vector<P> c(k);
		rep(j,0,k) {
			int u,v;
			scanf("%d%d",&u,&v);
			c[j]=P(u,v);
		}
		rep(j,0,k) {
			P u=c[j],v=c[(j+1)%k];
			if (crossOp(o,u,v)==0) continue;
			if (crossOp(o,u,v)<0) swap(u,v);
			db t1=u.alpha(),t2=v.alpha();
			assert(cmp(t1,t2)!=0);
			if (cmp(t1,pi)==0) t1=-pi;
			if (t1<t2) {
				evt.pb(segment{t1,0,u,v});
				evt.pb(segment{t2,1,u,v});
			} else {
				assert(cmp(t1,pi)==-1);
				assert(cmp(-pi,t2)==-1);
				evt.pb(segment{t1,0,u,v});
				evt.pb(segment{pi,1,u,v});
				evt.pb(segment{-pi,0,u,v});
				evt.pb(segment{t2,1,u,v});
			}
		}
	}
	sort(all(evt),[&](const segment&a,const segment&b) {
		if (cmp(a.ag,b.ag)!=0) return cmp(a.ag,b.ag)==-1;
		else return a.ty>b.ty;
	});
	db pr=-pi,ans=0;

	auto calcc=[&](L f,db a1,db a2)->double {
		P x(cos(a1),sin(a1));
		P f1=isLL(o,x,f[0],f[1]);
		P y(cos(a2),sin(a2));
		P f2=isLL(o,y,f[0],f[1]);
		//f1.write(); f2.write();
		//printf("gg %.10f\n",f1.det(f2)/2);
		return f1.det(f2)/2;
	};
	auto calc=[&](db a1,db a2)->double {
		myassert(SZ(st)!=1);
		if (SZ(st)==0) return 0;
		auto f1=*(st.begin()),f2=*(++st.begin());
		return calcc(f2,a1,a2)-calcc(f1,a1,a2);
	};
	/*for (auto p:evt) {
		printf("%.10f %d %.10f %.10f %.10f %.10f\n",p.ag,p.ty,p.u.x,p.u.y,p.v.x,p.v.y);
	}*/
	rep(i,0,SZ(evt)) {
		if (evt[i].ty==1) { // delete
			ans+=calc(pr,evt[i].ag);
			AG=(pr+evt[i].ag)/2;
			pr=evt[i].ag;
			int j=i;
			while (j<SZ(evt)&&cmp(evt[i].ag,evt[j].ag)==0&&evt[i].ty==evt[j].ty)
				j++;
			rep(k,i,j) st.erase(L{evt[k].u,evt[k].v});
			i=j-1;
		} else {
			if (cmp(pr,evt[i].ag)!=0) ans+=calc(pr,evt[i].ag);
			int j=i;
			while (j<SZ(evt)&&cmp(evt[i].ag,evt[j].ag)==0&&evt[i].ty==evt[j].ty)
				j++;
			pr=evt[i].ag;
			AG=(pr+evt[j].ag)/2;
			rep(k,i,j) st.insert(L{evt[k].u,evt[k].v});
			i=j-1;
		}
		//puts("ssss");
		//for (auto p:st) printf("%.10f %.10f %.10f %.10f\n",p[0].x,p[0].y,p[1].x,p[1].y);
		//printf("%.10f\n",ans);
	}
	printf("%.10f\n",ans);
}