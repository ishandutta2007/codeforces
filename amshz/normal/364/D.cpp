# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef double ld;
typedef pair <ll, ll> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 1e6 + 10;
const int xm = 1e6 + 11;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
ll gcd(ll a, ll b){
	if (b > a) swap(a, b);
	if (b == 0) return a;
	return gcd(b, a % b);
}
 
 
ll n, a[xn], ans, b[xn];
unordered_map <ll, int> cnt;
 
 
void Solve(ll x){
	cnt.clear();
	for (int i = 0; i < n; i ++)
		cnt[gcd(a[i], x)] ++;

	int pnt = 0;
	for (ll i = 1; i < sqrt(x); i ++)
		if (x % i == 0) b[pnt ++] = i, b[pnt ++] = x / i;
	
	if (sqrt(x) * sqrt(x) == x) b[pnt ++] = sqrt(x);
	
	for (int i = 0; i < pnt; i ++){
		int t = 0;
		for (int j = 0; j < pnt; j ++)
			if (b[j] % b[i] == 0) t += cnt[b[j]];
			
		if (t > (n - 1) / 2) ans = max(ans, b[i]);
	}
}
 
 
 
 
int main(){
	fast_io;
	srand(time(0));
	
	
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i];
	
	random_shuffle(a, a + n);
	
	for (int i = 0; i < min(n, 10LL); i ++) Solve(a[i]);
	
	
	cout << ans << endl;
	
	return 0;
}