#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
const ll MOD = 1e9 + 7;
const ld E = 1e-9;
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
	while (x) {
		++kkkk;
		wwww[kkkk] = char(x % 10 + '0');
		x /= 10;
	}
	for (int i = kkkk; i >= 1; --i)
		putchar(wwww[i]);
	putchar(' ');
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

const int MAX = 2e5 + 1;
const int MAX2 = 51;

ld dp[MAX2][MAX];
int ar[MAX];
ld pref1[MAX], pref2[MAX], pref3[MAX];

int pointer;
vector<ld> K;
vector<ld> B;

inline bool bad(int a, int b, int c){
	return (B[c] - B[a]) * (K[a] - K[b]) > (B[b] - B[a]) * (K[a] - K[c]);
}

inline void add(ld k, ld b){
	K.push_back(k);
	B.push_back(b);
	while((int) K.size() >= 3 && bad(K.size() - 3, K.size() - 2, K.size() - 1)){
		K.erase(K.end() - 2);
		B.erase(B.end() - 2);
	}
}

inline ld query(ld x){
	static int pos = 0;
	pos = min(pos, (int) K.size() - 1);
	while(pos + 1 < (int) K.size() && K[pos] * x + B[pos] > K[pos + 1] * x + B[pos + 1])
		pos++;
	return K[pos] * x + B[pos];
}

inline void clear() {
	K.clear();
	B.clear();
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(15);
	cout << fixed;

#ifdef LOCAL
	input;
#else

#endif

	int n, k;
	read(n);
	read(k);

	for(int i = 1; i <= n; i++) {
		read(ar[i]);
		pref1[i] = pref1[i - 1] + ar[i];
		pref2[i] = pref2[i - 1] + 1.0 / ar[i];
		pref3[i] = pref3[i - 1] + (pref1[i] / ar[i]);
	}

	ms(dp);

	for(int i = 1; i <= n; i++) {
		dp[1][i] = dp[1][i - 1] + pref1[i] / ar[i];
	}

	for(int j = 2; j <= k; j++) {
		clear();
		for(int i = j - 1; i < j; i++) {
			add(pref1[i], dp[j - 1][i] - pref3[i] + pref2[i] * pref1[i]);
		}
		for(int i = j; i <= n; i++) {
			dp[j][i] = query(-pref2[i]) + pref3[i];
			add(pref1[i], dp[j - 1][i] - pref3[i] + pref2[i] * pref1[i]);
		}
	}

	cout << dp[k][n] << endl;

}