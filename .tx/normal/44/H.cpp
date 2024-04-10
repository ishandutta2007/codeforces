#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

vector<int> a, b;
vector< vector<int> > d(10, vector<int>(10));
vector< vector<bool> > dd(10, vector<bool>(10));
int m[10][10][51];
int z[10][10];

long long kol = 0;
int n, f;
bool fl, fl1 = true;

int gsom(int i, int y) {
	if (i == 1) {
		return 1;
	}
	if (i == 0) {
		return 0;
	}
	int x = a[n - i + 1];
	if (m[x][y][i]) {
		return m[x][y][i];
	}
	else {
		int xx = i - 1;//z[x][y];
		if (xx < 0){ 
			xx = i - 1;
		}
		long long k = gsom(xx,  d[x][y]);
		if (dd[x][y]) {
			k += gsom(xx, d[x][y] + 1);
		}
		m[x][y][i] = k;
		z[x][y] = i;
		return m[x][y][i];
	}	
}



int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	char c;
	while (scanf("%c", &c) != -1 && c != 10) {
		a.push_back(c - '0');
	}
	int i, g;
	n = a.size();
	b.resize(n);

	memset(m, 0, sizeof(m));

	for (i = 0; i < 10; i++) {
		for (g = 0;  g < 10; g++) {
			d[i][g] = (i + g) / 2;
			dd[i][g] = (i + g) % 2 != 0;
			m[i][g][1] = 1;
			z[i][g] = 1;
		}
	}

	for (i = 0; i < 10; i++) {
		kol += gsom(n, i);
	}
	bool fff = true;
	for (i = 1; i < n; i++) {
		if (abs(a[i] - a[i-1]) > 1) {
			fff = false;
			break;
		}
	}
	if (fff) kol--;
	/*for (i = 0; i < 10; i++) {
		cout << m[a[1]][i][n] << endl;
	}*/
	cout << kol;
	return 0;
}//vihstl