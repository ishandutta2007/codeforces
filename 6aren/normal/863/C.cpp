#include<bits/stdc++.h>
using namespace std;

#define int long long

int  a, b, A[4][4], B[4][4];
int aw[100], bw[100];
int check[4][4];
long long k;

int w(int aa, int bb) {
	if (aa == bb) return 0;
	if (aa - bb == 1 || aa - bb == -2) return 1;
	return -1;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("a.txt", "r", stdin);
	cin >> k >> a >> b;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> B[i][j];
		}
	}
	check[a][b] = 1;
	int cura = a, curb = b;
	int cnt = 1;
	int chuky;
	if (w(cura, curb) == 1) {
		aw[cnt] = aw[cnt - 1] + 1;
		bw[cnt] = bw[cnt - 1];
	} else if (w(cura, curb) == -1) {
		bw[cnt] = bw[cnt - 1] + 1;
		aw[cnt] = aw[cnt - 1];
	} else {
		aw[cnt] = aw[cnt - 1];
		bw[cnt] = bw[cnt - 1];
	}
	//cout << w(1, 2) << endl;
	while (1) {
		int tmpa = A[cura][curb];
		int tmpb = B[cura][curb];
		cura = tmpa;
		curb = tmpb;
		//cout << "check: " << cura << ' ' << curb << endl;
		cnt++;
		if (w(cura, curb) == 1) {
			aw[cnt] = aw[cnt - 1] + 1;
			bw[cnt] = bw[cnt - 1];
		} else if (w(cura, curb) == -1) {
			bw[cnt] = bw[cnt - 1] + 1;
			aw[cnt] = aw[cnt - 1];
		} else {
			aw[cnt] = aw[cnt - 1];
			bw[cnt] = bw[cnt - 1];
		}
		if (check[cura][curb]) {
			//cout << cura << ' ' << curb << endl;
			chuky = cnt - check[cura][curb];
			break;
		}
		check[cura][curb] = cnt;
	}
	//cout << check[2][1] << endl;
	int t = check[cura][curb];
	if (k < t) {
		cout << aw[k] << ' ' << bw[k] << endl;
		return 0;
	}
	int achuky = aw[cnt] - aw[t];
	int bchuky = bw[cnt] - bw[t];
	//cout << t << ' ' << chuky << endl;
	long long resa = aw[t - 1];
	long long resb = bw[t - 1];
	resa += (k - t + 1) / chuky * achuky;
	resb += (k - t + 1) / chuky * bchuky;
	k = k - t + 1;
	k %= chuky;
	resa += aw[t + k - 1] - aw[t - 1];
	resb += bw[t + k - 1] - bw[t - 1];
	cout << resa << ' ' << resb;
	return 0;
}