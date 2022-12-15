#include <bits/stdc++.h>
using namespace std;
using lli = long long;

const double EPS=1e-10;

struct vec{
    double x,y;
    vec() {}
    vec(double x,double y):x(x),y(y) {}
    vec operator-(const vec &rhs)const {
        return vec(x-rhs.x,y-rhs.y);
    }
    vec operator+(const vec &rhs)const {
        return vec(x+rhs.x,y+rhs.y);
    }
    vec operator*(const double rhs)const {
        return vec(x*rhs,y*rhs);
    }
    double cross(const vec &rhs)const {
        return x*rhs.y-y*rhs.x;
    }
    double dot(const vec &rhs)const {
        return x*rhs.x+y*rhs.y;
    }
    double len() const {
        return sqrt(dot(*this));
    }
}arr[100000],p;
int n;

double get_dist(vec o,vec v, vec p) {
    double ret = min(p.len(), (p-v).len());
    if(fabs(p.cross(v))<EPS) return ret;

    double dt=p.dot(v) / v.dot(v);
    if(dt<-EPS || dt>1+EPS) return ret;
    return min(ret, (p-(v*dt)).len());
}
int main() {
    scanf("%d%lf%lf",&n,&p.x,&p.y);
    for(int i=0;i<n;i++) scanf("%lf%lf",&arr[i].x,&arr[i].y);

    double mx=0,mn=1e9;
    for(int i=0;i<n;i++) {
        double d=get_dist(arr[i],arr[(i+1)%n]-arr[i],p-arr[i]);
        mx = max(mx, d); mn = min(mn,d);
        mx = max(mx,(p-arr[i]).len());
    }
    double PI = acos(-1);
    printf("%.8lf\n",mx*mx*PI - mn*mn*PI);
    
    return 0;
}