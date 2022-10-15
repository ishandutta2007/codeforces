//
//

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << " is " << x << endl

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

template <class T> inline int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

template<class P> bool onSegment(P s, P e, P p) {
	return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

template<class P> pair<long double, long double>  segInter(P a, P b, P c, P d) {
	auto oa = c.cross(d, a), ob = c.cross(d, b),
	     oc = a.cross(b, c), od = a.cross(b, d);
	// Checks if intersection is single non-endpoint point.
	if ((sgn(oa) ^ sgn(ob) )< 0 && (sgn(oc) ^ sgn(od) ) < 0){
//        cout<<b.x<<' '<<oa<<endl;
		return {
		    (a.x * (long double)ob -
       b.x * (long double)oa) / (long double)(ob - oa),
            (a.y * (long double)ob -
             b.y * (long double)oa) / (long double)(ob - oa)};

	}

	//if (onSegment(c, d, a)) return a;
//	if (onSegment(c, d, b)) return b;
	//if (onSegment(a, b, c)) return c;
	//if (onSegment(a, b, d)) return d;

	else return make_pair(-1e9,-1e9);
}

#define Pd Point<long long>

//const Pd pEps=Pd(0,1e-9);

int n,h;
Pd arr[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);

	cin>>n>>h;

	long long a,b;
	rep(x,0,n){
		cin>>a>>b;
		arr[x]=Pd(a,b);
	}

	// rep(x,0,n-1){
		// cout<<(arr[x+1]-arr[x]).dist()<<endl;
	// }
	//cout<<"Bruh"<<endl;

	Pd Es=Pd(arr[n-1].x,arr[n-1].y+h);
	Pd Ee=Pd(arr[n-1].x,arr[n-1].y-1e9);

	long double ans=0;
	rep(x,n-1,0){
		if (onSegment(Es,Ee,arr[x]) && onSegment(Es,Ee,arr[x+1])){
			ans+=(arr[x+1]-arr[x]).dist();
			continue;
		}

		pair<long double, long double> temp=segInter(arr[x],arr[x+1],Es,Ee);
		//cout<<temp<<endl;
		if (x==n-2) temp=make_pair(arr[x+1].x, arr[x+1].y);
		if (temp==make_pair((long double)-1e9,(long double)-1e9)) continue;

		//cout<<"debug: "<<temp[0]<<endl;
		//cout<<x<<" "<<(temp[0]-arr[x]).dist()<<endl;
		ans+=hypot((temp.first-arr[x].x), (temp.second-arr[x].y));

		Ee=Es-(Es-arr[x])*(1e6+100);
		//cout<<Ee<<endl;
	}

	cout<<fixed<<setprecision(12)<<ans<<endl;
}