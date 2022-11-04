#include <bits/stdc++.h>
using namespace std;
char a[10][10];
vector<pair<char, char> > ans;
inline void L(int i) {
	char t = a[i][0];
	for (int j = 0; j < 5; j++) a[i][j] = a[i][j + 1];
	a[i][5] = t;
	ans.emplace_back('L', i + '1');
}
inline void R(int i) {
	char t = a[i][5];
	for (int j = 5; j; j--) a[i][j] = a[i][j - 1];
	a[i][0] = t;
	ans.emplace_back('R', i + '1');
}
inline void U(int j) {
	char t = a[0][j];
	for (int i = 0; i < 5; i++) a[i][j] = a[i + 1][j];
	a[5][j] = t;
	ans.emplace_back('U', j + '1');
}
inline void D(int j) {
	char t = a[5][j];
	for (int i = 5; i; i--) a[i][j] = a[i - 1][j];
	a[0][j] = t;
	ans.emplace_back('D', j + '1');
}
inline void SH(int i, int j) { // swap (i, j) and (i, j + 1)
	R(i);
	U(j);
	R(i);
	D(j);
	R(i);
	U(j);
	R(i);
	D(j);
	R(i);
	U(j);
	R(i);
	R(i);
	D(j);
}
inline void SV(int i, int j) { // swap (i, j) and (i + 1, j)
	D(j);
	L(i);
	D(j);
	R(i);
	D(j);
	L(i);
	D(j);
	R(i);
	D(j);
	L(i);
	D(j);
	D(j);
	R(i);
}
int main() {
	for (int i = 0; i < 6; i++) scanf(" %s", a[i]);
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			int s = i * 6 + j;
			char need;
			if (s < 10) need = s + '0';
			else need = s - 10 + 'A';
			int found = 0;
			for (int x = 0; x < 6; x++) {
				for (int y = 0; y < 6; y++) if (a[x][y] == need) {
					while (y < j) SH(x, y++);
					while (y > j) SH(x, --y);
					while (x > i) SV(--x, y);
					found = 1;
					break;
				}
				if (found) break;
			}
		}
	}
	printf("%d\n", (int)ans.size());
	for (auto &P : ans) printf("%c%c\n", P.first, P.second);
	return 0;
}