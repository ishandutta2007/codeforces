#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int qRem = 60;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n;
	cin >> n;

	int lo = 0, hi = (int) 1e9;
	while (lo < hi) {
		const int mid = (lo + hi) / 2;
		cout << "> " << mid << endl;

		int ans;
		cin >> ans;
		if (ans)
			lo = mid + 1;
		else
			hi = mid;
		qRem--;
	}

	vector<int> permutation(n);

	for (int i = 0; i < n; i++)
		permutation[i] = i + 1;

	shuffle(permutation.begin(), permutation.end(), rng);

	assert(qRem > 0);

	vector<int> v;

	for (int i = 0; i < n && qRem > 0; ++i) {
		qRem--;
		cout << "? " << permutation[i] << endl;
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());
	int g = 0;
	for (int i = 1; i < (int) v.size(); ++i)
		g = gcd(g, v[i] - v[i - 1]);
	cout << "! " << lo - (n - 1) * g << ' ' << g << endl;

	return 0;
}