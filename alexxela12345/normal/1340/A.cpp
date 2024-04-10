#ifndef DEBUG
#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,abm,mmx,popcnt")
#endif
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
typedef long double ldb;

int n;

const int MAXN = 1e5 + 228;


int par[MAXN];
int rk[MAXN];

multiset<int> sizes;

void init(int n) {
	sizes.clear();
	for (int i = 0; i <= n; i++) {
		par[i] = i;
		rk[i] = 1;
		if (i)
			sizes.insert(1);
	}
}

int get(int v) {
	if (par[v] == v) {
		return v;
	}
	return par[v] = get(par[v]);
}

void merge(int a, int b) {
	a = get(a);
	b = get(b);
	if (a == b) {
		return;
	}
	if (get(a) != get(n)) {
		sizes.erase(sizes.find(rk[a]));
	}
	if (get(b) != get(n)) {
		sizes.erase(sizes.find(rk[b]));
	}
	if (rk[b] > rk[a]) {
		swap(a, b);
	}
	par[b] = a;
	rk[a] += rk[b];
	if (get(n) != get(a)) {
		sizes.insert(rk[a]);
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(12);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> arr(n);
		vector<int> rev(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			arr[i]--;
			rev[arr[i]] = i;
		}
		init(n);
		bool good = 1;
		for (int i = 0; i < n; i++) {
			if (rk[get(rev[i])] != *sizes.rbegin()) {
				good = 0;
				break;
			} else {
				merge(rev[i], rev[i] + 1);
			}
		}
		if (good) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}

// If interactive problem remove #define endl '\n'
// CopyPasted part from BenQ:

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/