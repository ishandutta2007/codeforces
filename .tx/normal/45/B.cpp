#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int nextInt() {
	int res = 0;
	char c = getchar();
	while (c < '0' || c > '9') {
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, i;
	//cin >> n >> m;
	n = nextInt();
	m = nextInt();
	vector<int> g(n), v(m), b(m);//, d(m, 0);
	for (i = 0; i < n; i++) {
		//cin >> g[i];
		g[i] = nextInt();
		g[i]--;
	}
	for (i = 0; i < m; i++) {
		//cin >> v[i];
		v[i] = nextInt();
	}
	for (i = 0; i < m; i++) {
		//cin >> b[i];
		b[i] = nextInt();
		if (b[i] > n) b[i] = n;
	}
	int a, res = 0, res1, k = 0, x;
	vector<int> u(n, 0);
	for (i = 0; i < m && k < n; i++) {
		a = ((v[i] + res - 1) % n);
		res1 = 0;
		x = b[i];
		while (x) {
			if (u[a] >= x) break;
			if (!u[a]){ 
				res1++;
				k++;
			}
			u[a] = x;
			a = g[a];
			x--;
		}
		cout << res1 << endl;
		res = res1;
	}
	for (int f = i; i < m; i++) {
		cout << "0\n";
	}
	return 0;
}//lekjsf