# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 8e18 + 7;
const int xn = 1e6 + 10;
const int xm = 1e6 + 10;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
 
ll n;
ll ans = inf;
vector <ll> adj[xn], Primes;
bool Prime[xn];


bool check(ll x, ll y){
	ld xx = ld(x);
	ld yy = ld(y);
	if (xx * yy > 1e18) return true;
	return false;
}
bool pw(ll x, ll y){
	ll Log = 0;
	ll g = 1e18;
	while (g){
		g /= x;
		Log ++;
	}
	return (y > Log);
}
 
 
void Solve(ll x, int t, ll y){
	if (t > 11) return;
	if (x == 1){
		ans = min(ans, y);
		return;
	}
	for (ll k : adj[int(x)]){
		if (pw(Primes[t], k - 1) || check(y, power(Primes[t], k - 1))) continue;
		Solve(x / k, t + 1, y * power(Primes[t], k - 1));
	}
}
 
 
 
int main(){
	fast_io;
	
	
	cin >> n;
	
	for (int i = 2; i <= 1000; i ++){
		if (Prime[i]) continue;
		for (int j = i + i; j <= 1000; j += i)	Prime[j] = true;
		Primes.push_back(i);
	}
	
	for (int i = 2; i <= 1000; i ++)
		for (int j = i; j <= 1000; j += i)
			adj[j].push_back(ll(i));
			
	
	Solve(n, 0, 1);
	
	cout << ans << endl;
	
	
	return 0;
}