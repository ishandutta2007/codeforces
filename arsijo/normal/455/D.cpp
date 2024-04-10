#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
int MOD = 1e9 + 7;
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
template<typename T> inline T sqr(T t) {
	return t * t;
}
#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

#ifndef LOCAL
const int MAXN = 1e5 + 10;
const int MAX_SIZE = 345;
#else
const int MAXN = 1e3 + 1;
const int MAX_SIZE = 3;
#endif

const int MAX_GROUPS = 2 * (MAXN / MAX_SIZE) + 10;
const int NEED_REBUILD = MAX_GROUPS - 10;
int ar[MAXN], n, ar_copy[MAXN];
int colors[MAX_GROUPS + 4][MAXN];
int group_size = 0;
int prev_block[MAX_GROUPS], next_block[MAX_GROUPS], left_border[MAX_GROUPS],
		right_border[MAX_GROUPS];

inline void add_group(int ind) {
	int l = left_border[ind], r = right_border[ind];
	for (int i = l; i <= r; i++)
		colors[ind][ar[i]]++;
}

inline void remove_group(int ind) {
	int l = left_border[ind], r = right_border[ind];
	for (int i = l; i <= r; i++)
		colors[ind][ar[i]]--;
}

inline void debuild() {
	int ind = 0;
	int size = 0;
	for (int i = 1; i <= group_size; i++) {
		ind = next_block[ind];
		assert(ind);
		for (int j = left_border[ind]; j <= right_border[ind]; j++)
			ar_copy[++size] = ar[j];
		remove_group(ind);
	}
	group_size = 0;
	assert(next_block[ind] == 0);
	for (int i = 1; i <= n; i++)
		ar[i] = ar_copy[i];
	assert(size == n);
}

inline void build() {
	int last_block = 0;
	group_size = 0;
	for (int i = 1; i <= n; i++) {
		if (i % MAX_SIZE == 1) {
			next_block[last_block] = ++group_size;
			prev_block[group_size] = last_block;
			next_block[group_size] = 0;
			last_block = group_size;
			left_border[group_size] = i;
		}
		right_border[group_size] = i;
		colors[group_size][ar[i]]++;
	}
	next_block[group_size] = 0;
}

inline void rebuild() {
	debuild();
	build();
}

inline void remove_block(int ind) {
	next_block[prev_block[ind]] = next_block[ind];
	prev_block[next_block[ind]] = prev_block[ind];
}

inline void insert_block(int pos, int ind) {
	next_block[ind] = next_block[pos];
	prev_block[next_block[ind]] = ind;
	prev_block[ind] = pos;
	next_block[pos] = ind;
}

inline int query(int l, int r, int val) {
	int L = 1, R = 0;
	int ind = 0;
	int ans = 0;
	int Q = 0;
	while (true) {
		ind = next_block[ind];
		if (!ind)
			break;
		int size = right_border[ind] - left_border[ind] + 1;
		R += size;
		if (L > r)
			break;
		if (R >= l) {
			if (l <= L && R <= r) {
				ans += colors[ind][val];
			} else {
				int l1 = max(l, L), r1 = min(r, R);
				int diff = L - left_border[ind];
				Q++;
				for (int i = l1; i <= r1; i++) {
					ans += (ar[i - diff] == val ? 1 : 0);
				}
			}
		}
		L += size;
	}
	assert(Q <= 2);
	return ans;
}

inline void print() {
	int ind = 0;
	do {
		ind = next_block[ind];
		cout << ind << ": ";
		for (int i = left_border[ind]; i <= right_border[ind]; i++)
			cout << ar[i] << " ";
		cout << endl;
	} while (next_block[ind]);
	cout << endl;
}

inline void divide(int ind, int pos) {
	int l = left_border[ind], r = right_border[ind];
	assert(l < pos && pos <= r);
	remove_group(ind);
	right_border[ind] = pos - 1;
	group_size++;
	left_border[group_size] = pos;
	right_border[group_size] = r;
	add_group(ind);
	add_group(group_size);
	insert_block(ind, group_size);
}

inline ii get_segment(int l, int r) {
	int L = 1, R = 0;
	int ind = 0;
	int ans_l = -1, ans_r = -1;
	while (true) {
		ind = next_block[ind];
		if (!ind)
			break;
		int size = right_border[ind] - left_border[ind] + 1;
		R += size;
		if (L > r)
			break;
		if (R >= l) {
			if (l <= L && R <= r) {
				if (ans_l == -1)
					ans_l = ind;
				ans_r = ind;
			} else {
				if (L < l && l <= R) {
					divide(ind, left_border[ind] + l - L);
					R -= size;
					ind = prev_block[ind];
					continue;
				}
				if (L <= r && r < R) {
					divide(ind, left_border[ind] + r + 1 - L);
					R -= size;
					ind = prev_block[ind];
					continue;
				}
			}
		}
		L += size;
	}
	assert(ans_l != -1);
	return make_pair(ans_l, ans_r);
}

inline void update(int l, int r) {
	if (l == r)
		return;
	ii first = get_segment(l, r - 1);
	ii second = get_segment(r, r);
	next_block[first.second] = next_block[second.second];
	prev_block[second.first] = prev_block[first.first];
	next_block[prev_block[first.first]] = second.first;
	prev_block[next_block[second.second]] = first.second;
	next_block[second.second] = first.first;
	prev_block[first.first] = second.second;
	//print();
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(30);
	cout << fixed;

#ifdef LOCAL
	input;
	//output;
#else

#endif

	read(n);

	for(int i = 1; i <= n; i++)
	read(ar[i]);

	build();

	int m;
	read(m);

	int ans = 0;
	while(m--) {
		int t;
		read(t);
		if(t == 1) {
			int l, r;
			read(l);
			read(r);
			l = (l + ans - 1 + n) + 1;
			while(l > n)
				l -= n;
			r = (r + ans - 1 + n) + 1;
			while(r > n)
				r -= n;
			if(l > r)
			swap(l, r);
			update(l, r);
		} else {
			int l, r, t;
			read(l);
			read(r);
			read(t);
			l = (l + ans - 1 + n) + 1;
			r = (r + ans - 1 + n) + 1;
			while(l > n)
				l -= n;
			while(r > n)
				r -= n;
			if(l > r)
			swap(l, r);
			t = (t + ans - 1 + n) + 1;
			while(t > n)
				t -= n;
			ans = query(l, r, t);
			write(ans);
		}
		if(group_size > NEED_REBUILD)
			rebuild();
	}

}