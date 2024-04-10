//int ex,ey;
//ld ang(ld x, ld y){
//    return atan2(ex-x,ey-y);
//}
//void __(){
//    _(int,n);
//    _(int,H);
//    vi x(n),y(n);
//    rep(i,n)
//        cin >> x[i] >> y[i];
//
//    ex = x[n-1];
//    ey = y[n-1]+H;
//    ld max_ang = 0;
//    ld ans = 0;
//    per(i,1,n-1){
//        int x1 = x[i];
//        int y1 = y[i];
//
//        int x2 = x[i-1];
//        int y2 = y[i-1];
//
//        ld ang1 = ang(x1,y1);
//        ld ang2 = ang(x2,y2);
//
//        ld len = hypot(x1-x2,y2-y1);
//
//        if(abs(ang1-ang2) < EPS){
//            if(abs(ang1-max_ang) < EPS)
//                ans += len;
//            continue;
//        }
//        if(ang1 > ang2)
//            continue;
//        if(ang2 <= max_ang+EPS)
//            continue;
//        ld lo = 0, hi = 1, mid;
//        rep(times,100){
//            mid = (lo+hi)/2;
//            ld x = x1*(1-mid)+(mid)*x2;
//            ld y = y1*(1-mid)+(mid)*y2;
//            if(ang(x,y) >= max_ang)
//                hi = mid;
//            else
//                lo = mid;
//        }
//        ans += (1-lo)*len;
//        max_ang = ang2;
//
//    }
//    print ans;
//}
//
//
#include <cmath>
#include <iomanip>
#include <vector>
#include <utility>
#include <iostream>
#include <string>
#define REP_ZERO_INT(i,r) for(int i = 0; i < (r); ++i)
#define GET_REP_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) GET_REP_MACRO(__VA_ARGS__,REP_ANY,REP_INT,REP_ZERO_INT)(__VA_ARGS__)
#define PER_INT(i,l,r) for(int i = (r); i >= (l); --i)
#define GET_PER_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define per(...) GET_PER_MACRO(__VA_ARGS__,PER_ANY,PER_INT,PER_ZERO_INT)(__VA_ARGS__)
#define all(v) (v).begin(), (v).end()
#define sz(v) ll(v.size())
#define T1 template<typename T> static
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef double ld;
const ld EPS = 1e-12;
T1 ostream& operator<<(ostream& stream, const vector<T>& t);
T1 istream& read(T, T, istream& = cin);
struct _print {
    string sep,end;
    bool space;
    ostream &stream;
    _print(string _sep=" ",string _end="\n",
            ostream &_stream = cout) 
        : sep(_sep),end(_end),space(false),
            stream(_stream) {}
    ~_print() { stream << end; }

    template <typename T>
        _print &operator , (const T &t) {
            if (space) stream << sep;
            space = true;
            stream << t;
            return *this;
        }
};
#define print _print(),
#define INPUT_WITHOUT_INIT(type,name) type name; cin >> name
#define GET_INPUT_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,NAME,...) NAME
#define _(...) GET_INPUT_MACRO(__VA_ARGS__,_IWI,_IWI,_IWI,_IWI,_IWI,_IWI,INPUT_WITHOUT_INIT)(__VA_ARGS__)
int ex,ey;
ld ang(ld x, ld y){
    return atan2(ex-x,ey-y);
}
void __(){
    _(int,n);
    _(int,H);
    vi x(n),y(n);
    rep(i,n)
        cin >> x[i] >> y[i];

    ex = x[n-1];
    ey = y[n-1]+H;
    ld max_ang = 0;
    ld ans = 0;
    per(i,1,n-1){
        int x1 = x[i];
        int y1 = y[i];

        int x2 = x[i-1];
        int y2 = y[i-1];

        ld ang1 = ang(x1,y1);
        ld ang2 = ang(x2,y2);

        ld len = hypot(x1-x2,y2-y1);

        if(abs(ang1-ang2) < EPS){
            if(abs(ang1-max_ang) < EPS)
                ans += len;
            continue;
        }
        if(ang1 > ang2)
            continue;
        if(ang2 <= max_ang+EPS)
            continue;
        ld lo = 0, hi = 1, mid;
        rep(times,100){
            mid = (lo+hi)/2;
            ld x = x1*(1-mid)+(mid)*x2;
            ld y = y1*(1-mid)+(mid)*y2;
            if(ang(x,y) >= max_ang)
                hi = mid;
            else
                lo = mid;
        }
        ans += (1-lo)*len;
        max_ang = ang2;

    }
    print ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
        __();
}