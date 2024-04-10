#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef long double ld;

ld EPS = 1e-12;

#define mp make_pair
#define pb push_back
#define p first
#define q second

struct pt { 
  ld x, y; 
  pt(ld x, ld y) : x(x), y(y) {}
  pt operator + (const pt &p)  const { return pt(x+p.x, y+p.y); }
  pt operator - (const pt &p)  const { return pt(x-p.x, y-p.y); }
  pt operator * (ld c)     const { return pt(x*c,   y*c  ); }
  pt operator / (ld c)     const { return pt(x/c,   y/c  ); }
  bool operator == (const pt &p) const { return fabs(x-p.x)+fabs(y-p.y) < EPS; }
};

typedef pair<pt, pt> ln;

bool CONVEX;

ld dot(pt p, pt q)     { return p.x*q.x+p.y*q.y; }
ld cross(pt p, pt q)   { return p.x*q.y-p.y*q.x; }
ld dist2(pt p, pt q)   { return dot(p-q,p-q); }
ld dist(pt p, pt q)   { return sqrt(dot(p-q,p-q)); }

bool clockwiseLL(pt a, pt b, pt c, pt d){
	return cross(a-b,c-d) >0;
}

bool clockwisePPP(pt a, pt b, pt c){
	return cross(a-c,a-b) > 0;
}


pt intersectLL(pt a, pt b, pt c, pt d) {
  return a + (b-a)*(cross(c-a, c-d))/(cross(b-a, c-d));
}

pt LINEA = pt(0, 0);
pt LINEB = pt(1, 2);

bool cmp4(ln l, ln m){
	pt p = LINEA;
	pt q = LINEB;
	pt a = LINEA + l.q - l.p;
	pt b = LINEA + m.q - m.p;
	if(cross(a-p,a-q) * cross(b-p,b-q) >= 0){
		if(cross(a-p,a-q) == 0 && dot(a-p,a-q) > 0) return true;
		if(cross(b-p,b-q) == 0 && dot(b-p,b-q) > 0) return false;
		return cross(b-p,a-p) < 0;
	}
	return cross(a-p,a-q) > 0;
}

ld areaG(vector<pt> g) {
  ld area = 0;
  for(int i = 0; i < g.size(); i++) {
    area += cross(g[i], g[(i+1)%g.size()]);
  }
  return area / 2.0;
}


pt rotateP(pt p, ld t) { 
  return pt(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t)); 
}

vector<pt> rotateG(vector<pt> g, ld t){
	vector<pt> h;
	for(int i=0; i<g.size(); i++){
		h.pb(rotateP(g[i], t));
	}
	return h;
}

vector<pt> intersectionH(vector<ln> v){
	sort(v.begin(), v.end(), cmp4);
	//for(int i=0; i<v.size(); i++){
	//	cout << v[i].p.x << " " << v[i].p.y << "," << v[i].q.x << " " << v[i].q.y << " " << endl;
	//}
	CONVEX = true;
	vector<ln> ans;
	vector<pt> pts;
	if(v.size() == 0) return pts;
	ans.pb(v[0]);
	int ind=1;
	
	while(v.size()>ind){
		while(ans.size()>1){
			ln a = v[ind];
			ln b = ans[(ll) ans.size()-2];
			ln c = ans.back();
			if(!clockwiseLL(b.p, b.q, a.p, a.q) || clockwisePPP(intersectLL(a.p, a.q, b.p, b.q), c.p, c.q)) break;
			ans.pop_back();
		}
		//cout << "______________________________" << endl;
		//for(int i=0; i<ans.size(); i++){
		//	cout << ans[i].p.x << " " << ans[i].p.y << "," << ans[i].q.x << " " << ans[i].q.y << " " << endl;
		//}
		ans.pb(v[ind]);
		ind++;
	}
	LINEA = LINEA * -1;
	LINEB = LINEB * -1;
	v = ans;
	
	ans.clear();
	sort(v.begin(), v.end(), cmp4);
	
	ans.pb(v[0]);
	ind=1;
	while(v.size()>ind){
		while(ans.size()>1){
			ln a = v[ind];
			ln b = ans[(ll) ans.size()-2];
			ln c = ans.back();
			if(!clockwiseLL(b.p, b.q, a.p, a.q) || clockwisePPP(intersectLL(a.p, a.q, b.p, b.q), c.p, c.q)) break;
			ans.pop_back();
		}
		ans.pb(v[ind]);
		ind++;
	}
	
	LINEA = LINEA * -1;
	LINEB = LINEB * -1;
	for(int i=0; i<ans.size(); i++){
		ln a = ans[i];
		ln b = ans[(i+1)%ans.size()];
		if(!clockwiseLL(a.p, a.q, b.p, b.q)){
			CONVEX = false;
			cout << "Not convex!";
		}
		pts.pb(intersectLL(a.p, a.q, b.p, b.q));
	}
	return pts;
}

vector<pt> intersectionGG(vector<pt> g, vector<pt> h){
	vector<ln> v;
	for(int i=0; i<g.size(); i++){
		v.pb(mp(g[i], g[(i+1)%g.size()]));
	}
	for(int i=0; i<h.size(); i++){
		v.pb(mp(h[i], h[(i+1)%h.size()]));
	}
	return intersectionH(v);
}


int main() {
	ld w, h, a;
	cin >> w >> h >> a;
	vector<pt> g;
	a = (a*atan(1))/45;
	g.pb(pt(w/2, h/2));
	g.pb(pt(-w/2, h/2));
	g.pb(pt(-w/2, -h/2));
	g.pb(pt(w/2, -h/2));
	cout << setprecision(10) << fixed;
	cout << areaG(intersectionGG(g, rotateG(g, a))) << endl;
	
}