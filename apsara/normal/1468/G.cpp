#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010

int n, h;

namespace Plane_Geometry{

    const int Maxn = 100010;
    const double eps = 1e-6;
    const double PI = acos(-1.0);
    #define sqr(x) ((x) * (x))

    int dcmp(double x){ return (fabs(x) < eps) ? 0 : (x < 0 ? -1 : 1); }

	struct point{

        double x, y;

        point(double x = 0, double y = 0) : x(x), y(y) {}
        bool operator < (const point &p) const{
            if(fabs(x - p.x) > eps) return x < p.x;
            return y < p.y - eps;
        }
        point operator + (const point &p) const{ return {x + p.x, y + p.y}; }
        point operator - (const point &p) const{ return {x - p.x, y - p.y}; }
        point operator -= (const point &p){ x -= p.x; y -= p.y; return *this; }
        double operator * (const point &p) const{ return x * p.x + y * p.y; }
        point operator * (const double &k) const{ return {x * k, y * k}; }
        point operator / (const double &k) const{ return {x / k, y / k}; }
        point operator /= (const double &k){ x /= k; y /= k; return *this; }
        double operator ^ (const point &p) const{ return x * p.y - y * p.x; }
        bool operator == (const point &p) const{ return fabs(x - p.x) < eps && fabs(y - p.y) < eps; }
        double module() const{ return hypot(x, y); }
        point norm() const{ return *this / module(); }
        point anticlockwise_orthogonal() const{ return {-y, x}; }
        point clockwise_orthogonal() const{ return {y, -x}; }
        double dist(const point &p) const{ return (*this - p).module(); }

        bool on_segment(const point &a, const point &b) const{
            return fabs(((a - *this) ^ (b - *this))) < eps && ((a - *this) * (b - *this)) < eps;
        }

		int Read(){ return scanf("%lf %lf", &x, &y); }
		void Print(){ printf("%.10f %.10f\n", x, y); }
	};



	point lines_intersect(const point &a, const point &b, const point &c, const point &d){
		double p = (b - a) ^ (c - a), q = (b - a) ^ (d - a);
		return (c * q - d * p) / (q - p);
	}
}

Plane_Geometry::point p[MAXN], tp, eye;


void read(){
    scanf("%d %d", &n, &h);
    for(int i = 1; i <= n; ++i)
        p[i].Read();
}

void work(){
    double ans = 0;
    eye = {p[n].x, p[n].y + h};
    tp = p[n];
    for(int i = n; i > 1; --i){
        if(((eye - p[i]) ^ (eye - tp)) > Plane_Geometry::eps) tp = p[i];
        if(((eye - tp) ^ (p[i] - p[i - 1])) > Plane_Geometry::eps) continue;
        if(fabs((eye - tp) ^ (p[i] - p[i - 1])) < Plane_Geometry::eps){
            if(fabs((eye - p[i]) ^ (eye - p[i - 1])) < Plane_Geometry::eps)
                ans += (p[i] - p[i - 1]).module();
        }
        else{
            p[0] = Plane_Geometry::lines_intersect(eye, tp, p[i], p[i - 1]);
            if(p[0].on_segment(p[i], p[i - 1]))
                ans += (p[0] - p[i - 1]).module();
            else if((p[0] - p[i]).module() < (p[0] - p[i - 1]).module())
                ans += (p[i] - p[i - 1]).module();
        }
    }
    printf("%.10f\n", ans);
}

int main() {
//    int T;
//    for(scanf("%d", &T); T; --T){
        read();
        work();
//    }

    return 0;
}