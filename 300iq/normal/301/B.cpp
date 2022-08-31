#include <bits/stdc++.h>

using namespace std;

int g[100][100];
int n;
int a[100];
int x[100];
int y[100];
int d[100];

bool check(int m) {
    for (int i = 0; i < 100; i++)
	d[i] = -1;
    d[0] = m;
    for (int it = 0; it < n; it++) {
	for (int i = 0; i < n; i++) {
	    for (int j = 1; j < n; j++) {
		if (i == j) continue;
		if (d[i] - g[i][j] >= 0) {
		    d[j] = max(d[j], d[i] - g[i][j] + a[j]);
		}
	    }
	}
    }
    return (d[n - 1] != -1);
}

int main() {
    int d;
    cin >> n >> d;
    for (int i = 1; i < n - 1; i++)
	cin >> a[i];
    for (int i = 0; i < n; i++)
	cin >> x[i] >> y[i];
    for (int i = 0; i < n; i++) {
	for (int j = i + 1; j < n; j++) {
	    g[i][j] = g[j][i] = d * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
	}
    }
    int l = 0;
    int r = 100000000;
    while (l < r - 1) {
	int m = (l + r) / 2;
	if (check(m)) {
	    r = m;
	} else {
	    l = m;
	}
    }
    cout << r << endl;
}