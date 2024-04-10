#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
const ld E = 1e-17;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".dat"); _write(x ".sol")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
char ccc;
inline void read(int &n) {
	n = 0;
	while (true) {
		ccc = getchar();
		if (ccc == ' ' || ccc == '\n')
			break;
		n = n * 10 + ccc - '0';
	}
}
template<typename T> inline T sqr(T t) {
	return t * t;
}
#ifdef LOCAL
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

vector<int> primes;
const int MAX = 2e5 + 1;
int prime[MAX];

void pre(){
	fill(prime, prime + MAX, true);
	prime[0] = prime[1] = false;
	int s = sqrt(MAX);
	for(int i = 2; i <= MAX; i++){
		if(prime[i]){
			primes.push_back(i);
			if(i <= s){
				for(int j = i * i; j < MAX; j += i)
					prime[j] = false;
			}
		}
	}
}

int solve(int n, int k){
	int ans = 0;
	while(n){
		ans += n /= k;
	}
	return ans;
}

ll _pow(ll n, ll m){
	return (m == 0 ? 1 : m & 1 ? n * _pow(n, m - 1) : sqr(_pow(n, m >> 1))) mod;
}

ll get(int n, int two){
	int t = solve(n, 2) - two;
	ll ans = _pow(2, t);
	for(int i = 1; i < (int) primes.size() && primes[i] <= n; i++){
		t = solve(n, primes[i]);
		ans = (ans * _pow(primes[i], t)) mod;
	}
	return ans;
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(15);
	cout << fixed;

#ifdef LOCAL
	input;
	//output;
#else

#endif

	pre();

	int n;
	cin >> n;

	vector<ii> vec;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		vec.push_back(make_pair(a, i));
	}
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		vec.push_back(make_pair(a, i));
	}
	cin >> MOD;
	sort(vec.begin(), vec.end());
	ll ans = 1;
	for(int i = 0; i < (int) vec.size(); i++){
		int n = 1;
		int m = 0;
		while(i + 1 < (int) vec.size() && vec[i + 1].first == vec[i].first){
			if(vec[i + 1].second == vec[i].second)
				m++;
			n++;
			i++;
		}
		ans = (ans * get(n, m)) mod;
	}
	cout << ans << endl;

}