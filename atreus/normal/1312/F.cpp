#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn = 3e5 + 10;

int gn[6][6][6][50][3];
int fr[6][6][6], to[6][6][6];

int getgn(ll t, int x, int y, int z){
	if (t < to[x][y][z])
		return t;
	int len = to[x][y][z] - fr[x][y][z];
	t %= len;
	while (t < fr[x][y][z])
		t += len;
	return t;
}

int MEX(int a = 3, int b = 3, int c = 3){
	if (a != 0 and b != 0 and c != 0)
		return 0;
	if (a != 1 and b != 1 and c != 1)
		return 1;
	if (a != 2 and b != 2 and c != 2)
		return 2;
	return 3;
}

void solve(int x, int y, int z){
	gn[x][y][z][0][0] = gn[x][y][z][0][1] = gn[x][y][z][0][2] = 0;
	for (int n = 1; ; n++){
		gn[x][y][z][n][0] = MEX(gn[x][y][z][max(n-x,0)][0], gn[x][y][z][max(n-y,0)][1], gn[x][y][z][max(n-z,0)][2]);
		gn[x][y][z][n][1] = MEX(gn[x][y][z][max(n-x,0)][0], gn[x][y][z][max(n-z,0)][2]);
		gn[x][y][z][n][2] = MEX(gn[x][y][z][max(n-x,0)][0], gn[x][y][z][max(n-y,0)][1]);
		if (n < max({x,y,z}))
			continue;
		for (int m = max({x,y,z})-1; m < n; m++){
			bool flag = 1;
			for (int q = 0; q < max({x,y,z}); q++)
				for (int t = 0; t < 3; t++)
					if (gn[x][y][z][m-q][t] != gn[x][y][z][n-q][t])
						flag = 0;
			if (flag == 1){
				fr[x][y][z] = m;
				to[x][y][z] = n;
				return;
			}
		}
	}
}

ll a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	for (int x = 1; x <= 5; x++)
		for (int y = 1; y <= 5; y++)
			for (int z = 1; z <= 5; z++)
				solve(x, y, z);
	int t;
	cin >> t;
	while (t --){
		int n, x, y, z;
		cin >> n >> x >> y >> z;
		int grundy = 0;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			ll p = getgn(a[i], x, y, z);
			grundy ^= gn[x][y][z][p][0];
		}
		if (grundy == 0){
			cout << 0 << '\n';
			continue;
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++){
			int p = getgn(a[i], x, y, z);
			ll t = max(0ll, a[i] - x);
			t = getgn(t, x, y, z);
			if ((grundy ^ gn[x][y][z][p][0] ^ gn[x][y][z][t][0]) == 0)
				cnt ++;
			t = max(0ll, a[i] - y);
			t = getgn(t, x, y, z);
			if ((grundy ^ gn[x][y][z][p][0] ^ gn[x][y][z][t][1]) == 0)
				cnt ++;
			t = max(0ll, a[i] - z);
			t = getgn(t, x, y, z);
			if ((grundy ^ gn[x][y][z][p][0] ^ gn[x][y][z][t][2]) == 0)
				cnt ++;
		}
		cout << cnt << '\n';
	}
}