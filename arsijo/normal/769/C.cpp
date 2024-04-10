#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
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
#define filesdatsol(x) _read(x ".DAT"); _write(x ".SOL")
#define output _write("output.txt")
#define input _read("input.txt")
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
	putchar(' ');
}

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

int X[4] = {1, 0, 0, -1};
int Y[4] = {0, -1, 1, 0};
string str = "DLRU";

const int MAX = 1010;

char ar[MAX][MAX];

int dist[MAX][MAX];

void imp(){
	cout << "IMPOSSIBLE" << endl;
	exit(0);
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

	int n, m, k;
	read(n);
	read(m);
	read(k);

	int x, y;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			ar[i][j] = getchar();
			if(ar[i][j] == 'X'){
				x = i, y = j;
				ar[i][j] = '.';
			}
		}
		getchar();
	}

	if(k & 1){
		imp();
	}

	dist[x][y] = 1;
	queue<ii> q;
	q.push(make_pair(x, y));

	string ans = "";
	int sz = 0;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		sz++;
		for(int i = 0; i < 4; i++){
			int x1 = x + X[i];
			int y1 = y + Y[i];
			if(ar[x1][y1] == '.' && dist[x1][y1] == 0){
				dist[x1][y1] = dist[x][y] + 1;
				q.push(make_pair(x1, y1));
			}
		}
	}

	if(sz == 1){
		imp();
	}

	while(k){
		for(int i = 0; i < 4; i++){
			x += X[i];
			y += Y[i];
			if(ar[x][y] == '.' && dist[x][y] <= k){
				ans += str[i];
				break;
			}
			x -= X[i];
			y -= Y[i];
		}
		k--;
	}

	cout << ans << endl;

}