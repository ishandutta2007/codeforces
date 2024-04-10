#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define SQ(x) (x)*(x)
#define MNTO(a,b) a = min(a,(__typeof__(a))(b))
#define MXTO(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define debug(x) cerr<<#x<<" is "<<x<<endl
using namespace std;

// #define int ll

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"No\n"; exit(0);}

ll mpow(ll a, ll n){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mod;
        a = a*a %mod;
        n>>=1;
    }
    return re;
}

ll inv (ll b){
    if (b==1) return b;
    return (mod-mod/b) * inv(mod%b) % mod;
}

const int maxn = 1e5+5;

const double PI = acos(-1);

struct Point{
    double x, y;

    bool operator < (const Point &b) const {
        return tie(x,y) < tie(b.x,b.y);
        //return atan2(y,x) < atan2(b.y,b.x);
    }
    Point operator + (const Point &b) const {
        return {x+b.x,y+b.y};
    }
    Point operator - (const Point &b) const {
        return {x-b.x,y-b.y};
    }
    Point operator * (const double d) const {
        return {x*d,y*d};   
    }
    Point operator / (const double d) const {
        return {x/d,y/d};   
    }
    double operator * (const Point &b) const {
        return x*b.x + y*b.y;
    }
    double operator % (const Point &b) const { // Cross!
        return x*b.y - y*b.x;
    }
    Point(double xx, double yy): x(xx), y(yy){  } 
};

double Length( const Point &p ){
    return sqrt( p.x*p.x + p.y*p.y );
}  

int ori(const Point &a, const Point &b, const Point &c){
    int tmp = (c-a)%(b-a);
    if (tmp==0) return 0; //Collinear
    return tmp>0? 1: -1;
}

bool collinear(const Point &a, const Point &b, const Point &c){
    return ori(a, b, c)==0; 
}

bool btw(const Point &a, const Point &b, const Point &c){
    return(a-c)*(b-c)<=0; 
}

typedef Point Vector;

double Angle( const Vector &a, const Vector &b ){
    double A = Length(a);
    double B = Length(b);
    double v = A*B;
    double theta = acos( v/A/B );
}

Vector rot(Vector vec, double a){
    return Vector(cos(a)*vec.x-sin(a)*vec.y, sin(a)*vec.x+cos(a)*vec.y);
}

Vector Normal(const Vector &v){
    return v / Length(v);
}

Point intersect_at(const Point &p1, const Point &p2, const Point &p3, const Point &p4){
    double aa = (p2-p1)%(p3-p1);
    double bb = (p2-p1)%(p4-p1);
    if (aa == bb) {
        Point nono (17, 94887.721);
        return nono;
    }
    return (p4*aa - p3*bb) / (aa-bb);
}

bool cmp(const Point&a, const Point &b){
    return a<b; 
    //Sort by x first, then by y. 
}

vector<Point> convex_hull(vector<Point>arr){
    sort (arr.begin(), arr.end(), cmp);
    vector<Point> p;
    int m = 0; // size of p
    for (int i=0; i<arr.size(); i++){ // Lower hull
        //cout<<"On the "<<i<<"-th one. "<<arr[i].x<<' '<<arr[i].y<<'\n';
        while (m>=2&&(p[m-1]-p[m-2])%(arr[i]-p[m-2])<0){
            //Get rid of a previous point 
            //cout<<"Got rid of "<<p[m-1].x<<' '<<p[m-1].y<<'\n';
            p.pop_back(); m--;
        }
        p.push_back(arr[i]); m++;
    }
    //cout<<"Onto upper hull"<<'\n';
    int tmp = m+1; //the size of lower hull +1
    for (int i=arr.size()-2; i>=0; i--){
        //cout<<"On the "<<i<<"-th one. "<<arr[i].x<<' '<<arr[i].y<<'\n';
        while (m>=tmp&&(p[m-1]-p[m-2])%(arr[i]-p[m-2])<0){
            //cout<<"Got rid of "<<p[m-1].x<<' '<<p[m-1].y<<'\n';
            p.pop_back(); m--;
        }
        p.push_back(arr[i]); m++;
    }
    //cout<<m<<'\n';
    if (arr.size()>1) p.pop_back(); //Repeated
    return p;
}

//Segment banana 

double signedArea(Point p[], int n){
    double re = 0.0;
    for (int i=0; i<n; i++){
        re+=p[i]%p[(i+1)%n];
    }
    return re/2.0; //Cross returns twice the triangle's area
}

bool intersect(const Point a, const Point b, const Point c, const Point d){
    int abc = ori(a, b, c);
    int abd = ori(a, b, d);
    int cda = ori(c, d, a);
    int cdb = ori(c, d, b);
    if (abc==0&&abd==0){
        assert(0);
        return btw(a,b,c)||btw(a,b,d)||btw(c,d,a)||btw(c,d,b);
    }else return (abc*abd<=0&&cda*cdb<=0);
}


main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    ll re =0;
    map<Point, int> mp;
    vector<pair<Point, Point> > v;
    REP(i,n){
        double a, b, c, d; cin>>a>>b>>c>>d;
        ll np = __gcd((ll)abs(a-c), (ll)abs(b-d))+1;
        v.pb({Point (a,b), Point(c,d)});
        re += np;
    }
    REP(i,n) REP(j,i){

        Point pp = intersect_at(v[i].f, v[i].s, v[j].f, v[j].s);
        if (pp.y == 94887.721) continue;
        if (pp.x < min(v[i].f.x, v[i].s.x) || pp.x > max(v[i].f.x, v[i].s.x) ) continue;
        if (pp.x < min(v[j].f.x, v[j].s.x) || pp.x > max(v[j].f.x, v[j].s.x) ) continue;
        if (pp.y < min(v[i].f.y, v[i].s.y) || pp.y > max(v[i].f.y, v[i].s.y) ) continue;
        if (pp.y < min(v[j].f.y, v[j].s.y) || pp.y > max(v[j].f.y, v[j].s.y) ) continue;
        
        if (floor(pp.x)==pp.x && floor(pp.y) == pp.y){
            mp[pp]++;
        }
        

    }
    for (auto xx : mp){
        double M = xx.s;
        double num = 0.5 + sqrt(0.25 + 2*M);
        assert(floor(num)==num);
        re -= (ll)num; re++;
    }
    cout<<re<<'\n';
}