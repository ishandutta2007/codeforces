#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
template<typename T> inline T sqr(T a) {
	return a * a;
}
#define endl "\n"
#define def(f) make(#f);
#define y1 dads
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
#ifdef LOCAL
typedef double ld;
#else
typedef long double ld;
#endif
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
typedef pair<string, string> ss;
const ld E = 1e-15;
const ll MOD = 1e9 + 7;
#define mod % MOD

#ifdef LOCAL
#define DEBUG
#endif

#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

int solve(int n, int m, int q){
	for(int i = 1; i <= m; i++){
		int w = i * 3;
		if((w & 1) == 0 && w <= (n << 1)){
			if(q == 0){
				m++;
				continue;
			}else{
				q--;
				n++;
			}
		}
	}
	return max(n * 2, m * 3);
}

int solve_long(int n, int m){
	int ans = INT_MAX;
	for(int i = 0; i <= n * 3; i++){
		ans = min(ans, solve(n, m, i));
	}
	return ans;
}

int main() {

	cout.precision(11);
	cout << fixed;
	sync;
	srand(time(NULL));

#ifdef LOCAL
	input;
#else

#endif

	int n, m;
	cin >> n >> m;

	set<int> s;

	int k = 0;

	s.insert(0);

	for(int i = 1; i <= m; i++){
		if(i % 2 == 0 && i * 3 <= 2 * n){
			k++;
			m++;
			continue;
		}
		s.insert(i * 3);
	}

	for(int i = 0; i < k; i++){
		if(*s.rbegin() > (n + 1) * 2){
			n++;
			if(s.find(n * 2) == s.end()){
				s.erase(*s.rbegin());
			}else{
				k++;
			}
		}
	}

	cout << max(*s.rbegin(), n * 2);

}