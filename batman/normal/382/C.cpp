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
	int n, a[n_], d, x = 0, iscon, y;
	scanf("%d", &n);
	if (n == 1) return puts("-1"), 0;
	set<int> st;
	for0(i, n) {
		scanf("%d", a + i);
	}
	sort(a, a+n);
	d = a[1] - a[0];
	iscon = (a[1] == a[0]);
	For(i, 2, n - 1) {
		if (d != a[i] - a[i-1]) {
			x++; y = i;
			st.insert(a[i] - a[i - 1]);
		}
		iscon &= (a[i] == a[i-1]);
	}
	//cerr << x << " " << y << endl;
	if (iscon) {
		printf("1\n%d\n", a[0]);
		return 0;
	}
	if (n == 2) {
		if ((a[0] & 1) ^ (a[1] & 1) == 0) {
			printf("3\n");
			printf("%d %d %d\n", a[0] - d, a[0] + a[1] >> 1, a[1] + d);
		}else{
			printf("2\n");
			printf("%d %d\n", a[0] - d, a[1] + d);
		}
		return 0;
	}
	if (!x) {
		printf("2\n%d %d\n", a[0] - d, a[n-1] + d);
		return 0;
	}
/*
4
1 3 5 9
*/
	if (x == 1 || x == n - 2) {
		if (st.sz > 1) return puts("0"), 0;
		if (n == 3) {
			if ((a[2] - a[1]) % 2 == 0) {
				if (a[2] - a[1] >> 1 == d) return printf("1\n%d\n", a[2] + a[1] >> 1), 0;
			}
			d = a[2] - a[1];
			if ((a[1] - a[0]) % 2 == 0) {
				if (a[1] - a[0] >> 1 == d) return printf("1\n%d\n", a[1] + a[0] >> 1), 0;
			}
			puts("0");
			return 0;
		}
		if (x == 1) {
			if ((a[y] - a[y-1] >> 1) == d && ((a[y]&1) ^ (a[y-1] & 1) == 0)) {
				printf("1\n%d\n", (a[y] + a[y-1] >> 1));
			}else{
				puts("0");
			}
			return 0;
		}
		d = a[y] - a[y-1];
		if ((a[1] - a[0] >> 1) == d && ((a[1]&1) ^ (a[0] & 1) == 0)) {
			printf("1\n%d\n", (a[1] + a[0] >> 1));
		}else{
			//cerr << "entered h\n";
			puts("0");
		}
		return 0;
	}
	//cerr << "r\n";
	puts("0");
	return 0;
}