#include <bits/stdc++.h>
using namespace std;

inline int ask(int i, int j) {
	cout << '?' << ' ' << i << ' ' << j << endl;
	int ret; cin >> ret; return ret;
}

int n, p0[5000], b0[5000], p[5000], b[5000], ret, f = -1, v[5000];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) p0[i] = ask(0, i), b0[i] = ask(i, 0);
	for(p[0] = 0; p[0] < n; p[0]++) {
		for(int i = 0; i < n; i++) b[i] = (p0[i] ^ p[0]), p[i] = (b0[i] ^ b[0]);
		bool ok = true;
		for(int i = 0; i < n; i++) ok &= (p[b[i]] == i);
		if(ok) {
			ret++;
			if(f == -1) {
				f = 0;
				for(int i = 0; i < n; i++) v[i] = p[i];
			}
		}
	}
	cout << '!' << endl << ret << endl;
	for(int i = 0; i < n; i++) cout << v[i] << ' ';
	cout << endl;
}