#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define M 300300

long double p[M];
int n;
pair<int, int> b[M];

void pre(void){
	p[0] = 1.0;
	for (int i = 1; i < M; ++i)
		p[i] = p[i - 1] / 2;
}

struct node{
	long double l, r;
	int c;
} t[4 * M], one{ 0.5, 1.0, 1}, zero{ 1.0, 1.0, 0};

node comb(const node &l, const node &r){
	node ans;
	ans.c = l.c + r.c;
	ans.l = l.l*p[r.c] + r.l;
	ans.r = l.r + p[l.c] * r.r;
	return ans;
}

void upd(int v, int l, int r, int p){
	if (l + 1 == r){
		t[v] = one;
		return;
	}
	int m = (l + r) / 2;
	if (p < m)
		upd(2 * v, l, m, p);
	else
		upd(2 * v + 1, m, r, p);

	t[v] = comb(t[2 * v], t[2 * v + 1]);
}

void build(int v, int l, int r){
	if (l + 1 == r){
		t[v] = zero;
		return;
	}
	int m = (l + r) / 2;
	build(2 * v, l, m);
	build(2 * v + 1, m, r);
	t[v] = comb(t[2 * v], t[2 * v + 1]);
}

node get(int v, int l, int r, int le, int re){
	if (l == le && r == re)
		return t[v];
	int m = (l + r) / 2;
	if (re <= m)
		return get(2 * v, l, m, le, re);
	if (m <= le)
		return get(2 * v + 1, m, r, le, re);

	return comb(get(2 * v, l, m, le, m), get(2 * v + 1, m, r, m, re));
}

void read(void){
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> b[i].first;
		b[i].second = i;
	}
	sort(b, b + n);
}

void kill(void){
	long double ans = 0.0;
	node l, r;
	for (int i = n - 1; i >= 0; --i){
		int pos = b[i].second;
		l = get(1, 0, n+1, 0, pos+1);
		r = get(1, 0, n+1, pos + 1, n+1);

		//cout << b[i].first << ": " << l.l << "-" << r.r << "\n";

		ans = ans + b[i].first*l.l*r.r;

		upd(1, 0, n + 1, pos);

	}

	cout.precision(10);
	cout << fixed;

	cout << ans / n / n/2 << "\n";
}

int main(){
#ifdef TROLL
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#else
	ios_base::sync_with_stdio(0);
#endif

	pre();
	read();
	build(1, 0, n+1);
	kill();


	return 0;
}