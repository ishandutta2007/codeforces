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
 
const ll md =  998244353;
const int xn = 2e5 + 10;
const int xm = 1e3 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const ll inf = 1e18+ 10;
 
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}


int n, cnt[xn], ans;
string a;
bool Mark[xn];

void check(int k){
	memset(cnt, 0, sizeof cnt);
	for (int i = 0; i < n; i ++) if (a[i] == '1') cnt[i % k] ++;
	for (int i = 0; i < k; i ++) if (cnt[i] % 2) return;
	Mark[k] = true;
}

int main(){
	fast_io;
	
	cin >> n >> a;
	for (int i = 1; i <= n; i ++){
		int g = __gcd(n, i);
		if (g == i) check(i);
		ans += Mark[g];
	}
	cout << ans << endl;
	
	return 0;
}