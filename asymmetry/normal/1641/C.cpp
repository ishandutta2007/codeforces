//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
template<class A,class B>auto&operator<<(ostream&o,pair<A,B>p){return o<<'('<<p.first<<", "<<p.second<<')';}
template<class T>auto operator<<(ostream&o,T x)->decltype(x.end(),o){o<<'{';int i=0;for(auto e:x)o<<(", ")+2*!i++<<e;return o<<'}';}
#define debug(x...) cerr<<"["#x"]: ",[](auto...$){((cerr<<$<<"; "),...);}(x),cerr<<'\n'
#else
#define debug(...) {}
#endif

struct node {
	int mn, p;
};

const int N = 201000;
int n, q, com, a, b, c;
vector<node> st;
set<pair<int, int>> S;

void push(int x) {
	if (st[x].p) {
		int l = x << 1;
		int r = l ^ 1;
		st[l].mn = st[x].p;
		st[l].p = st[x].p;
		st[r].mn = st[x].p;
		st[r].p = st[x].p;
		st[x].p = 0;
	}
}

void ins(int x, int l, int r, int ll, int rr, int w) {
	if (l > rr || ll > r) {
		return;
	}
	if (ll <= l && r <= rr) {
		st[x].mn = w;
		st[x].p = w;
		return;
	}
	push(x);
	ins(x * 2, l, (l + r) / 2, ll, rr, w);
	ins(x * 2 + 1, (l + r) / 2 + 1, r, ll, rr, w);
	st[x].mn = min(st[x * 2].mn, st[x * 2 + 1].mn);
}

int zap(int x, int l, int r, int ll, int rr) {
	if (l > rr || ll > r) {
		return 1;
	}
	if (ll <= l  && r <= rr) {
		return st[x].mn;
	}
	push(x);
	return min(zap(x * 2, l, (l + r) / 2, ll, rr), zap(x * 2 + 1, (l + r) / 2 + 1, r, ll, rr));
}

vector<int> v;
void dajl(int x, int l, int r, int ll, int rr) {
	if (l > rr || ll > r) {
		return;
	}
	if (ll <= l && r <= rr) {
		v.push_back(x);
		return;
	}
	push(x);
	dajl(x * 2 + 1, (l + r) / 2 + 1, r, ll, rr);
	dajl(x * 2, l, (l + r) / 2, ll, rr);
}

void dajr(int x, int l, int r, int ll, int rr) {
	if (l > rr || ll > r) {
		return;
	}
	if (ll <= l && r <= rr) {
		v.push_back(x);
		return;
	}
	push(x);
	dajr(x * 2, l, (l + r) / 2, ll, rr);
	dajr(x * 2 + 1, (l + r) / 2 + 1, r, ll, rr);
}

int flf(int x) {
	if (!x) {
		return 1;
	}
	v.clear();
	dajl(1, 1, com, 1, x);
	for (int i : v) {
		if (st[i].mn) {
			continue;
		}
		while (i < com) {
			i <<= 1;
			if (!st[i ^ 1].mn) {
				i ^= 1;
			}
		}
		return i - com + 2;
	}
	return 1;
}

int frg(int x) {
	if (x > n) {
		return n;
	}
	v.clear();
	dajr(1, 1, com, x, com);
	for (int i : v) {
		if (st[i].mn) {
			continue;
		}
		while (i < com) {
			i <<= 1;
			if (st[i].mn) {
				i ^= 1;
			}
		}
		return i - com;
	}
	return 1;
}

bool inside(int lf, int rg) {
	auto x = S.lower_bound({lf, -1e9});
	if ((*x).second <= rg) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	scanf("%d%d", &n, &q);
	com = 1;
	while (com < n) {
		com <<= 1;
	}
	st.resize(com << 1);
	S.insert({1e9, 1e9});
	S.insert({-1e9, -1e9});
	for (int i = 1; i <= q; ++i) {
		scanf("%d", &a);
		if (a == 0) {
			scanf("%d%d%d", &a, &b, &c);
			if (c == 0) {
				ins(1, 1, com, a, b, 1);
			}
			else {
				auto x = S.lower_bound({a, 0});
				if ((*x).second <= b) {
					continue;
				}
				--x;
				vector<pair<int, int>> er;
				while ((*x).second >= b) {
					er.push_back(*x);
					--x;
				}
				for (auto i : er) {
					S.erase(i);
				}
				S.insert({a, b});
			}
		}
		else {
			scanf("%d", &a);
			if (zap(1, 1, com, a, a) == 1) {
				printf("NO\n");
				continue;
			}
			int lf = flf(a - 1);
			int rg = frg(a + 1);
			debug(lf, rg);
			if (inside(lf, rg)) {
				printf("YES\n");
			}
			else {
				printf("N/A\n");
			}
		}
	}
	return 0;
}