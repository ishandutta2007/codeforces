#include<bits/stdc++.h>

#define Would
#define you
#define please

using namespace std;

typedef long long ll;

const int maxn = 500 + 10;

int n, m;
string s[maxn];
int a[maxn][maxn];

int reVert(int x, int y) {
	if (x < 0 || y < 0)
		return 0;
	if (a[x][y] == 1)
		return -1;
	else
		return 1;
}

void solveOne() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	int justTopLeft = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int xorFour = 0;
			for (int ix = 0; ix < 2; ix++)
				for (int jy = 0; jy < 2; jy++)
					if (i + ix < n and j + jy < m)
						xorFour ^= (s[i + ix][j + jy] == 'B');
			a[i][j] = xorFour;
			justTopLeft += xorFour;
		}
	}
	int answer = justTopLeft;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp = justTopLeft;
			tmp += reVert(i - 1, j - 1);
			tmp += reVert(i - 1, m - 1);
			tmp += reVert(n - 1, j - 1);
			tmp += reVert(n - 1, m - 1);
			answer = min(answer, tmp + 3);
		}
	}
	cout << answer << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	int t = 1;
	while (t --) {
		solveOne();
	}
	Would you please return 0;
}