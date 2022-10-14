#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(ll (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) > (b); --(i))
#define rep(i, c)	for(auto &(i) : (c))
#define x     first
#define y     second
#define pb  push_back
#define PB  pop_back()
#define iosfal  ios_base::sync_with_stdio(false)
#define mp(a,b) make_pair(a,b)
#define sqr(a)  ((1LL * (a) * (a)))
#define all(a)  a.begin() , a.end()
#define error(x) cerr << #x << " = " << (x) <<endl                                                                 
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define errop(a) cerr<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define coud(a,b) cout<<fixed << setprecision((b)) << (a) << endl
#define dis(a,b)	(point(a.x - b.x, a.y - b.y))
#define L(x)	((x)<<1)
#define R(x)	(((x)<<1)+1)
#define mt	make_tuple
#define get(a,b)	get<b>(a)
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>	os;
typedef pair<int,int>pii;
typedef long long ll;
const int maxn = 1e3 + 100;
int n,t1,t2,a[maxn],b[maxn];
typedef pair<double,int> pf;
vector<pf> v;
double k;
inline double fuck(int v,int u){
	double x = .0;
	x += (double)v * (double)t1;
	x *= (100.0 - k)/100.0;
	x += (double)u * (double)t2;
	return x;
}
int main(int argc, char * argv[]){
	iosfal;
	cin >> n >> t1 >> t2 >> k;
	For(i,0,n){
		cin >> a[i] >> b[i];
		v.pb(pf(-max(fuck(a[i],b[i]),fuck(b[i],a[i])),i+1));
	}
	sort(all(v));
	For(i,0,v.size())
		cout << v[i].y << ' ' <<fixed << setprecision(2) << -v[i].x << endl;
}