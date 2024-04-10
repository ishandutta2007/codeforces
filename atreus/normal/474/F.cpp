#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = (int)1e9 + 7;
const int maxn = (int)1e5 + 100;
const int infint = (int)1e9;
const ll inf = (ll)1e18;
const int del = 10799;
ll n, gc[4 * maxn], s[maxn];
pair <ll, ll> seg[4 * maxn];

ll gcdd (ll a, ll b){
	if (a > b)
		swap (a, b);
	if (a == 0)
		return b;
	if (b % a == 0)
		return a;
	return gcdd(a, b % a);
}

ll getgcd (int id, int L, int R, int l, int r){
	if (L == l and R == r)
		return gc[id];
	int mid = (L + R) / 2;
	ll gcd = 0;
	if (mid > l)
		gcd = gcdd (gcd, getgcd (2 * id + 0, L, mid, l, min (r, mid)));
	if (mid < r)
		gcd = gcdd (gcd, getgcd (2 * id + 1, mid, R, max (mid, l), r));
	return gcd;
}

void buildgcd (int id, int l, int r){
	if (l + 1 == r){
		gc[id] = s[l];
		return;
	}
	int mid = (l + r) / 2;
	buildgcd (2 * id + 0, l, mid);
	buildgcd (2 * id + 1, mid, r);
	gc[id] = gcdd (gc[2 * id + 0], gc[2 * id + 1]);
}

pair <ll, ll> merge (pair <ll, ll> a, pair <ll, ll> b){
	if (a.F == b.F)
		return MP (a.F, a.S + b.S);
	if (a.F < b.F)
		return a;
	return b;
}

pair <ll, ll> get (int id, int L, int R, int l, int r){
	if (L == l and R == r)
		return seg[id];
	int mid = (L + R) / 2;
	pair <ll, ll> a = MP(inf, inf), b = MP(inf, inf);
	if (mid > l)
		a = get (2 * id + 0, L, mid, l, min (r, mid));
	if (mid < r)
		b = get (2 * id + 1, mid, R, max (l, mid), r);
	return merge (a, b);
}

void build (int id, int l, int r){
	if (l + 1 == r){
		seg[id].F = s[l];
		seg[id].S = 1;
		return;
	}
	int mid = (l + r) / 2;
	int idb = 2 * id + 1, idk = 2 * id + 0;
	build (idk, l, mid);
	build (idb, mid, r);
	seg[id] = merge (seg[idk], seg[idb]);
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	n ++;
	for (int i = 1; i < n; i++)
		cin >> s[i];
	build (1, 1, n);
	buildgcd (1, 1, n);
	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; i++){
		int l, r;
		cin >> l >> r;
		r ++;
		pair <ll, ll> a = get (1, 1, n, l, r);
		ll b = getgcd (1, 1, n, l, r);
		if (a.F == b)
			cout << r - l - a.S << endl;
		else
			cout << r - l << endl;
	}
}