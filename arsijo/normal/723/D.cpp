#include <bits/stdc++.h>
using namespace std;
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
#define prev asdklhsdireufhdashj
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

char ar[52][52];

int X[4] = {0, 1, 0, -1}, Y[4] = {1, 0, -1, 0};

bool used[52][52];

int bfs(int x, int y){
	int ans = 0;
	used[x][y] = true;
	queue<ii> q;
	q.push(make_pair(x, y));
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		ans++;
		q.pop();
		for(int i = 0; i < 4; i++){
			int x1 = x + X[i], y1 = y + Y[i];
			if(0 <= x1 && x1 < 52 && 0 <= y1 && y1 < 52 && !used[x1][y1] && ar[x1][y1] == '.'){
				q.push(make_pair(x1, y1));
				used[x1][y1] = true;
			}
		}
	}
	return ans;
}

int ans = 0;

void _s(int x, int y){
	queue<ii> q;
	ar[x][y] = '*';
	q.push(make_pair(x, y));
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		ans++;
		for(int i = 0; i < 4; i++){
			int x1 = x + X[i], y1 = y + Y[i];
			if(0 <= x1 && x1 < 52 && 0 <= y1 && y1 < 52 && ar[x1][y1] == '.'){
				q.push(make_pair(x1, y1));
				ar[x1][y1] = '*';
			}
		}
	}
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
	cin >> n >> m >> k;
	for(int i = 0; i < 52; i++){
		for(int j = 0; j < 52; j++){
			ar[i][j] = '.';
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> ar[i][j];
		}
	}

	bfs(0, 0);

	vector<pair<int, ii> > v;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(ar[i][j] == '.' && !used[i][j]){
				v.push_back(make_pair(bfs(i, j), make_pair(i, j)));
			}
		}
	}

	sort(v.rbegin(), v.rend());
	while((int) v.size() > k){
		_s(v.back().second.first, v.back().second.second);
		v.pop_back();
	}

	cout << ans << endl;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cout << ar[i][j];
		}
		cout << endl;
	}

}