#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
const ll MOD = 1e9 + 7;
const ld E = 1e-7;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
//#define endl "\n"
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
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

ii ar[101];
int n, a[101], dist[101], d;

int get_dist(int c, int d){
	return (abs(ar[c].first - ar[d].first) + abs(ar[c].second - ar[d].second)) * ::d;
}

bool check(int t){
	for(int i = 2; i <= n; i++)
		dist[i] = INT_MIN;
	dist[1] = t;
	for(int k = 2; k <= n; k++){
		for(int i = 1; i <= n; i++){
			if(dist[i] == INT_MIN)
				continue;
			for(int j = 1; j <= n; j++){
				if(i == j)
					continue;
				int d = get_dist(i, j);
				if(dist[i] >= d){
					dist[j] = max(dist[j], dist[i] - d + a[j]);
				}
			}
		}
	}
	return dist[n] != INT_MIN;
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(15);
	cout << fixed;

#ifdef LOCAL
	//write();
	input;
#else

#endif

	cin >> n >> d;

	for(int i = 2; i < n; i++)
		cin >> a[i];

	for(int i = 1; i <= n; i++){
		cin >> ar[i].first >> ar[i].second;
	}
	int l = 0, r = 1e9;
	while(l < r){
		int x = (l + r) >> 1;
		if(check(x))
			r = x;
		else
			l = x + 1;
	}

	cout << l << endl;

}