#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
const ld E = 1e-9;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#ifndef LONG_LONG_MAX
#define LONG_LONG_MAX LLONG_MAX
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".DAT"); _write(x ".SOL")
#define output _write("output.txt")
#define input _read("input.txt")
#define prev time_prev
#define remove tipa_remove
#define next tipa_next
#define mod % MOD
#define y1 hello_world
unsigned char ccc;
bool _minus = false;
template<typename T>
inline T sqr(T t) {
	return (t * t);
}
inline void read(ll &n) {
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
char wwww[19];
int kkkk;
inline void write(ll y) {
	long long x = y;
	kkkk = 0;
	if (x < 0) {
		putchar('-');
		x *= -1;
	}
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
}

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

const int MAX = 20;

int ar[MAX][MAX];
bool used[MAX];
int d[MAX];
int n;

int solve(int pos, int col) {
	for (int w = 0; w < 3; w++) {
		ms(used);
		used[pos] = true;
		d[pos] = 0;
		queue<int> q;
		q.push(pos);
		while(!q.empty()){
			pos = q.front();
			q.pop();
			for(int i = 1; i <= n; i++){
				if(ar[pos][i] == col && !used[i]){
					used[i] = true;
					d[i] = d[pos] + 1;
					q.push(i);
				}
			}
		}
		for(int i = 1; i <= n; i++){
			if(!used[i]){
				return -1;
			}
		}
	}
	return d[pos];
}

set<int> s;

void dfs(int x, int y){
	if(y == n + 1){
		x++;
		y = x + 1;
		if(x == n){
			if(min(solve(1, 1), solve(1, 2)) == 2){
				for(int i = 1; i <= n; i++){
					for(int j = 1; j <= n; j++){
						cout << ar[i][j] << " ";
					}
					cout << endl;
				}
				exit(0);
			}
			return;
		}
	}
	ar[x][y] = ar[y][x] = 1;
	dfs(x, y + 1);
	ar[x][y] = ar[y][x] = 2;
	dfs(x, y + 1);
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
/*
	cin >> n;
	dfs(1, 2);
	for(int a : s){
		cout << a << endl;
	}
	*/
	int n, k;
	cin >> n >> k;
	if(k == 2 && n >= 5){
		cout << n - 1 << endl;
		for(int i = 2; i <= n; i++){
			cout << i - 1 << " " << i << endl;
		}
		return 0;
	}
	if(k == 3 && n >= 4){
		cout << n - 1 << endl;
		for(int i = 1; i < n; i++){
			if(i != n - 2){
				cout << i << " " << n << endl;
			}
		}
		cout << n - 2 << " " << n - 1 << endl;
		return 0;
	}
	cout << -1 << endl;

}