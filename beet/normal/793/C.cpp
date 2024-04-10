#include<bits/stdc++.h>
#define EPS (1e-10)
#define equals(a,b) (fabs((a)-(b)) < EPS)
#define PI 3.141592653589793238
#define int long long
using namespace std;

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

struct Point{
  double x,y;
  Point(){}
  Point(double x,double y) :x(x),y(y){}
  Point operator + (Point p) {return Point(x+p.x,y+p.y);}
  Point operator - (Point p) {return Point(x-p.x,y-p.y);}
  Point operator * (double k) {return Point(x*k,y*k);}
  Point operator / (double k) {return Point(x/k,y/k);}
  double norm(){return x*x+y*y;}
  double abs(){return sqrt(norm());}

  bool operator < (const Point &p) const{
    return x!=p.x ? x < p.x : y < p.y;
  }

  bool operator == (const Point &p) const{
    return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS;
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

typedef Point Vector;
typedef vector<Point> Polygon;

struct Segment{
  Point p1,p2;
  Segment(){}
  Segment(Point p1, Point p2):p1(p1),p2(p2){}
};
typedef Segment Line;

struct Circle{
  Point c;
  double r;
  Circle(){}
  Circle(Point c,double r):c(c),r(r){}
};

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

int ccw(Point p0,Point p1,Point p2){
  Vector a = p1-p0;
  Vector b = p2-p0;
  if(cross(a,b) > EPS) return COUNTER_CLOCKWISE;
  if(cross(a,b) < -EPS) return CLOCKWISE;
  if(dot(a,b) < -EPS) return ONLINE_BACK;
  if(a.norm()<b.norm()) return ONLINE_FRONT;
  return ON_SEGMENT;
}

bool intersect(Point p1,Point p2,Point p3,Point p4){
  return (ccw(p1,p2,p3)*ccw(p1,p2,p4) <= 0 &&
	  ccw(p3,p4,p1)*ccw(p3,p4,p2) <= 0 );
}

bool intersect(Segment s1,Segment s2){
  return intersect(s1.p1,s1.p2,s2.p1,s2.p2);
}

double getDistanceLP(Line l,Point p){
  return abs(cross(l.p2-l.p1,p-l.p1)/abs(l.p2-l.p1));
}

double getDistanceSP(Segment s,Point p){
  if(dot(s.p2-s.p1,p-s.p1) < 0.0 ) return abs(p-s.p1);
  if(dot(s.p1-s.p2,p-s.p2) < 0.0 ) return abs(p-s.p2);
  return getDistanceLP(s,p);
}

double getDistance(Segment s1,Segment s2){
  if(intersect(s1,s2)) return 0.0;
  return min(min(getDistanceSP(s1,s2.p1),getDistanceSP(s1,s2.p2)),
	     min(getDistanceSP(s2,s1.p1),getDistanceSP(s2,s1.p2)));
}

Point getCrossPoint(Segment s1,Segment s2){
  Vector base=s2.p2-s2.p1;
  double d1=abs(cross(base,s1.p1-s2.p1));
  double d2=abs(cross(base,s1.p2-s2.p1));
  double t=d1/(d1+d2);
  return s1.p1+(s1.p2-s1.p1)*t;
}


pair<Point,Point> getCrossPoints(Circle c,Line l){
  Vector pr=project(l,c.c);
  Vector e=(l.p2-l.p1)/abs(l.p2-l.p1);
  double base=sqrt(c.r*c.r-norm(pr-c.c));
  return make_pair(pr+e*base,pr-e*base);
}


double arg(Vector p){
  return atan2(p.y,p.x);
}

Vector polar(double a,double r){
  return Point(cos(r)*a,sin(r)*a);
}

pair<Point,Point> getCrossPoints(Circle c1,Circle c2){
  double d=abs(c1.c-c2.c);
  double a=acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));
  double t=arg(c2.c-c1.c);
  return make_pair(c1.c+polar(c1.r,t+a),c1.c+polar(c1.r,t-a));
}

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
  Polygon u,l;
  if(s.size()<3) return s;
  sort(s.begin(),s.end());
  u.push_back(s[0]);
  u.push_back(s[1]);
  l.push_back(s[s.size()-1]);
  l.push_back(s[s.size()-2]);
  for(int i=2;i<(int)s.size();i++){
    for(int n=u.size();n>=2&&ccw(u[n-2],u[n-1],s[i])!=CLOCKWISE;n--){
      u.pop_back();
    }
    u.push_back(s[i]);
  } 
  for(int i=s.size()-3;i>=0;i--){
    for(int n=l.size();n>=2&&ccw(l[n-2],l[n-1],s[i])!=CLOCKWISE;n--){
      l.pop_back();
    }
    l.push_back(s[i]);
  }
  reverse(l.begin(),l.end());
  for(int i=u.size()-2;i>=1;i--) l.push_back(u[i]);
  return l;
} 

bool isConvex(Polygon p){
  bool f=1;
  int n=p.size();
  for(int i=0;i<n;i++){
    int t=ccw(p[(i+n-1)%n],p[i],p[(i+1)%n]);
    f&=t!=CLOCKWISE;
  }
  return f;
}

double area(Polygon s){
  double res=0;
  for(int i=0;i<(int)s.size();i++){
    res+=cross(s[i],s[(i+1)%s.size()])/2.0;
  }
  return abs(res);
}


Point getCrossPointLL(Line l1,Line l2){
  double a=cross(l1.p2-l1.p1,l2.p2-l2.p1);
  double b=cross(l1.p2-l1.p1,l1.p2-l2.p1);
  if(abs(a)<EPS&&abs(b)<EPS) return l2.p1;
  return l2.p1+(l2.p2-l2.p1)*(b/a);
}

Polygon convexCut(Polygon p,Line l){
  Polygon q;
  for(int i=0;i<(int)p.size();i++){
    Point a=p[i],b=p[(i+1)%p.size()];
    if(ccw(l.p1,l.p2,a)!=-1) q.push_back(a);
    if(ccw(l.p1,l.p2,a)*ccw(l.p1,l.p2,b)<0)
      q.push_back(getCrossPointLL(Line(a,b),l));
  }
  return q;
}

Line bisector(Point p1,Point p2){
  Circle c1=Circle(p1,abs(p1-p2)),c2=Circle(p2,abs(p1-p2));
  pair<Point,Point> p=getCrossPoints(c1,c2);
  if(cross(p2-p1,p.first-p1)>0) swap(p.first,p.second);
  return Line(p.first,p.second);
}


Vector spin(Vector v,double theta){
  Vector res;
  res.x=cos(theta)*v.x-sin(theta)*v.y;
  res.y=sin(theta)*v.x+cos(theta)*v.y;
  return res;
}

vector<Line> corner(Line l1,Line l2){
  vector<Line> res;
  if(isParallel(l1,l2)){
    double d=getDistanceLP(l1,l2.p1)/2.0;
    Vector v1=l1.p2-l1.p1;
    v1=v1/v1.abs()*d;
    Point p=l2.p1+spin(v1,90.0*(PI/180.0));
    double d1=getDistanceLP(l1,p);
    double d2=getDistanceLP(l2,p);
    if(abs(d1-d2)>d){
      p=l2.p1+spin(v1,-90.0*(PI/180.0));
    }
    res.push_back(Line(p,p+v1));
  }else{
    Point p=getCrossPointLL(l1,l2);
    Vector v1=l1.p2-l1.p1,v2=l2.p2-l2.p1;
    v1=v1/v1.abs();
    v2=v2/v2.abs();
    res.push_back(Line(p,p+(v1+v2)));
    res.push_back(Line(p,p+spin(v1+v2,90.0*(PI/180.0))));
  }
  return res;
}

double diameter(Polygon s){
  Polygon p=s;
  int n=p.size();
  if(n==2) return abs(p[0]-p[1]);
  int i=0,j=0;
  for(int k=0;k<n;k++){
    if(p[i].x<p[k].x) i=k;
    if(p[j].x>p[k].x) j=k;
  }
  //cout<<i<<" "<<j<<endl;
  double res=0;
  int si=i,sj=j;
  do{
    //cout<<i<<" "<<j<<endl;
    res=max(res,abs(p[i]-p[j]));
    if(cross(p[(i+i)%n]-p[i],p[(j+1)%n]-p[j])<0.0){
      i=(i+1)%n;
    }else{
      j=(j+1)%n;
    }
  }while(i!=si||j!=sj);
  return res;
}

signed main(){
  //ios::sync_with_stdio(0);
  //cin.tie(0);
  int n;
  //cin>>n;
  scanf("%lld",&n);
  Polygon r(4);
  //cin>>r[0]>>r[2];
  scanf("%lf %lf",&(r[0].x),&(r[0].y));
  scanf("%lf %lf",&(r[2].x),&(r[2].y));
  r[1]=Point(r[2].x,r[0].y);
  r[3]=Point(r[0].x,r[2].y);
  Segment l[4];
  l[0]=Segment(r[0],r[1]);
  l[1]=Segment(r[1],r[2]);
  l[2]=Segment(r[2],r[3]);
  l[3]=Segment(r[3],r[0]);
  Polygon p(n),v(n);
  for(int i=0;i<n;i++){
    //cin>>p[i]>>v[i];
    scanf("%lf %lf",&(p[i].x),&(p[i].y));
    scanf("%lf %lf",&(v[i].x),&(v[i].y));
  }
  double INF = 1e8;
  double L=0,R=INF;
  bool f=1;
  for(int i=0;i<n;i++){
    int c=contains(r,p[i]);
    if(equals(abs(v[i]),0)){
      if(c==2) continue;
      f=0;
      break;
    }
    Segment s=Segment(p[i],p[i]+v[i]*INF);
    int fs=0,fp=0;
    for(int j=0;j<4;j++){
      fs+=intersect(s,l[j]);
      fp+=equals(getDistanceSP(s,r[j]),0.0);
      //cout<<j<<" "<<getDistanceLP(s,r[j])<<endl;
      //cout<<r[j]<<endl;
      //cout<<s.p1<<endl;
      //cout<<s.p2<<endl;
    }
    
    if(c==0){
      if((fs==0)||(fs==2&&fp==1)||(fs==3&&fp==2)){	
	f=0;
	break;
      }
    }
    //cout<<c<<" "<<fs<<" "<<fp<<endl;
    if(c==1){
      if((fs==2&&fp==1)||(fs==3&&fp==2)){	
	f=0;
	break;
      }
    }
    
    //cout<<fs<<" "<<fp<<endl;
    double tL=INF,tR=0;
    if(c==2) tL=0;
    for(int j=0;j<4;j++){      
      if(!intersect(s,l[j])) continue;
      double xL=0,xR=INF;
      for(int k=0;k<120;k++){
	double xM=(xL+xR)/2;
	Segment t=Segment(p[i],p[i]+v[i]*xM);
	if(intersect(t,l[j])) xR=xM;
	else xL=xM;
      }
      //cout<<xL<<"~"<<xR<<endl;
      tL=min(tL,xR);
      tR=max(tR,xR);
    }
    //cout<<tL<<" "<<tR<<endl;
    L=max(L,tL);
    R=min(R,tR);
  }
  if(f&&!equals(L,R)&&(L<R)) printf("%.20f\n",L);
  else cout<<-1<<endl;
  return 0;
}