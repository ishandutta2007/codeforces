# include <iostream>
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
const ll md = 1e9 + 7;
const int xn = 5e5 + 10;
const int xm = 1e3 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const ll inf = 1e18+ 10;
 
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}


int qq;
ll a, b, c, d, x1, y1, x2, y2, x, y;


int main(){
	fast_io;
	
	cin >> qq;
	while (qq --){
		cin >> a >> b >> c >> d;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		x += b - a;
		if (a && b && a == b && x == x1 && x == x2){
			cout << "No" << endl;
			continue;
		}
		y += d - c;
		if (d && c && d == c && y == y1 && y == y2){
			cout << "No" << endl;
			continue;
		}
		if (x >= x1 && x <= x2 && y >= y1 && y <= y2) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	return 0;
}