#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int Mx = (int) 1e5 + 9;
int c[Mx + 9];
map<int, int> mp;

bool valid() {
	mp.erase(0);
	assert(!mp.empty());

	auto it = mp.begin();

	if (mp.size() == 1)
		return it->first == 1 || it->second == 1;
	if (mp.size() != 2)
		return false;
	auto it2 = next(it);
	if (it->first + 1 == it2->first && it2->second == 1)
		return true;
	return it->first == 1 && it->second == 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int ans = 0;
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		if (!--mp[c[x]])
			mp.erase(c[x]);
		++mp[++c[x]];
		if (valid())
			ans = i;
	}
	cout << ans;
	return 0;
}