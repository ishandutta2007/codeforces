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



const double PI = acos(-1);

struct Pt{
    double x, y;
    int id;

    bool operator < (const Pt &b) const {
        return tie(x,y) < tie(b.x,b.y);
        //return atan2(y,x) < atan2(b.y,b.x);
    }
    Pt operator + (const Pt &b) const {
        return {x+b.x,y+b.y};
    }
    Pt operator - (const Pt &b) const {
        return {x-b.x,y-b.y};
    }
    Pt operator * (const double d) const {
        return {x*d,y*d};   
    }
    Pt operator / (const double d) const {
        return {x/d,y/d};   
    }
    double operator * (const Pt &b) const {
        return x*b.x + y*b.y;
    }
    double operator % (const Pt &b) const { // Cross!
        return x*b.y - y*b.x;
    }
    Pt(double xx, double yy, int _id = -1): x(xx), y(yy){ id = _id; } 
};

double Length( const Pt &p ){
    return sqrt( p.x*p.x + p.y*p.y );
}  

int ori(const Pt &a, const Pt &b, const Pt &c){
    int tmp = (c-a)%(b-a);
    if (tmp==0) return 0; //Collinear
    return tmp>0? 1: -1;
}

bool collinear(const Pt &a, const Pt &b, const Pt &c){
    return ori(a, b, c)==0; 
}

bool btw(const Pt &a, const Pt &b, const Pt &c){
    return(a-c)*(b-c)<=0; 
}

typedef Pt Vector;

double Angle( const Vector &a, const Vector &b ){
    double A = Length(a);
    double B = Length(b);
    double v = a*b;
    double theta = acos( v/A/B );  
    return theta;
}

double ang( const Pt &a){
    return atan2(a.y,a.x);
}

Vector rot(Vector vec, double a){
    return Vector(cos(a)*vec.x-sin(a)*vec.y, sin(a)*vec.x+cos(a)*vec.y);
}

Vector Normal(const Vector &v){
    return v / Length(v);
}

Pt intersect_at(const Pt &p, const Vector &v, const Pt &q, const Vector &w){
    Vector u = q-p;
    return p+v*(u%w)/(q%w);
}

const int maxn = 2001;
bool done[maxn];

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector<Pt> v;
    REP(i,n){
        int x, y; cin>>x>>y;
        Pt npt (x,y,i+1);
        v.pb(npt);
    }
    string s; cin>>s;
    Pt at (-10000000000, 0);
    REP(i,n){
        if (v[i].x>at.x){
            at = v[i];
        }
    }
    double dir = PI;
    cout<<at.id<<'\n';
    REP(i,n-1){
        done[at.id-1] = 1;
        // debug(dir);
        if (s[i] == 'L'){
            // Minimize Angle?
            Pt to (-100, -123);
            double mn = 2*PI +1;

            REP(j,n){
                if (!done[j]){
                    double aa = ang(v[j] - at) + 3*PI - dir;
                    while (aa >= PI * 2) aa-=(PI*2);
                    if (aa < mn) {
                        mn = aa; to = v[j];
                    }
                }
            }
            dir = ang(to-at);
            at = to;
        }else{
            Pt to (-100, -123);
            double mx = -1;

            REP(j,n){
                if (!done[j]){
                    double aa = ang(v[j] - at) + 3*PI - dir;
                    while (aa >= PI * 2) aa-=(PI*2);
                    if (aa > mx) {
                        mx = aa; to = v[j];
                    }
                }
            }
            dir = ang(to-at);
            at = to;
        }
        cout<<at.id<<'\n';
        done[at.id-1]=1;
    }

    
}