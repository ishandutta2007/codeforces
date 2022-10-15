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

const int MAX = 1e6 + 1;
map<int, int> m[MAX];

inline void add(int pos, int val, int t){
	for(int i = pos; i < MAX; i |= (i + 1))
		m[i][val] += t;
}

map<int, int>::iterator it;

inline int get(map<int, int> &m, int val){
	it = m.find(val);
	if(it == m.end())
		return 0;
	return it->second;
}

inline int sum(int pos, int val){
	int ans = 0;
	for(int i = pos; i >= 0; i &= (i + 1), i--)
		ans += get(m[i], val);
	return ans;
}

map<int, int> _time;
set<int> s;
int a[MAX], b[MAX], c[MAX];
inline void make(int n){
	for(int i = 0; i < n; i++)
		s.insert(b[i]);
	int size = 0;
	for(set<int>::iterator it = s.begin(); it != s.end(); it++){
		_time[*it] = size++;
	}
	for(int i = 0; i < n; i++)
		b[i] = _time[b[i]];
}

inline void _rand_test(){
	int n = 1e5;
	ofstream cout("input.txt");
	cout << n << endl;
	for(int i = 0; i < n; i++){
		cout << rand() % 3 + 1 << " " << rand() << " " << rand() % 1000 << endl;
	}
	cout.close();
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

	int n;
	read(n);

	for(int i = 0; i < n; i++){
		read(a[i]);
		read(b[i]);
		read(c[i]);
	}

	make(n);

	for(int i = 0; i < n; i++){
		if(a[i] == 1){
			add(b[i], c[i], 1);
		}else if(a[i] == 2){
			add(b[i], c[i], -1);
		}else{
			//sum(b[i], c[i]);
			write(sum(b[i], c[i]));
		}
	}

}