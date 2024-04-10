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

const int N = 1000 + 5;
const ll P = 998244353;

ll f[N][N << 1][2][2];
int n, k;

int main() {
	memset(f, -1, sizeof(f));
	cin >> n >> k;
	f[1][1][0][0] = 1; f[1][2][0][1] = 1;
	f[1][2][1][0] = 1; f[1][1][1][1] = 1;
	for(int i = 1; i < n; i++) {
		for(int j = 1; j <= (n << 1); j++) {
			for(int k = 0; k <= 1; k++) {
				for(int t = 0; t <= 1; t++) {
					if(f[i][j][k][t] == -1) continue;
					for(int _i = 0; _i <= 1; _i++) {
						for(int _j = 0; _j <= 1; _j++) {
							int now;
							if(_i == _j) {
								if(k == _i || t == _i) now = j;
								else now = j + 1;
							} else {
								if(k == t) {
									now = j + 1;
								} else {
									if(k != _i) now += 2;
									else now = j;
								}
							}
							ll &ans = f[i + 1][now][_i][_j];
							if(ans == -1) ans = 0;
							ans = (ans + f[i][j][k][t]);
							if(ans >= P) ans -= P; 
						}
					}
				}
			}
		}
	}
	cout << (max(f[n][k][0][0], 0ll) + max(f[n][k][0][1], 0ll) + max(f[n][k][1][0], 0ll) + max(f[n][k][1][1], 0ll)) % P << endl;
	return 0;
}