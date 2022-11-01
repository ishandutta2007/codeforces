#include <functional>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)		(a).begin(), (a).end()

typedef long long int64;

int n, timetodie;
char A[13][13], B[13][13];

int a[256][256], S, T, V;
bool b[256];

bool dfs(int x) {
	b[x] = true;
	for (int y = 0; y < S; ++y)
		if (a[x][y] && (!b[y] && dfs(y) || y == T)) {
			--a[x][y];
			++a[y][x];
			return true;
		}
	return false;
}

int c[13][13];

int dx[] = {1, 0, -1, 0, 0};
int dy[] = {0, 1, 0, -1, 0};

void go() {
	bool f[13][13];
	memset(f, 0, sizeof f);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (c[i][j] == 1) 
				for (int k = 0; k < 5; ++k) {
					int x = i + dx[k];
					int y = j + dy[k];
					if (x >= 0 && x < n && y >= 0 && y < n && isdigit(A[x][y]))
						f[x][y] = true;
				}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (c[i][j] != -1 && f[i][j])
				c[i][j] = 1;
}

void kill() {
	bool f[13][13];
	memset(f, 0, sizeof f);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (c[i][j] == -1) 
				for (int k = 0; k < 5; ++k) {
					int x = i + dx[k];
					int y = j + dy[k];
					if (x >= 0 && x < n && y >= 0 && y < n && isdigit(A[x][y]))
						f[x][y] = true;
				}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (f[i][j])
				c[i][j] = -1;
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n >> timetodie;
	for (int i = 0; i < n; ++i) cin >> A[i];
	for (int i = 0; i < n; ++i) cin >> B[i];
	V = n * n;
	T = V + V;
	S = T + 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			int v = i * n + j;
			if (isdigit(A[i][j])) {
				a[S][v] = A[i][j] - '0';
				memset(c, 0, sizeof c);
				c[i][j] = 1;
				for (int x = 0; x < n; ++x)
					for (int y = 0; y < n; ++y)
						if (A[x][y] == 'Z')
							c[x][y] = -1;
				for (int k = 0; k < timetodie; ++k) {
					go();
					for (int x = 0; x < n; ++x)
						for (int y = 0; y < n; ++y)
							if (isdigit(B[x][y]) && c[x][y] == 1)
								a[v][V + x * n + y] = -1u/4;	
					kill();
				}
			}
			if (isdigit(B[i][j]))
				a[V + v][T] = B[i][j] - '0';
			
		}
	int res = 0;
	for (; memset(b, 0, sizeof b), dfs(S); ++res);
	cout << res << endl;
	return 0;
}