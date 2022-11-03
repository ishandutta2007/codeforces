#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

#define double long double

struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

#define EPS (1e-20)
#define equals(a,b) (fabs((a)-(b)) < EPS)
#define PI 3.141592653589793238

// COUNTER CLOCKWISE
static const int CCW_COUNTER_CLOCKWISE = 1;
static const int CCW_CLOCKWISE = -1;
static const int CCW_ONLINE_BACK = 2;
static const int CCW_ONLINE_FRONT = -2;
static const int CCW_ON_SEGMENT = 0;

//Intercsect Circle & Circle
static const int ICC_SEPERATE = 4;
static const int ICC_CIRCUMSCRIBE = 3;
static const int ICC_INTERSECT = 2;
static const int ICC_INSCRIBE = 1;
static const int ICC_CONTAIN = 0;

struct Point{
  double x,y;
  Point(){}
  Point(double x,double y) :x(x),y(y){}
  Point operator+(Point p) {return Point(x+p.x,y+p.y);}
  Point operator-(Point p) {return Point(x-p.x,y-p.y);}
  Point operator*(double k){return Point(x*k,y*k);}
  Point operator/(double k){return Point(x/k,y/k);}
  double norm(){return x*x+y*y;}
  double abs(){return sqrt(norm());}

  bool operator < (const Point &p) const{
    return x!=p.x?x<p.x:y<p.y;
    //grid-point only
    //return !equals(x,p.x)?x<p.x:!equals(y,p.y)?y<p.y:0;
  }

  bool operator == (const Point &p) const{
    return fabs(x-p.x)<EPS && fabs(y-p.y)<EPS;
  }
};

struct EndPoint{
  Point p;
  int seg,st;
  EndPoint(){}
  EndPoint(Point p,int seg,int st):p(p),seg(seg),st(st){}
  bool operator<(const EndPoint &ep)const{
    if(p.y==ep.p.y) return st<ep.st;
    return p.y<ep.p.y;
  }
};

istream &operator >> (istream &is,Point &p){
  is>>p.x>>p.y;
  return is;
}

ostream &operator << (ostream &os,Point p){
  os<<fixed<<setprecision(12)<<p.x<<" "<<p.y;
  return os;
}

bool sort_x(Point a,Point b){
  return a.x!=b.x?a.x<b.x:a.y<b.y;
}

bool sort_y(Point a,Point b){
  return a.y!=b.y?a.y<b.y:a.x<b.x;
}

typedef Point Vector;
typedef vector<Point> Polygon;

istream &operator >> (istream &is,Polygon &p){
  for(int i=0;i<(int)p.size();i++) is>>p[i];
  return is;
}

struct Segment{
  Point p1,p2;
  Segment(){}
  Segment(Point p1, Point p2):p1(p1),p2(p2){}
};
typedef Segment Line;

istream &operator >> (istream &is,Segment &s){
  is>>s.p1>>s.p2;
  return is;
}

struct Circle{
  Point c;
  double r;
  Circle(){}
  Circle(Point c,double r):c(c),r(r){}
};

istream &operator >> (istream &is,Circle &c){
  is>>c.c>>c.r;
  return is;
}

double norm(Vector a){
  return a.x*a.x+a.y*a.y;
}
double abs(Vector a){
  return sqrt(norm(a));
}
double dot(Vector a,Vector b){
  return a.x*b.x+a.y*b.y;
}
double cross(Vector a,Vector b){
  return a.x*b.y-a.y*b.x;
}

Point orth(Point p){return Point(-p.y,p.x);}

bool isOrthogonal(Vector a,Vector b){
  return equals(dot(a,b),0.0);
}

bool isOrthogonal(Point a1,Point a2,Point b1,Point b2){
  return isOrthogonal(a1-a2,b1-b2);
}

bool isOrthogonal(Segment s1,Segment s2){
  return equals(dot(s1.p2-s1.p1,s2.p2-s2.p1),0.0);
}

bool isParallel(Vector a,Vector b){
  return equals(cross(a,b),0.0);
}

bool isParallel(Point a1,Point a2,Point b1,Point b2){
  return isParallel(a1-a2,b1-b2);
}

bool isParallel(Segment s1,Segment s2){
  return equals(cross(s1.p2-s1.p1,s2.p2-s2.p1),0.0);
}

Point project(Segment s,Point p){
  Vector base=s.p2-s.p1;
  double r=dot(p-s.p1,base)/norm(base);
  return s.p1+base*r;
}

Point reflect(Segment s,Point p){
  return p+(project(s,p)-p)*2.0;
}

double arg(Vector p){
  return atan2(p.y,p.x);
}

Vector polar(double a,double r){
  return Point(cos(r)*a,sin(r)*a);
}

int ccw(Point p0,Point p1,Point p2);
bool intersectSS(Point p1,Point p2,Point p3,Point p4);
bool intersectSS(Segment s1,Segment s2);
bool intersectPS(Polygon p,Segment l);
int intersectCC(Circle c1,Circle c2);
bool intersectSC(Segment s,Circle c);
double getDistanceLP(Line l,Point p);
double getDistanceSP(Segment s,Point p);
double getDistanceSS(Segment s1,Segment s2);
Point getCrossPointSS(Segment s1,Segment s2);
Point getCrossPointLL(Line l1,Line l2);
Polygon getCrossPointCL(Circle c,Line l);
Polygon getCrossPointCC(Circle c1,Circle c2);
int contains(Polygon g,Point p);
Polygon andrewScan(Polygon s);
Polygon convex_hull(Polygon ps);
double diameter(Polygon s);
bool isConvex(Polygon p);
double area(Polygon s);
Polygon convexCut(Polygon p,Line l);
Line bisector(Point p1,Point p2);
Vector translate(Vector v,double theta);
vector<Line> corner(Line l1,Line l2);
vector< vector<int> >
segmentArrangement(vector<Segment> &ss, Polygon &ps);

int ccw(Point p0,Point p1,Point p2){
  Vector a = p1-p0;
  Vector b = p2-p0;
  if(cross(a,b) > EPS) return CCW_COUNTER_CLOCKWISE;
  if(cross(a,b) < -EPS) return CCW_CLOCKWISE;
  if(dot(a,b) < -EPS) return CCW_ONLINE_BACK;
  if(a.norm()<b.norm()) return CCW_ONLINE_FRONT;
  return CCW_ON_SEGMENT;
}

bool intersectSS(Point p1,Point p2,Point p3,Point p4){
  return (ccw(p1,p2,p3)*ccw(p1,p2,p4) <= 0 &&
          ccw(p3,p4,p1)*ccw(p3,p4,p2) <= 0 );
}

bool intersectSS(Segment s1,Segment s2){
  return intersectSS(s1.p1,s1.p2,s2.p1,s2.p2);
}

bool intersectPS(Polygon p,Segment l){
  int n=p.size();
  for(int i=0;i<n;i++)
    if(intersectSS(Segment(p[i],p[(i+1)%n]),l)) return 1;
  return 0;
}

int intersectCC(Circle c1,Circle c2){
  if(c1.r<c2.r) swap(c1,c2);
  double d=abs(c1.c-c2.c);
  double r=c1.r+c2.r;
  if(equals(d,r)) return ICC_CIRCUMSCRIBE;
  if(d>r) return ICC_SEPERATE;
  if(equals(d+c2.r,c1.r)) return ICC_INSCRIBE;
  if(d+c2.r<c1.r) return ICC_CONTAIN;
  return ICC_INTERSECT;
}

bool intersectSC(Segment s,Circle c){
  return getDistanceSP(s,c.c)<=c.r;
}

int intersectCS(Circle c,Segment s){
  if(norm(project(s,c.c)-c.c)-c.r*c.r>EPS) return 0;
  double d1=abs(c.c-s.p1),d2=abs(c.c-s.p2);
  if(d1<c.r+EPS&&d2<c.r+EPS) return 0;
  if((d1<c.r-EPS&&d2>c.r+EPS)||(d1>c.r+EPS&&d2<c.r-EPS)) return 1;
  Point h=project(s,c.c);
  if(dot(s.p1-h,s.p2-h)<0) return 2;
  return 0;
}

double getDistanceLP(Line l,Point p){
  return abs(cross(l.p2-l.p1,p-l.p1)/abs(l.p2-l.p1));
}

double getDistanceSP(Segment s,Point p){
  if(dot(s.p2-s.p1,p-s.p1) < 0.0 ) return abs(p-s.p1);
  if(dot(s.p1-s.p2,p-s.p2) < 0.0 ) return abs(p-s.p2);
  return getDistanceLP(s,p);
}

double getDistanceSS(Segment s1,Segment s2){
  if(intersectSS(s1,s2)) return 0.0;
  return min(min(getDistanceSP(s1,s2.p1),getDistanceSP(s1,s2.p2)),
             min(getDistanceSP(s2,s1.p1),getDistanceSP(s2,s1.p2)));
}

Point getCrossPointSS(Segment s1,Segment s2){
  for(int k=0;k<2;k++){
    if(getDistanceSP(s1,s2.p1)<EPS) return s2.p1;
    if(getDistanceSP(s1,s2.p2)<EPS) return s2.p2;
    swap(s1,s2);
  }
  Vector base=s2.p2-s2.p1;
  double d1=abs(cross(base,s1.p1-s2.p1));
  double d2=abs(cross(base,s1.p2-s2.p1));
  double t=d1/(d1+d2);
  return s1.p1+(s1.p2-s1.p1)*t;
}

Point getCrossPointLL(Line l1,Line l2){
  double a=cross(l1.p2-l1.p1,l2.p2-l2.p1);
  double b=cross(l1.p2-l1.p1,l1.p2-l2.p1);
  if(abs(a)<EPS&&abs(b)<EPS) return l2.p1;
  return l2.p1+(l2.p2-l2.p1)*(b/a);
}

Polygon getCrossPointCL(Circle c,Line l){
  Polygon ps;
  Point pr=project(l,c.c);
  Vector e=(l.p2-l.p1)/abs(l.p2-l.p1);
  if(equals(getDistanceLP(l,c.c),c.r)){
    ps.emplace_back(pr);
    return ps;
  }
  double base=sqrt(c.r*c.r-norm(pr-c.c));
  ps.emplace_back(pr+e*base);
  ps.emplace_back(pr-e*base);
  return ps;
}

Polygon getCrossPointCS(Circle c,Segment s){
  Line l(s);
  Polygon res=getCrossPointCL(c,l);
  if(intersectCS(c,s)==2) return res;
  if(res.size()>1u){
    if(dot(l.p1-res[0],l.p2-res[0])>0) swap(res[0],res[1]);
    res.pop_back();
  }
  return res;
}


Polygon getCrossPointCC(Circle c1,Circle c2){
  Polygon p(2);
  double d=abs(c1.c-c2.c);
  double a=acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));
  double t=arg(c2.c-c1.c);
  p[0]=c1.c+polar(c1.r,t+a);
  p[1]=c1.c+polar(c1.r,t-a);
  return p;
}

// IN:2 ON:1 OUT:0
int contains(Polygon g,Point p){
  int n=g.size();
  bool x=false;
  for(int i=0;i<n;i++){
    Point a=g[i]-p,b=g[(i+1)%n]-p;
    if(fabs(cross(a,b)) < EPS && dot(a,b) < EPS) return 1;
    if(a.y>b.y) swap(a,b);
    if(a.y < EPS && EPS < b.y && cross(a,b) > EPS ) x = !x;
  }
  return (x?2:0);
}

Polygon andrewScan(Polygon s){
  Polygon l;
  if(s.size()<3) return s;
  sort(s.begin(),s.end());
  l.push_back(s[s.size()-1]);
  l.push_back(s[s.size()-2]);
  for(int i=s.size()-3;i>=0;i--){
    for(int n=l.size();n>=2&&
          (ccw(l[n-2],l[n-1],s[i])!=CCW_CLOCKWISE &&
           ccw(l[n-2],l[n-1],s[i])!=CCW_ONLINE_FRONT)
          ;n--){
      l.pop_back();
    }
    l.push_back(s[i]);
  }
  return l;
}

//INSERT ABOVE HERE
signed main(){
  int n;
  cin>>n;

  vector<int> rs(n),ss(n);
  for(int i=0;i<n;i++) cin>>rs[i]>>ss[i];

  using P = pair<int, int>;
  set<P> uku;
  int num=0;
  Polygon qs(n);
  for(int i=0;i<n;i++){
    if(uku.count(P(rs[i],ss[i]))) continue;
    uku.emplace(rs[i],ss[i]);
    qs[num].x=1.0/rs[i];
    qs[num].y=1.0/ss[i];
    num++;
  }
  qs.resize(num);

  qs.emplace_back(1e18,0);
  qs.emplace_back(0,1e18);
  qs=andrewScan(qs);

  //if(n>=100) return 0;

  using P = pair<int, int>;
  set<P> cand;
  for(auto p:qs){
    if(p.x==0||p.y==0) continue;
    int a=round(1.0/p.x);
    int b=round(1.0/p.y);
    //cout<<a<<" "<<b<<endl;
    cand.emplace(a,b);
  }

  vector<int> ans;
  for(int i=0;i<n;i++)
    if(cand.count(P(rs[i],ss[i])))
      ans.emplace_back(i);

  for(int i=0;i<(int)ans.size();i++){
    if(i) cout<<" ";
    cout<<ans[i]+1;
  }
  cout<<endl;
  return 0;
}