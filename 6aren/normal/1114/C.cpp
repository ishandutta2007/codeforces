#include <bits/stdc++.h>

using namespace std;

long long n, b;

vector<pair<long long, long long>> p;

long long check(long long x, pair<long long, long long> y) {
	long long  u = y.first, v = y.second;
	long long res = 0;
	x /= u;
	while (x != 0) {
		res += x;
		x /= u;
	}
	res /= v;
	return res;
}

int main() {
	//freopen("in", "r", stdin);
	cin >> n >> b;
	for (int i = 2; 1LL * i * i <= b; i++) {
		if (b % i == 0) {
			int cnt = 0;
			while (b % i == 0) {
				b /= i;
				cnt++;
			}
			p.push_back(make_pair(i, cnt));
		}
	}
	if (b != 1) {
		p.push_back(make_pair(b, 1));
	}
	long long mini = 1e18 + 1;
	for (int i = 0; i < p.size(); i++) {
		mini = min(mini, check(n, p[i]));
	}
	cout << mini << endl;
	return 0;
}
/* 
g++ online.cpp -o online.exe
*/