#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) ll(0); //cerr << #v << " = " << (v) << endl;

vector<int> getBasis(const vector<int> &S) {
	vector<int> v, res;
	for (const int x : S) {
		int y = x;
		for (const int z : v)
			y = min(y, y ^ z);
		if (y) {
			v.push_back(y);
			res.push_back(x);
		}
	}
	return res;
}

vector<int> getP(const int K) {
	if (K == 0)
		return {0};

	vector<int> v = { 0, 1 };
	for (int k = 1; k < K; ++k) {
		const int n = (int) v.size();
		v.resize(2 * n);
		copy(v.begin(), v.begin() + n, v.rbegin());
		for (int i = 0; i < n; ++i)
			v[i] |= 1 << k;
	}

	return v;
}

int getSubset(const vector<int> &v, const int mask) {

	int res = 0;
	for (int i = 0; i < (int) v.size(); ++i) {
		if (mask & (1 << i))
			res ^= v[i];
	}
	return res;
}

void f(const vector<int> &S, const int k) {
	const vector<int> basis = getBasis(S);
	assert((int )basis.size() <= k);
	if ((int) basis.size() != k)
		return;

	const vector<int> perm = getP(k);
	vector<int> pos(1 << k, 888);

	for (int _perm : perm)
		DBG(_perm);

	for (int i = 0; i < (1 << k); ++i)
		pos[perm[i]] = i;

	for (int _pos : pos)
		DBG(_pos);

	vector<int> res(1 << k, 999);

	for (int i = 0; i < (1 << k); ++i) {
		const int j = getSubset(basis, i);
		DBG(j);
		res[pos[i]] = j;
	}
	cout << k << endl;
	for (int x : res)
		cout << x << ' ';
	exit(0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> S(n);
	for (int &x : S)
		cin >> x;
	sort(S.begin(), S.end());

	for (int k = 20; k >= 0; --k) {

		vector<int> v(S.begin(), lower_bound(S.begin(), S.end(), 1 << k));
		f(v, k);
	}
	assert(false);
	return 0;
}