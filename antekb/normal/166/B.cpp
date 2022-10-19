#include<bits/stdc++.h>
 
#define st first
#define nd second
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
#define sz(x) (int)(x).size()
 
using namespace std;
 
///~~~~~~~~~~~~~~~~~~~~~~~~~~
 
void debug(){cerr<<"\n";}
template <typename H, typename... T>
void debug(H h, T... t) {cerr<<h; if (sizeof...(t)) cerr << ", "; debug(t...);}
#define deb(x...) cerr<<#x<<" = ";debug(x);
 
///~~~~~~~~~~~~~~~~~~~~~~~~~
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<ll> vl;
typedef vector<pll> vll;
typedef string str;
 
const int N=2e5+5, INF=1e9+5, mod=1e9+7;

//https://github.com/bqi343/USACO/blob/master/Implementations/content/geometry%20(13)/Primitives/Point.h

using T=double;
const T EPS=1e-9;
int sgn(T a) { return (a>EPS)-(a<-EPS); }
struct Point{
	typedef Point P;
	T x, y;
	Point(T _x=0, T _y=0){x=_x; y=_y;}
	T norm()const {return x*x+y*y;}
	P conj() const {return P(x, -y);};
	T dist(){return sqrt(norm());}
	P operator +(const P &p)const {return P(x+p.x, y+p.y);}
	P operator -(const P &p)const {return P(x-p.x, y-p.y);}
	P operator *(const T &p)const {return P(x*p, y*p);}
	P operator /(const T &p)const {return P(x/p, y/p);}
	P operator *(const P &p)const {return P(x*p.x-y*p.y, x*p.y+y*p.x);}
	P operator /(const P &p)const {return (*this)*p.conj()/p.norm();}
	P operator +=(const P &p){return (*this)=((*this)+p);}
	P operator -=(const P &p){return (*this)=((*this)-p);}
	P operator *=(const P &p){return (*this)=((*this)*p);}
	P operator /=(const P &p){return (*this)=((*this)/p);}
	P operator *=(const T &p){return (*this)=((*this)*p);}
	P operator /=(const T &p){return (*this)=((*this)/p);}
	bool eq(P p){return sgn((p-*this).x)==0 && sgn((p-*this).y)==0;}
	bool operator<(P p) const {if(x==p.x)return y<p.y; return x<p.x;}
	bool operator==(P p) const {return y==p.y && x==p.x;}
	T dot(P p) const {return x*p.x + y*p.y;}
	T dot(P a, P b) const {return (a-*this).dot(b-*this);}
	T cross(P p) const {return x*p.y - y*p.x;}
	T cross(P a, P b) const {return (a-*this).cross(b-*this);}
	P unit(){return (*this)/dist();}
	T arg(){return atan2(x, y);}
	P dir(T a) {return P(cos(a),sin(a));}
	P rotate(T a){return (*this)*dir(a);};
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; 
	}
};
typedef Point P; 
using Line=pair<P, P>;
using VP=vector<P>;
P reflect(P &p, Line &l){
	P a=p-l.st, b=l.nd-l.st;
	a=(a/b.unit()).conj();
	a*=b.unit();
	return a+=l.st;
}
P proj(P &p, Line &l){
	return (p+reflect(p, l))/2;
}
bool on_segm(P &p, Line &l){
	return sgn(p.cross(l.st, l.nd))==0 && sgn(p.dot(l.st, l.nd))<=0;
}
bool on_line(P &p, Line &l){
	return sgn(p.cross(l.st, l.nd))==0;
}
VP hull(VP pts){
	sort(all(pts), [](P &a, P &b){return (a.y<b.y) || (a.y==b.y && a.x < b.x);});
	//pts.resize(unique(all(pts))-pts.begin());
	if(pts.size()<2)return pts;
	for(int i=1; i<sz(pts); i++){
		pts[i]-=pts[0];
	}
	sort(1+all(pts), [](P &a, P &b){return sgn(a.cross(b))==1 || (sgn(a.cross(b)==0) && a.norm()<b.norm());});
	//for(P &p:pts)cout<<p<<" ";
	//	cout<<"\n";
	VP pts2;
	pts2.pb(P(0, 0));
	pts2.pb(pts[1]);
	for(int i=2; i<sz(pts); i++){
		while(pts2.size()>=2 && sgn(pts2.back().cross(pts2[sz(pts2)-2], pts[i]))>=1)pts2.pp();
		pts2.pb(pts[i]);
	}
	for(int i=pts.size()-2; i>0; i--){
		if(pts[i].arg()!=pts.back().arg()){
			break;
		}
		pts2.pb(pts[i]);
	}
	for(auto &p:pts2)p+=pts[0];
	return pts2;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin>>n;
	VP V(n);
	for(int i=0; i<n; i++){
		cin>>V[i].x>>V[i].y;
	}
	cin>>m;
	VP V2(m+n);
	for(int i=0; i<m; i++){
		cin>>V2[i].x>>V2[i].y;	
	}
	copy(all(V), V2.begin()+m);
	V2=hull(V2);
	sort(all(V));
	sort(all(V2));
	cout<<((V==V2) ? "YES" : "NO");
}