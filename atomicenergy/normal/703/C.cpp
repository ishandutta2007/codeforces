// C++ routines for computational geometry.

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>

using namespace std;

typedef long double ld;

ld INF = 1e100;
ld EPS = 1e-15;
ld PI = atan(1)*4;

struct pt { 
  ld x, y; 
  pt() {}
  pt(ld x, ld y) : x(x), y(y) {}
  pt(const pt &p) : x(p.x), y(p.y)    {}
  pt operator + (const pt &p)  const { return pt(x+p.x, y+p.y); }
  pt operator - (const pt &p)  const { return pt(x-p.x, y-p.y); }
  pt operator * (ld c)     const { return pt(x*c,   y*c  ); }
  pt operator / (ld c)     const { return pt(x/c,   y/c  ); }
  bool operator == (const pt &p) const { return  (((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y)) < EPS);}
};


//Stores two points
//Allowed to be lines or points
struct ln {
	pt p, q;
	ln() {}
	ln(ld a, ld b, ld c, ld d){ p = pt(a, b), q = pt(c, d);} 
	ln(pt x, ld a, ld l){p = x, q = p+pt(l*cos(a),l*sin(a));}
	ln(ld m, ld b) {p = pt(0, m), q = pt(1,m+b);}
	ln(pt x, pt y) { p = x , q = y;}
};

struct circle {
	pt c;
	ld r;
	circle() {}
	circle(pt p, ld x) {c = p, r=x;}
	circle(const circle &x){c = x.c, r = x.r; }
};

struct polygon {
	vector<ln> v;
	polygon() {}
	polygon(vector<ln> u) {v = u;}
	polygon (const polygon &p) {v=p.v;}
	polygon(vector<pt> u){
		vector<ln> w;
		for(int i=0; i<u.size(); i++){
			w.push_back(ln(u[i], u[(i+1)%u.size()]));
		}
		v = w;
	}
};

ostream &operator<<(ostream &os, const pt &p) {
  os << p.x << " " << p.y; 
}
ostream &operator<<(ostream &os, const ln &l) {
  os << l.p << " " << l.q; 
}


ld dot(pt p, pt q)     { return p.x*q.x+p.y*q.y; }
ld cross(pt p, pt q)   { return p.x*q.y-p.y*q.x; }
ld dist2(pt p, pt q)   { return dot(p-q,p-q); }
ld dist(pt p, pt q)   { return sqrt(dist2(p, q)); }


ld len(ln l)         { return sqrt(dist2(l.p, l.q)); }
ld areaC(circle c)   { return PI*c.r*c.r; }
//How far CW you have to rotate l until it's parallel to the x axis, from 0 to 2*PI
ld angle(ln l)		{ 
	pt p = ((l.q-l.p)/len(l));
	if(asin(p.y)>=0)
		return acos(p.x); 
	else{
		return 2*PI - acos(p.x);
	}
}
//How far you CW you have to rotate j until it's parallel to l, from 0 to 2*PI
ld angle(ln l, ln j){
	ld x = angle(j) - angle(l);
	if(x < 0)
		x += 2*PI;
	return x;
}
//Less than PI if abc are going clockwise
ld angle(pt a, pt b, pt c){
	return angle(ln(b, a), ln(b, c));
}


pt rotateCCW90(pt p)   { return pt(-p.y,p.x); }
pt rotateCW90(pt p)    { return pt(p.y,-p.x); }
pt rotateCCW(pt p, ld t) { 
  return pt(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t)); 
}
pt rotatePA(pt p, ld t) { 
  return rotateCCW(p, -t);
}
pt rotatePPA(pt p, pt q, ld t) { 
  return rotatePA(p-q, t) + q;
}

// assuming a != b
pt projectPL(pt a, ln l) {
  return a + (l.p-a)*dot(l.q-a, l.p-a)/dist2(a, l.p);
}

pt projectPS(pt a, ln l) {
  if (l.p == l.q) return l.p;
  ld r = dot(l.q-a, l.p-a)/dist2(a, l.p);
  if (r < 0) return l.p;
  if (r > 1) return l.q;
  return projectPL(a, l);
}

pt reflectPL(pt p, ln l){
	return projectPL(p, l)*2 - p;
}

ln reverseS(ln l){
	return ln(l.q, l.p);
}

ld distancePL(pt a, ln l){
	return sqrt(dist2(a, projectPL(a, l)));
}

ld distancePS(pt a, ln l) {
  return sqrt(dist2(a, projectPS(a, l)));
}

bool onPL(pt p, ln l){
	return dist2(p, projectPL(p, l)) < EPS;
}


bool parallelLL(ln l, ln m) { 
  return fabs(cross(l.p-l.q, m.p-m.q)) < EPS; 
}

bool equalLL(ln l, ln m) { 
  return onPL(m.p, l) && onPL(m.q, l);
}

//True only if the orientation is the same too
bool equalSS(ln l, ln m){
	return l.p==m.p && l.q == m.q;
}

bool clockwisePPP(pt a, pt b, pt c){
	return cross(c-b, c-a)>0;
}

//True if IN BUT NOT ON
bool inPH(pt p, ln l){
	return clockwisePPP(l.p, l.q, p) ;
}


bool intersectSS(ln a, ln b) {
  if(equalLL(a, b)){
  	return !(dot(b.p-a.p, b.p-a.q) > 0 && dot(b.q-a.p, b.q-a.q) > 0 && dot(b.p-a.q, b.q-a.q) > 0);
  }
  return ((!inPH(a.p, b) && !inPH(a.q, reverseS(b))) || (!inPH(a.p, reverseS(b)) && !inPH(a.q, b))) &&
         ((!inPH(b.p, a) && !inPH(b.q, reverseS(a))) || (!inPH(b.p, reverseS(a)) && !inPH(b.q, a)));
}


pt intersectionLL(ln l, ln m) {
  pt b=l.q-l.p, d=m.p-m.q, c=m.p-l.p;
  return l.p + b*cross(c, d)/cross(b, d);
}

pt midpointS(ln l){
	return (l.p+l.q)/2;
}

ln perpendicularS(ln l){
	pt m = midpointS(l);
	return ln(rotateCW90(l.p-m)+m, rotateCCW90(l.p-m)+m);
}

ln rotateLP(ln l, pt p, ld a){
	return ln(rotatePPA(l.p, p, a), rotatePPA(l.q, p, a));
}

ln perpendicularPL(pt p, ln l){
	return ln(p, reflectPL(p, l));
}

circle circumcirclePPP(pt a, pt b, pt c) {
  pt p = intersectionLL(perpendicularS(ln(a, b)), perpendicularS(ln(a, c)));
  ld r = dist(p, a);
  return circle(p, r);
}

circle incirclePPP(pt a, pt b, pt c){
	pt p = (a*dist(b, c) + b*dist(a, c) + c*dist(a, b))/((dist(a,b)+dist(a,c)+dist(b,c)));
	ld r = cross(b-a,c-a)/(dist(a,b)+dist(a,c)+dist(b,c));
}

bool onPG(pt p, const polygon &g) {
  for (int i = 0; i < g.v.size(); i++)
    if (projectPS(p, g.v[i]) == p)
      return true;
  return false;
}

//Returns true if IN BUT NOT ON
bool inPG(pt p, const polygon &g) {
  if(onPG(p, g)) return false;
  bool c = false;
  for (int i = 0; i < g.v.size(); i++){
    if ((g.v[i].p.y <= p.y && p.y < g.v[i].q.y || 
      g.v[i].q.y <= p.y && p.y < g.v[i].p.y) &&
      p.x < g.v[i].p.x + (g.v[i].q.x - g.v[i].p.x) * (p.y - g.v[i].p.y) / (g.v[i].q.y - g.v[i].p.y))
      c = !c;
  }
  return c;
}

bool intersectSL(ln m, ln l){
  if(equalLL(l, m)){
  	return true;
  }
  //cout << l << m << endl;
  //cout << ((!inPH(m.p, l) && !inPH(m.q, reverseS(l))) || (!inPH(m.p, reverseS(l)) && !inPH(m.q, l))) << endl;
  return ((!inPH(m.p, l) && !inPH(m.q, reverseS(l))) || (!inPH(m.p, reverseS(l)) && !inPH(m.q, l)));
}

vector<pt> intersectLC(ln l, circle c) {
  vector<pt> ans;
  pt p = projectPL(c.c, l);
  ld d1 = dist(p, c.c);
  ld d2 = c.r*c.r - d1*d1;
  if(d2<-EPS) return ans;
  if(d2<EPS) {
  	ans.push_back(p);
  	return ans;
  }
  ans.push_back(p+(l.q-l.p)*d2/len(l));
  ans.push_back(p-(l.q-l.p)*d2/len(l));
	return ans;
}

vector<pt> intersectCC(circle c, circle d) {
  vector<pt> ans;
  ld d1 = dist(c.c, d.c);
  if (d1 > c.r+d.r || d1+min(c.r, d.r) < max(c.r, d.r)) return ans;
  ld d2 = (d1*d1-c.r*c.r+d.r*d.r)/(2*d1);
  ld d3 = sqrt(c.r*c.r-d2*d2);
  pt v = (d.c-c.c)/d1;
  ans.push_back(c.c+v*d2 + rotateCCW90(v)*d3);
  if (d3 > 0)
    ans.push_back(c.c+v*d2 - rotateCCW90(v)*d3);
  return ans;
}

ld areaG(const polygon &g) {
  ld area = 0;
  for(int i = 0; i < g.v.size(); i++) {
    area += cross(g.v[i].p, g.v[i].q);
  }
  return area / 2.0;
}

pt centroidG(const polygon &g) {
  pt c(0,0);
  for (int i = 0; i < g.v.size(); i++){
    c = c + (g.v[i].p+g.v[i].q)*cross(g.v[i].p, g.v[i].q);
  }
  return c / (6.0 * areaG(g));
}

vector<pt> intersectionLG(ln l, const polygon &g){
	vector<pt> ans;
	for (int i = 0; i < g.v.size(); i++){
    if(intersectSL(g.v[i],l)){
    	pt p = intersectionLL(g.v[i], l);
    	if(ans.size()>0 && (ans[ans.size()-1] == p|| ans[0] == p)) continue; 
    	ans.push_back(p);
    }
  }
  return ans;
}

//finds all INTERSECTION POINTS (not the intersection of interiors)
//Not guaranteed to return in any nice order...
vector<pt> intersectionGG(const polygon &g, const polygon &h){
	vector<pt> ans;
	for (int i = 0; i < g.v.size(); i++){
    vector<pt> v = intersectionLG(g.v[i], h);
    for(int j=0; j<v.size(); j++){
    	//SLOW
    	if(find(ans.begin(), ans.end(), v[j]) == ans.end()) continue;
    	ans.push_back(v[j]); 
    }
  }
  return ans;
}


/*
// tests whether or not a given polygon (in CW or CCW order) is simple
bool IsSimple(const vector<pt> &p) {
  for (int i = 0; i < p.size(); i++) {
    for (int k = i+1; k < p.size(); k++) {
      int j = (i+1) % p.size();
      int l = (k+1) % p.size();
      if (i == l || j == k) continue;
      if (SegmentsIntersect(p[i], p[j], p[k], p[l])) 
        return false;
    }
  }
  return true;
}
*/
int main() {
	pt p(0,0);
	int n;
	ld w, v, u;
	cin >> n >> w >> u >> v;
	vector<pt> g;
	for(int i=0; i<n; i++){
		ld x, y;
		cin >> x >> y;
		g.push_back(pt(x, y));
	}
	polygon bus(g);
	cout << setprecision(12) << fixed;
	if(intersectionLG(ln(pt(-2*EPS, 0), pt(u-2*EPS, v)), bus).size()==0){
		cout << w/v;
		return 0;
	}
	ld lo = 0;
	ld hi = 1000000000;
	for(int i=0; i<90; i++){
		ld mid = (hi+lo)/2;
		ln l = ln(pt(mid, 0), pt(mid+u, v));
		//cout << intersectionLG(l, bus).size() << endl;
		if(intersectionLG(l, bus).size()>0){
			lo = mid;
		}
		else{
			hi = mid;
		}
	}
	
	cout << hi/u+w/v << endl;
	return 0;
}