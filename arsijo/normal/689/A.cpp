#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
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
char wwww[12];
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

void no(){
	cout << "NO" << endl;
	exit(0);
}

bool ok[9][9];

bool check(ii a, vector<ii> v){
	for(int i = 0; i < (int) v.size(); i++){
		a.first += v[i].first;
		a.second += v[i].second;
		//cout << a.first << " " << a.second << "? " << endl;
		if(!ok[a.first][a.second])
			return false;
	}
	//cout << a.first << " " << a.second << endl;
	return true;
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(5);
	cout << fixed;

#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	string s;
	cin >> s;
	ii ar[10] = {make_pair(4, 2), make_pair(1, 1), make_pair(1, 2), make_pair(1, 3), make_pair(2, 1), make_pair(2, 2), make_pair(2, 3), make_pair(3, 1), make_pair(3, 2), make_pair(3, 3)};
	if(n == 1){
		no();
	}
	vector<ii> v;
	for(int i = 0; i < 10; i++)
		ok[ar[i].first][ar[i].second] = true;
	for(int i = 1; i < n; i++){
		int a = s[i - 1] - '0';
		int b = s[i] - '0';
		v.push_back(make_pair(ar[b].first - ar[a].first, ar[b].second - ar[a].second));
	}
	//cout << v[0].first << " " << ar[0].second << endl;

	int res = 0;
	for(int i = 0; i < 10; i++)
		if(check(ar[i], v))
			res++;
	if(res != 1)
		no();
	cout << "YES" << endl;

}