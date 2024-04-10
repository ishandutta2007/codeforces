#include <bits/stdc++.h>
using namespace std;

inline int ask(vector<int> &vec) {
	cout << '?' << ' ' << vec.size() << ' ';
	for(int x : vec) cout << x << ' ';
	cout << endl;
	int ret; cin >> ret; return ret;
}

int n, x, y, dif[10], i1, i2;
vector<int> a;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> x >> y;
	for(int i = 0; i < 10; i++) {
		vector<int> vec;
		for(int j = 1; j <= n; j++)
			if((j & (1 << i)) == 0)
				vec.push_back(j);
		int xr = ask(vec);
		if(vec.size() & 1) {
			if(xr == y) dif[i] = 1, a = vec;
		} else {
			if(xr == (y ^ x)) dif[i] = 1, a = vec;
		}
	}
	int lf = 0, rg = a.size() - 1;
	while(lf < rg) {
		int md = (lf + rg) / 2;
		vector<int> vec;
		for(int i = 0; i <= md; i++) vec.push_back(a[i]);
		int xr = ask(vec);
		if(vec.size() & 1) {
			if(xr == y) rg = md;
			else lf = md + 1;
		} else {
			if(xr == (x ^ y)) rg = md;
			else lf = md + 1;
		}
	}
	i1 = i2 = a[lf];
	for(int i = 0; i < 10; i++) if(dif[i]) i2 ^= (1 << i);
	if(i1 > i2) swap(i1, i2);
	cout << '!' << ' ' << i1 << ' ' << i2 << endl;
}