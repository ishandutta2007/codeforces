#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> void chmax(T& a, T b) { a = max(a, b); }
template<class T> void chmin(T& a, T b) { a = min(a, b); }

template<class T> class BIT {
	static const int n = ten(5) * 2 + 10;
	T bit[n + 1];
public:
	BIT() { memset(bit,0,sizeof(bit)); }
	T sum(int i) {
		T s = 0;
		while (i > 0) { s += bit[i]; i -= i & -i; }
		return s;
	}
	void add(int i, T x) {
		while (i <= n) { bit[i] += x; i += i & -i; }
	}
};


vector<int> f(vector<int>& v){
	vector<int> ret;
	BIT<int> bit;
	FOR(i, sz(v)){
		int sm = bit.sum(v[i] + 1);
		bit.add(v[i] + 1, 1);
		ret.push_back(v[i] - sm);
	}
	return ret;
}

typedef int valT;

struct node {
	valT val; //l
	node *chl, *chr; //{,E}
	int pri; //Dx
	int cnt; //TCY
	bool rev; //t
	node() {}
	node(valT v) : val(v), pri(rand()), cnt(1), rev(false) {
		chl = chr = NULL;
	}
};
typedef pair<node*, node*> PN;
void push_flip(node *t);

node *node_allocator(valT val) {
	static node arr[ten(7)];
	static int cnt = 0;
	arr[cnt++] = node(val);
	return &arr[cnt - 1];
}
int count(const node* t) { return t ? t->cnt : 0; }
node* update(node *t) {
	t->cnt = count(t->chl) + count(t->chr) + 1;
	return t;
}
node *merge(node *l, node *r) {
	if (!l || !r) return l ? l : r;
	push_flip(l); push_flip(r);
	if (l->pri > r->pri) { //Dx
		l->chr = merge(l->chr, r); //Eq}
		return update(l);
	} else {
		r->chl = merge(l, r->chl); //Eq}
		return update(r);
	}
}
PN split(node* t, int k) { //[0,k),[k,n)
	if (!t) return PN(NULL, NULL);
	push_flip(t);
	if (k <= count(t->chl)) {
		PN s = split(t->chl, k);
		t->chl = s.second;
		return PN(s.first, update(t));
	} else {
		PN s = split(t->chr, k - count(t->chl) - 1);
		t->chr = s.first;
		return PN(update(t), s.second);
	}
}
node* insert(node* t, int k, valT val) {
	push_flip(t);
	PN s = split(t, k);
	return merge(merge(s.first, node_allocator(val)), s.second);
}
node *erase(node *t, int k) {
	push_flip(t);
	PN sl = split(t, k);
	PN sr = split(sl.second, 1);
	return merge(sl.first, sr.second);
}
node *kth(node *t, int k) {
	assert(t != NULL);
	push_flip(t);
	if (k < count(t->chl)) return kth(t->chl, k);
	else if (k == count(t->chl)) return t;
	else return kth(t->chr, k - count(t->chl) - 1);
}

void push_flip(node *t) {
	if (t && t->rev) {
		swap(t->chl, t->chr);
		if (t->chl) t->chl->rev ^= true;
		if (t->chr) t->chr->rev ^= true;
		t->rev = false;
	}
}

int main(){
	int n; scanf("%d", &n);
	vector<int> a(n), b(n);
	FOR(i, n) scanf("%d", &a[i]);
	FOR(i, n) scanf("%d", &b[i]);

	auto x = f(a);
	auto y = f(b);

	vector<int> ansidx(n + 1);
	for (int i = n - 1; i >= 0; i--) {
		int md = n - i;
		ansidx[i + 1] += x[i] + y[i];
		if (ansidx[i + 1] >= md) ansidx[i + 1] -= md, ansidx[i]++;
	}
	node *root = NULL;
	FOR(i, n) root = insert(root, i, i);

	for (int i = 1; i <= n; i++) {
		int ans = kth(root, ansidx[i])->val;
		root = erase(root, ansidx[i]);
		printf("%d%c", ans, i == n ? '\n' : ' ');
	}

}