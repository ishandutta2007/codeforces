#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
ll MOD = 2012;
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

int ar[6];

vector<int> v[12];

void no(){
	cout << "NO" << endl;
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

	for(int i = 0; i < 6; i++)
		cin >> ar[i];

	int n;
	cin >> n;

	map<string, int> m;
	string sizes[6] = {"S", "M", "L", "XL", "XXL", "XXXL"};
	for(int i = 0; i < 6; i++){
		m[sizes[i]] = i;
	}
	for(int i = 1; i < 6; i++){
		m[sizes[i - 1] + "," + sizes[i]] = 5 + i;
	}

	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		v[m[s]].push_back(i);
	}

	int anses[n];
	ms(anses);

	for(int i = 0; i < 6; i++){
		for(int j = 0; j < (int) v[i].size(); j++){
			int ind = v[i][j];
			if(ar[i]){
				anses[ind] = i;
				ar[i]--;
			}else{
				no();
			}
		}
	}
	for(int q = 1; q < 6; q++){
		int i = 5 + q;
		for(int j = 0; j < (int) v[i].size(); j++){
			int s = (ar[q - 1] ? q - 1 : q);
			int ind = v[i][j];
			if(ar[s]){
				anses[ind] = s;
				ar[s]--;
			}else{
				no();
			}
		}
	}

	cout << "YES" << endl;
	for(int i = 0; i < n; i++)
		cout << sizes[anses[i]] << endl;

}