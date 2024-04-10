/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <unordered_map>
#include <random>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll

using namespace std;

const int maxn = (int)2e5 + 10;
int v[maxn];
bool used[maxn];
int inter[maxn];

struct point {
	int x;
	int st;
	int cost;
	int y;
	int l, r;

	point() {

	}

	point(int x, int cost): x(x), st(0), cost(cost), y(rand()), l(-1), r(-1) {

	}
};

point mas[maxn];
int posit = 0;

int my_new(int x, int cost) {
	mas[posit] = point(x, cost);
	return posit++;
}

void sets(int t, int x) {
	if (t != -1) {
		mas[t].x += x;
		mas[t].st += x;
	}
}

void push(int t) {
	if (t == -1) {
		return;
	}

	if (mas[t].st != 0) {
		sets(mas[t].l, mas[t].st);
		sets(mas[t].r, mas[t].st);
		mas[t].st = 0;
	}
}

void split(int t, int x, int &l, int &r) {
	push(t);
	if (t == -1) {
		l = -1;
		r = -1;
	} else if (mas[t].x > x) {
		split(mas[t].l, x, l, mas[t].l);
		r = t;
	} else {
		split(mas[t].r, x, mas[t].r, r);
		l = t;
	}
}

int merge(int l, int r) {
	if (l == -1) {
		return r;
	} else if (r == -1) {
		return l;
	} else if (mas[l].y > mas[r].y) {
		push(l);
		mas[l].r = merge(mas[l].r, r);
		return l;
	} else {
		push(r);
		mas[r].l = merge(l, mas[r].l);
		return r;
	}
}

int add(int t, int x, int cost) {
	int l, r;

	split(t, x, l, r);

	return merge(merge(l, my_new(x, cost)), r);
}

int get_ans(int t) {
	if (t == -1) {
		return (int)1e9;
	}

	push(t);

	int ans = min(get_ans(mas[t].l), get_ans(mas[t].r));

	if (mas[t].x != 0) {
		ans = min(ans, mas[t].cost);
	}

	return ans;
}

int add(int t, int m) {
	int l, r;
	split(t, mas[m].x, l, r);

	return merge(merge(l, m), r);
}

int my_add(int l, int r, int x) {
	if (r == -1) {
		return l;
	} else {
		push(r);
		l = my_add(l, mas[r].l, x);
		l = my_add(l, mas[r].r, x);

		mas[r].l = -1;
		mas[r].r = -1;
		mas[r].x -= x;
		l = add(l, r);

		return l;
	}
}

int make(int t, int x) {
	int l, m, r;

	split(t, x - 1, l, r);
	split(r, 2 * x, m, r);

	sets(r, -x);

	l = my_add(l, m, x);

	return merge(l, r);
}

void write(int t) {
	if (t == -1) {
		return;
	}

	push(t);
	write(mas[t].l);
	cout << mas[t].x << ' ';
	write(mas[t].r);
}

int main() {
	int c, n;

	cin >> c >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	sort(v, v + n);
	reverse(v, v + n);

	int cc = c;

	for (int i = 0; i < n; i++) {
		if (cc >= v[i]) {
			cc -= v[i];
			used[i] = true;
		}
	}

	if (cc != 0) {
		throw 1;
	}

	int pos = n - 1;
	int sum = 0;

	for (int i = 1; i <= c; i++) {
		while (true) {
			while (pos >= 0 && !used[pos]) {
				pos--;
			}

			if (pos < 0) {
				break;
			}

			if (v[pos] < i) {
				sum += v[pos];
				pos--;
			} else {
				break;
			}
		}

		if (sum - i > 0) {
			if (inter[c - i] == 0) {
				inter[c - i] = i;
			}
		}
	}

	int t = -1;

	for (int i = 1; i <= c; i++) {
		if (inter[i] != 0) {
			t = add(t, i, inter[i]);
		}
	}

	for (int i = 0; i < n; i++) {
		t = make(t, v[i]);
	}

	int ans = get_ans(t);

	if (ans != (int)1e9) {
		cout << ans << endl;
	} else {
		cout << "Greed is good" << endl;
	}

	return 0;
}