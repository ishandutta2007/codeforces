#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
const ll MOD = 1e9 + 7;
const ld E = 1e-10;
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
char wr[12];
int k;
inline void write(int x) {
	k = 0;
	if (!x)
		++k, wr[k] = '0';
	while (x) {
		++k;
		wr[k] = char(x % 10 + '0');
		x /= 10;
	}
	for (int i = k; i >= 1; --i)
		putchar(wr[i]);
	putchar('\n');
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

const int MAX = 501;
int ar[MAX][MAX];
int dist[MAX][MAX];
bool used[MAX];
int n;
ll ans = 0;

void upd(int k){
	//cout << "+ " << k << endl;
	used[k] = true;
	for(int i = 1; i <= n; i++){
		if(used[i]){
			ans += dist[k][i] = ar[k][i];
			ans += dist[i][k] = ar[i][k];
		}
	}
	for(int i = 1; i <= n; i++){
		if(used[i]){
			int w = dist[k][i];
			int e = dist[i][k];
			for(int j = 1; j <= n; j++){
				if(used[j]){
					dist[k][i] = min(dist[k][i], dist[k][j] + dist[j][i]);
					dist[i][k] = min(dist[i][k], dist[i][j] + dist[j][k]);
				}
			}
			ans -= w - dist[k][i];
			ans -= e - dist[i][k];
		}
	}
	int w;
	for(int i = 1; i <= n; i++){
		if(used[i]){
			for(int j = 1; j <= n; j++){
				if(used[j]){
					w = dist[i][k] + dist[k][j];
					if(w < dist[i][j]){
						ans -= dist[i][j];
						dist[i][j] = w;
						ans += w;
					}
				}
			}
		}
	}
	return;
	cout << "-----" << endl;
	for(int i = 1; i <= n; i++){
		if(!used[i])
			continue;
		for(int j = 1; j <= n; j++){
			if(used[i] && used[j]){
				cout << dist[i][j] << "\t";
			}
		}
		cout << endl;
	}
	cout << "-----" << endl;
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(0);
	cout << fixed;

#ifdef LOCAL
	input;
#else

#endif

	cin >> n;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> ar[i][j];
		}
	}

	int t[n + 1];
	for(int i = 1; i <= n; i++)
		cin >> t[i];

	ll ans[n + 1];
	ans[n] = 0;

	upd(t[n]);

	for(int i = n - 1; i >= 1; i--){
		upd(t[i]);
		ans[i] = ::ans;
	}

	for(int i = 1; i <= n; i++)
		cout << ans[i] << " ";

}