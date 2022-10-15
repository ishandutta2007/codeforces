#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
int MOD = 1e9 + 7;
const ld E = 1e-8;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".DAT"); _write(x ".SOL")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
#define y1 hello_world
unsigned char ccc;
bool _minus = false;
inline void read(int &n) {
	n = 0;
	_minus = false;
	while (true) {
		ccc = getchar();
		if (ccc == ' ' || ccc == '\n')
			break;
		if (ccc == '-') {
			_minus = true;
			continue;
		}
		n = n * 10 + ccc - '0';
	}
	if (_minus)
		n *= -1;
}
char wwww[12];
int kkkk;
inline void write(int x) {
	kkkk = 0;
	if (!x)
		++kkkk, wwww[kkkk] = '0';
	else
		while (x) {
			++kkkk;
			wwww[kkkk] = char(x % 10 + '0');
			x /= 10;
		}
	for (int i = kkkk; i >= 1; --i)
		putchar(wwww[i]);
	putchar('\n');
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

int main() {

	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;

#ifdef LOCAL
	input;
	//output;
#else

#endif

	int n, m;
	cin >> n >> m;

	int l[m], r[m];
	set<int> s;
	s.insert(0);
	s.insert(n);
	for(int i = 0; i < m; i++){
		cin >> l[i] >> r[i];
		s.insert(l[i]);
		s.insert(r[i]);
	}

	map<int, int> mp;
	int size = 0;
	for(set<int>::iterator it = s.begin(); it != s.end(); it++){
		mp[*it] = size++;
	}

	n = mp[n];
	vector<int> v[size];
	for(int i = 0; i < m; i++){
		l[i] = mp[l[i]];
		r[i] = mp[r[i]];
		v[r[i]].push_back(l[i]);
	}

	ll dp[size];
	ms(dp);

	ll sum[size];
	ms(sum);

	dp[0] = sum[0] = 1;

	for(int i = 1; i < size; i++){
		for(int j = 0; j < (int) v[i].size(); j++){
			int start = v[i][j];
			ll res = sum[i - 1] - (start == 0 ? 0 : sum[start - 1]);
			if(res < 0)
				res += MOD;
			dp[i] += res;
		}
		dp[i] %= MOD;
		sum[i] = sum[i - 1] + dp[i];
		if(sum[i] >= MOD)
			sum[i] -= MOD;
	}

	cout << dp[size - 1] << endl;

}