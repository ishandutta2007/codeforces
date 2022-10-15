#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ld, ld> ii;
typedef pair<ii, ii> iii;
const ll MOD = 1e9 + 7;
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

void magic(int n, int *ar){
	set<int> s;
	map<int, int> m;
	for(int i = 0; i < n; i++)
		s.insert(ar[i]);
	int size = 0;
	for(set<int>::iterator it = s.begin(); it != s.end(); it++){
		m[*it] = size++;
	}
	for(int i = 0; i < n; i++)
		ar[i] = m[ar[i]];
}

void upd(int &a, int b){
	a = max(a, b);
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

	int n;
	cin >> n;

	int ar[n];
	for(int i = 0; i < n; i++)
		cin >> ar[i];

	magic(n, ar);

	int dp[n][n];
	ms(dp);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			if(dp[ar[j]][ar[i]] && ar[i] != ar[j])
				upd(dp[ar[i]][ar[j]], dp[ar[j]][ar[i]] + 1);
		for(int j = 0; j < i; j++)
			if(ar[i] != ar[j])
			upd(dp[ar[i]][ar[j]], 2);
		upd(dp[ar[i]][ar[i]], dp[ar[i]][ar[i]] + 1);
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;

}