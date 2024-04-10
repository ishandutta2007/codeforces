#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
map<int, pair<int, int> > mp;
pair<int, int> root(int a) {
	if (mp.count(a) == 0) {
		return pair<int, int>(-1, 0);
	}
	if (mp[a].first == a) {
		return mp[a];
	}
	pair<int, int> t = root(mp[a].first);
	mp[a].first = t.first;
	mp[a].second ^= t.second;
	return mp[a];
}
int getVal(int a, int b) {
	pair<int, int> pa = root(a);
	pair<int, int> pb = root(b);
	if (pa.first == -1 || pb.first == -1)return -1;
	if (pa.first != pb.first) return -1;
	return pa.second ^ pb.second;
}
int unionSet(int a, int b, int c) {
	if (getVal(a, b) == -1) {
		if (mp.count(b) == 0) {
			mp[b] = pair<int, int>(b, 0);
		}
		else {
			pair<int, int> t = root(b);
			b = t.first;
			c ^= t.second;
		}
		if (mp.count(a) == 0) {
			mp[a].first = b;
			mp[a].second = c;
		}
		else {
			pair<int, int> t = root(a);
			a = t.first;
			c ^= t.second;
			mp[a].first = b;
			mp[a].second = c;
		}
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int Q;
	cin >> Q;
	int res = 0;
	int t;
	int l, r, v;
	int last = 0;
	for (int i = 0; i < Q; i++) {
		cin >> t;
		if (t == 1) {
			cin >> l >> r >> v;
			l ^= last;
			r ^= last;
			v ^= last;
			if (l > r)swap(l, r);
			r++;
			unionSet(l, r, v);
		}
		else {
			cin >> l >> r;
			l ^= last;
			r ^= last;
			if (l > r)swap(l, r);
			//cerr << l << " " << r << endl;
			r++;
			res = getVal(l, r);
			cout << res << endl;
			last = res;
			if (last == -1)last = 1;
		}
	}
}