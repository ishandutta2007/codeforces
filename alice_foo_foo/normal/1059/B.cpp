#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i <= b; i++)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
    while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
    f *= fu;
}

const int N = 1010;

int a[N][N], b[N][N];
int n, m, ans= 3;

int main() {
	read(n), read(m);
	for(int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c = getchar();
			while (c != '#' && c != '.') c = getchar();
			if(c == '#') a[i][j] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i + 1][j] == 1 && a[i][j + 1] == 1 && a[i + 1][j + 1] == 1 && a[i - 1][j] && a[i][j - 1] && a[i - 1][j - 1] && a[i - 1][j + 1] && a[i + 1][j - 1]) {
				for(int x = i - 1; x <= i + 1; x++) {
					for(int y = j - 1; y <= j + 1; y++) {
						if(x == i && y == j) continue;
						b[x][y] = 1;
					}
				}
			}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (a[i][j] && (b[i][j] == 0)) ans = 0;
	if (ans) cout << "YES" << endl; else cout << "NO" << endl;
	return 0;
}