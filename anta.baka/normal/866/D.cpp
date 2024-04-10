#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll s, ret;
multiset<int> setik;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		setik.insert(x);
		setik.insert(x);
		s += x - *setik.begin();
		ret = max(ret, s);
		setik.erase(setik.begin());
	}
	cout << ret;
}