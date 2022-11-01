# include <bits/stdc++.h>
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
const int xn = 1e3 + 10;
const int xm = 1e3 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const ll inf = 1e18+ 10;
 
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}


int qq, n, a[xn], c[xn], cnt;
bool p[xn];
vector <int> pr;


int main(){
	fast_io;
	
	for (int i = 2; i <= 1000; i ++){
		if (p[i]) continue;
		pr.push_back(i);
		if (pr.size() == 11) break;
		for (int j = i + i; j <= 1000; j += i) p[j] = true;
	}
	cin >> qq;
	while (qq --){
		cin >> n;
		for (int i = 0; i < n; i ++) cin >> a[i];
		memset(c, 0, sizeof c);
		int cnt = 1;
		for (int x : pr){
			int t = 0;
			for (int i = 0; i < n; i ++) if (a[i] % x == 0 && !c[i]) c[i] = cnt, t ++;
			if (t) cnt ++;
		}
		cout << cnt - 1 << endl;
		for (int i = 0; i < n; i ++) cout << c[i] << sep;
		cout << endl;
	}
	
	
	return 0;
}