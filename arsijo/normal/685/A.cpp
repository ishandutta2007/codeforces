#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
ll MOD = 1000003;
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
template<typename T>
inline T sqr(T t) {
	return (t * t)mod;
}
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

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

int get_seven(ll n){
	int ans = 0;
	n--;
	while(n){
		ans++;
		n /= 7;
	}
	return max(ans, 1);
}

bool colored[7];

void get(ll a, int b){
	for(int i = 0; i < b; i++){
		colored[a % 7] = true;
		a /= 7;
	}
}

ll solve_long(ll a, ll b){
	int aa = get_seven(a), bb = get_seven(b);
	if(aa + bb > 7)
		return 0;
	int ans = 0;
	for(int i = 0; i < a; i++){
		for(int j = 0; j < b; j++){
			ms(colored);
			get(i, aa);
			get(j, bb);
			int res = 0;
			for(int i = 0; i < 7; i++)
				if(colored[i])
					res++;
			if(res == aa + bb){
				ans++;
			}
		}
	}
	return ans;
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;

#ifdef LOCAL
	input;
#else

#endif

	int n, m;
	cin >> n >> m;
	cout << solve_long(n, m) << endl;

}