#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <limits>
#include <ctime>
#include <random>

#define pb push_back
#define mp make_pair
#define rn(n) int n; cin >> n
#define fi(n) for (int i = 0; i < (int)n; ++i)
#define fie(n) for (int i = 1; i <= (int)n; ++i)
#define fir(l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define fj(n) for (int j = 0; j < (int)n; ++j)
#define fje(n) for (int j = 1; j <= (int)n; ++j)
#define fjr(l, r) for (int j = (int)(l); j <= (int)(r); ++j)
#define fv(i, n) for (int i = 0; i < (int)n; ++i)
#define fve(i, n) for (int i = 1; i <= (int)n; ++i)
#define fvr(j, l, r) for (int j = (int)(l); j <= (int)(r); ++j)
#define sc(n) scanf("%d", &n)
#define scc(n) scanf("%c", &n)
#define scs(n) scanf("%s", &n)
#define scl(n) scanf("%l64d", &n)
#define endl '\n'
#define sqr(x) ((x) * (x))
#define F first
#define S second
#define fll(x, a) memset(x, a, sizeof(x))
#define clr(x) memset(x, 0, sizeof(x))
#define IOboost ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int ll

#pragma warning (disable : 4996)
#pragma optimize ("gtsy", on)
//#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <pii> vii;
typedef vector <char> vc;
typedef vector <ll> vll;
typedef vector <vll> vvll;

const ld EPS = 1e-9;
const int N = (int)1e5 + 10;
const int INF = (int)1e9 + 10;
const int MOD = (int)1e9 + 7;

struct Node {
	int x, y = rand(), k, sum;
	Node *L, *R;
	Node(int x, int k) : x(x), L(nullptr), R(nullptr), k(k), sum(k) {};
};

int summ(Node *t) {
	if (t == nullptr)
		return 0;
	return t->sum;
}

void update(Node *t) {
	t->sum = summ(t->L) + summ(t->R) + t->k;
	return;
}

Node* merge(Node *a, Node *b) {
	if (a == nullptr)
		return b;
	if (b == nullptr)
		return a;
	if (a->y < b->y) {
		a->R = merge(a->R, b);
		update(a);
		return a;
	}
	else {
		b->L = merge(a, b->L);
		update(b);
		return b;
	}
}

pair<Node*, Node*> splitl(Node *t, int x) {
	if (t == nullptr)
		return { nullptr, nullptr };
	if (t->x <= x) {
		auto r = splitl(t->R, x);
		t->R = r.first;
		update(t);
		r.first = t;
		return r;
	}
	else {
		auto l = splitl(t->L, x);
		t->L = l.second;
		update(t);
		l.second = t;
		return l;
	}
}

pair<Node*, Node*> splitr(Node *t, int x) {
	if (t == nullptr)
		return { nullptr, nullptr };
	if (t->x < x) {
		auto r = splitr(t->R, x);
		t->R = r.first;
		update(t);
		r.first = t;
		return r;
	}
	else {
		auto l = splitr(t->L, x);
		t->L = l.second;
		update(t);
		l.second = t;
		return l;
	}
}

pair<int, Node*> insertl(Node *t, int x, int k) {
	Node *n = new Node(x, k);
	auto p = splitl(t, x);
	int ans = summ(p.first);
	return { ans + k, merge(p.first, merge(n, p.second)) };
}

pair<int, Node*> insertr(Node *t, int x, int k) {
	Node *n = new Node(x, k);
	auto p = splitr(t, x);
	int ans = summ(p.second);
	return { ans + k, merge(p.first, merge(n, p.second)) };
}

bool comp(pair<pii, int>& a, pair<pii, int>& b) {
	if (a.first.first != b.first.first)
		return a.first.first > b.first.first;
	return a.first.second < b.first.second;
}

signed main() {
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;

	Node *t = nullptr;
	rn(n);
	vector<pair<pii, int>> a(n);
	fi(n) cin >> a[i].first.first >> a[i].first.second;
	sort(a.rbegin(), a.rend());
	fi(n) {
		if (!i || a[i].first.first != a[i - 1].first.first) {
			auto p = insertr(t, a[i].first.second, 1);
			t = p.second;
			a[i].second = p.first;
		}
		else {
			auto p = splitr(t, a[i].first.second);
			a[i].second = summ(p.second);
			t = merge(p.first, p.second);
		}
	}
	sort(a.begin(), a.end(), comp);
	map<int, vi> m;
	fi(n)
		m[a[i].first.second].pb(i);
	for (auto i : m) {
		sort(i.second.begin(), i.second.end());
		int sum = 0;
		fj(i.second.size()) {
			a[i.second[j]].second -= sum;
			sum += a[i.second[j]].second;
		}
	}
	t = nullptr;
	int ans = 0;
	fi(n) {
		auto p = insertl(t, a[i].first.second, a[i].second);
		t = p.second;
		if ((i + 1 == n) || a[i].first.first != a[i + 1].first.first)
			ans += p.first;
	}
	cout << ans;

	return 0;
}