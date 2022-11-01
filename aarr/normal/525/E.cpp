#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int N = 27, Q = 20;
int n, n1, n2, k;
long long s, ans;


int a[N];
long long fac[Q];

map <long long, vector <int> > mp;

void bt1(int x = 0, long long sm = 0, int c = 0) {
	if (sm > s || c > k) {
		return;
	}
	if (x == n1) {
		mp[sm].push_back(c);
	//	if (c == 2 && sm == 7)
	//	cout << "72 " << sm << " " << c << endl;
		return;
	}
	bt1(x + 1, sm, c);
	bt1(x + 1, sm + a[x], c);
	if (a[x] < Q) {
		bt1(x + 1, sm + fac[a[x]], c + 1);
	}
}

void bt2(int x = n1, long long sm = 0, int c = 0) {
	if (sm > s || c > k) {
		return;
	}
	if (x == n) {
	
		if (mp[s - sm].size()) {
		//	cout << "73 " << sm << " " << c << " " << upper_bound(mp[s - sm].begin(), mp[s - sm].end(), k - c) - mp[s - sm].begin() << " " << mp[s - sm][16] << endl;
			int x = upper_bound(mp[s - sm].begin(), mp[s - sm].end(), k - c) - mp[s - sm].begin();
			ans += x;
		}
		return;
	}
	bt2(x + 1, sm, c);
	bt2(x + 1, sm + a[x], c);
	if (a[x] < Q) {
		bt2(x + 1, sm + fac[a[x]], c + 1);
	}
}

int main() {
	cin >> n >> k >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	fac[0] = 1;
	for (int i = 1; i < Q; i++) {
		fac[i] = fac[i - 1] * i;
	}
	n1 = n / 2, n2 = n - n1;
	bt1();
//	cout << 75 << " " << mp[7].size() << endl;
	for (auto p : mp) {
	//	cout << 79 << endl;
		sort(mp[p.first].begin(), mp[p.first].end());
	}
//	for (auto x : mp[7]) {
//		cout << x << " ";
//	}
	bt2();
	cout << ans;
	return 0;
}