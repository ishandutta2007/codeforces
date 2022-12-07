#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define mp make_pair
#define EPS 1e-10
#define maxn 1005
using namespace std;
const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;
typedef long long ll;
typedef pair<int,int> P;
int n;
struct Point{
	double x,y;
	Point(double x = 0.0,double y = 0.0): x(x),y(y) {}
	Point operator + (Point p){
		return Point(x + p.x,y + p.y);
	}
	Point operator - (Point p){
		return Point(x - p.x,y - p.y);
	}
	Point operator * (double lambda){
		return Point(x * lambda,y * lambda);
	}
	Point operator / (double lambda){
		return Point(x / lambda,y / lambda);
	}
	double norm(){
		return x * x + y * y;
	}
	double abs_(){
		return sqrt(norm());
	}
	double pol(){
		return atan2(y,x);
	}
	bool operator == (const Point &p)const
	{
		return abs(x - p.x) < EPS && abs(y - p.y) < EPS;
	}
	bool operator < (const Point &p)const
	{
		if(abs(x - p.x) < EPS) return y - p.y < -EPS;
		else return x - p.x < EPS;
	}
};
typedef Point Vector;
double dot(Vector a,Vector b){
	return a.x * b.x + a.y * b.y;
}
double det(Vector a,Vector b){
	return a.x * b.y - a.y * b.x;
}
struct Segment{
	Point p1,p2;
	Segment(Point p1 = Point(),Point p2 = Point()): p1(p1),p2(p2) {}
	
	void print(){
		printf("p1: %.1f %.1f, p2: %.1f %.1f\n",p1.x,p1.y,p2.x,p2.y);
	}
	
	Vector vec(){
		return p2 - p1;
	}
};
typedef Segment Line;
int ccw(Point p0,Point p1,Point p2){
	Vector a = p1 - p0,b = p2 - p0;
	if(det(a,b) > EPS) return 1;
	else if(det(a,b) < -EPS) return -1;
	else if(dot(a,b) < -EPS) return 2;
	else if(a.norm() - b.norm() < -EPS) return -2;//Online-front
	else return 0;//On-segment
}
bool intersect(Segment s1,Segment s2){
	return ccw(s1.p1,s1.p2,s2.p1) * ccw(s1.p1,s1.p2,s2.p2) <= 0 && ccw(s2.p1,s2.p2,s1.p1) * ccw(s2.p1,s2.p2,s1.p2) <= 0;
}
Point proj(Point p,Line l){
	Vector a = l.p2 - l.p1,b = p - l.p1;
	return l.p1 + a * (dot(a,b) / a.norm());
}
Point CrossPoint(Segment s1,Segment s2){
	Point A = proj(s2.p1,s1),B = proj(s2.p2,s1);
	double p1A = (s2.p1 - A).abs_(),p2B = (s2.p2 - B).abs_();
	return A + (B - A) * (p1A / (p2B + p1A));
}
int gcd(int x,int y){
	if(y == 0) return x;
	return gcd(y,x % y);
}
Segment sg;
vector <Segment> s,ver,nonver;
vector <P> cross;
ll calc(int x){
	cross.clear();
	for(int i=0;i<x;i++){
		if(intersect(s[i],s[x])){
			Point p = CrossPoint(s[i],s[x]);
			int ok = 0;
			if(abs(p.x - (int)p.x) < EPS){
				p.x = (int)p.x;
				ok++;
			}else if(abs(p.x - ((int)p.x + 1)) < EPS){
				p.x = (int)p.x + 1;
				ok++;
			}
			if(abs(p.y - (int)p.y) < EPS){
				p.y = (int)p.y;
				ok++;
			}else if(abs(p.y - ((int)p.y + 1)) < EPS){
				p.y = (int)p.y + 1;
				ok++;
			}
			if(ok == 2) cross.push_back(mp(p.x,p.y));
		}
	}
	sort(cross.begin(),cross.end());
	cross.erase(unique(cross.begin(),cross.end()),cross.end());
	Vector v = s[x].p2 - s[x].p1;
	return gcd(abs((int)v.x),abs((int)v.y)) + 1 - (ll)cross.size();
}
bool cmpver(const Segment &s1,const Segment &s2){
	if(abs(s1.p1.y - s2.p1.y) < EPS) return s1.p2.x < s2.p2.x;
	return s1.p1.y < s2.p1.y;
}
bool cmpnonver(Segment s1,Segment s2){
	if(abs(s1.p1.x - s2.p1.x) < EPS) return s1.p1.y < s2.p1.y;
	return s1.p1.x < s2.p1.x;
}
bool delver[maxn],delnonver[maxn];
int main(){
	scanf("%d",&n);
	ll ans = 0;
	for(int i=1;i<=n;i++){
		scanf("%lf%lf%lf%lf",&sg.p1.x,&sg.p1.y,&sg.p2.x,&sg.p2.y);
		if(sg.p1.x == sg.p2.x){
			if(sg.p1.y > sg.p2.y) swap(sg.p1.y,sg.p2.y);
			ver.push_back(sg);
		}else{
			if(sg.p1.x > sg.p2.x){
				swap(sg.p1.y,sg.p2.y);
				swap(sg.p1.x,sg.p2.x);
			}
			nonver.push_back(sg);
		}
	}
	sort(ver.begin(),ver.end(),cmpver);
	for(int i=0;i<(int)ver.size();i++){
		if(delver[i]) continue;
		delver[i] = true;
		double miny = ver[i].p1.y,maxy = ver[i].p2.y;
		for(int j=i+1;j<(int)ver.size();j++){
			if(abs(ver[j].p1.x - ver[i].p1.x) < EPS){
				if(ver[j].p1.y - maxy < EPS){
					maxy = max(maxy,ver[j].p2.y);
					delver[j] = true;
				}
			}
		}
		s.push_back(Segment(ver[i].p1,Point(ver[i].p1.x,maxy)));
	}
	sort(nonver.begin(),nonver.end(),cmpnonver);
	for(int i=0;i<(int)nonver.size();i++){
		if(delnonver[i]) continue;
		delnonver[i] = true;
		Point minp = nonver[i].p1,maxp = nonver[i].p2;
		for(int j=i+1;j<(int)nonver.size();j++){
			int type = ccw(minp,maxp,nonver[j].p1);
			if(type == 0){
				type = ccw(minp,maxp,nonver[j].p2);
				if(type == -2) maxp = nonver[j].p2;
				if(abs(type) != 1) delnonver[j] = true;
			}
		}
		s.push_back(Segment(minp,maxp));
	}
	for(int i=0;i<(int)s.size();i++){
		ans += calc(i);
	}
	printf("%I64d\n",ans);
	return 0;
}