//In C<>de We Trust :D
#include <bits/stdc++.h>

using namespace std;

#define MohammadAmin main()
#define mpair make_pair
#define endl "\n"
#define c_false ios_base::sync_with_stdio(false)
#define pushb push_back
#define pushf push_front
#define popb pop_back
#define popf pop_front
#define sz size()
#define X first
#define Y second
#define ashar(a) cout << fixed << setprecision((a))
#define reset(a,b) memset(a, b, sizeof(a))
#define for0(a, n) for (int (a) = 0; (a) < (n); (a)++)
#define for1(a, n) for (int (a) = 1; (a) <= (n); (a)++)
#define rof0(a, n) for (int (a) = (n); (a) >= 0; (a)--)
#define For(i, a, n) for (int (i) = (a); (i) <= (n); (i)++)
#define rof(i, n, a) for (int (i) = (n); (i) >= (a); (i)--)
#define segn(id) int l = (id) << 1, r = l | 1, mid = (b + e) >> 1;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, char> pcc;

const ll INF = 1e9, MOD = 1e9 + 7;
const int n_ = 1e5 + 1000;
ll gcd (ll a, ll b) {return ( a ? gcd(b%a, a) : b );}
ll power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}


int MohammadAmin {
	c_false;
	ll a, b, w, x, c;
	cin >> a >> b >> w >> x >> c;
	cout << (a < c ? ((c - a) * x - b + w - x - 1) / (w - x) + c - a : 0) << endl;
	return 0;
}