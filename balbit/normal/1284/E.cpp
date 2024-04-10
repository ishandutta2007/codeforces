#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for (int i=(n-1); i>=0; --i)
#define REP1(i,n) FOR(i,1,n+1)
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#ifdef BALBIT
#define IOS()
#define bug(...) fprintf(stderr,"#%d (%s) = ",__LINE__,#__VA_ARGS__),_do(__VA_ARGS__);
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y){cerr<<x<<", ";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define bug(...)
#endif
#define int ll
const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"-1\n"; exit(0);}

ll mpow(ll a, ll n, ll mo = mod){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mo;
        a = a*a %mo;
        n>>=1;
    }
    return re;
}

ll inv (ll b, ll mo = mod){
    if (b==1) return b;
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 1e5+5;
#define double long double
struct pt{
    int x, y;
};
vector<pt> v;
const double PI = acos(-1);

//double norm(double ang){
//    while (ang < 0) ang += 2*PI;
//    while (ang >= 2*PI) ang -= 2*PI;
//    return ang;
//}
int n;
ll N;
inline int f(int x){

    if (x>=N) return x-N;
    if (x<0) return x+N;
    return x;
}
inline void inc(int &x) {
    ++x; if (x>=N) x-=N;
}
inline int ord(pt x) {
    if (x.y>0) return 1;
    if (x.y<0) return 0;
    return x.x>0;
}

bool cmp(pt &a, pt &b) {
    if (ord(a)!=ord(b)) return ord(a) > ord(b);
    return a.x*b.y-a.y*b.x>0;
}

signed main(){
    IOS();
    cin>>n;
    N = n-1;
    v.resize(n);
    REP(i,n) {
        cin>>v[i].x>>v[i].y;
    }
    ll re = 0;
    REP(iter,n) {
        bug(iter);
        vector<pt> ang;
        REP(j,n) {
            if (j!=iter) {
//                double ta = acosl((-v[iter].x+v[j].x) / ((double)hypotl(v[iter].x-v[j].x,v[iter].y-v[j].y)));
//                if (v[iter].y-v[j].y>0) ta = 2*PI - ta;
                ang.pb({v[j].x-v[iter].x,v[j].y-v[iter].y});
            }
        }
        sort(ALL(ang),cmp);
#ifdef BALBIT
        cout<<"===";
        REP(i,N) {
            cout<<ang[i].x<<' '<<ang[i].y<<endl;
        }
        cout<<"===";
#endif
        int j=0,k=0,l=0;
        ll tri = N * (N-1) * (N-2) / 6;
        REP(i,N) {
            if (f(j+1)==i) j = i;
            while (f(j+1)!=i && ang[i].x*ang[f(j+1)].y > ang[i].y*ang[f(j+1)].x) inc(j);

            bug(i,j);
            ll thg = f(j-i)+1;
            tri -= (thg-2) * (thg-1)/2;
        }
        bug(tri);
        re += tri * (ll)(n-4);
        bug(re);
    }
    bug(re);
    cout<<re/2<<endl;
}