#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
const ld E = 1e-7;
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

struct fenwick_tree{
	int n, *t;
	fenwick_tree(int n){
		this->n = n;
		t = new int[n];
		for(int i = 0; i < n; i++)
			t[i] = 0;
	}
	void add(int pos, int val){
		for(int i = pos; i < n; i |= (i + 1)){
			t[i] ^= val;
		}
	}
	int xor_sum(int pos){
		int ans = 0;
		for(int i = pos; i >= 0; i &= (i + 1), i--)
			ans ^= t[i];
		return ans;
	}
	int xor_sum(int l, int r){
		return (xor_sum(r) ^ xor_sum(l - 1));
	}
};

const int MAX = 1e6 + 1;
int ar[MAX];
vector<ii> vec[MAX];
int ans[MAX];
int next[MAX];
int main() {

	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;

#ifdef LOCAL
	input;
#else

#endif

	int n;
	read(n);
	for(int i = 1; i <= n; i++){
		read(ar[i]);
	}
	int m;
	read(m);
	int l, r;
	for(int i = 1; i <= m; i++){
		read(l);
		read(r);
		vec[l].push_back(make_pair(r, i));
	}
	fenwick_tree tree1(n + 1);
	for(int i = 1; i <= n; i++){
		tree1.add(i, ar[i]);
	}
	map<int, int> mm;
	fenwick_tree tree2(n + 1);
	for(int i = 1; i <= n; i++){
		if(mm[ar[i]] == 0)
			tree2.add(i, ar[i]);
		next[mm[ar[i]]] = i;
		mm[ar[i]] = i;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < (int) vec[i].size(); j++){
			int pos = vec[i][j].first;
			ans[vec[i][j].second] = tree1.xor_sum(i, pos) ^ tree2.xor_sum(i, pos);
		}
		tree2.add(i, ar[i]);
		tree2.add(next[i], ar[i]);
	}
	for(int i = 1; i <= m; i++){
		write(ans[i]);
	}
}