#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> x, y;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	vector<int> q;
	int e = n - 1;
	for(int i = 0; i < k - 2; i++) {
		x.push_back(1);
		y.push_back(i + 2);
		q.push_back(i + 2);
		e--;
	}
	int v = k;
	int pt = 0;
	for(int d = 2; k != 2; ) {
		if(d > (e - 1) / 2) break;
		x.push_back(q[pt]);
		y.push_back(v);
		q[pt] = v;
		v++;
		pt++;
		if(pt == q.size()) {
			pt = 0;
			d++;
		}
		e--;
	}
	int r = 1;
	for(int i = 0; i < e / 2; i++)
		x.push_back(r), y.push_back(v), r = v, v++;
	r = 1;
	for(int i = 0; i < e / 2; i++)
		x.push_back(r), y.push_back(v), r = v, v++;
	if(v == n)
		x.push_back(r), y.push_back(v);
	cout << e << '\n';
	for(int i = 0; i < n - 1; i++)
		cout << x[i] << ' ' << y[i] << '\n';
}