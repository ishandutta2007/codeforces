#include<bits/stdc++.h>

using namespace std;

int n, cnt[1005], a[25][25];

void print() {
	for (int i = 1; i <= 1000; i++) {
		if (cnt[i] > 0) {
			cout << "NO";
			return;
		} 
	}
	cout << "YES" << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n * n; i++) {
		int u;
		cin >> u;
		cnt[u]++;
	}
	int tmp = n / 2;
	for (int i = 1; i <= tmp; i++) {
		for (int j = 1; j <= tmp; j++) {
			for (int k = 1; k <= 1000; k++) {
				if (cnt[k] < 4) continue;
				a[i][j] = k;
				a[n + 1 - i][j] = k;
				a[i][n + 1 - j] = k;
				a[n + 1 - i][n + 1 - j] = k;
				cnt[k] -= 4;
				break;
			}
		}
	}
	if (n % 2 == 0) {
		print();
		return 0; 
	}
	for (int i = 1; i <= tmp; i++) {
		for (int j = 1; j <= 1000; j++) {
			if (cnt[j] >= 2) {
				a[tmp + 1][i] = j;
				a[tmp + 1][n + 1- i] = j;
				cnt[j] -= 2;
				break;
			}
		}
	}
	for (int i = 1; i <= tmp; i++) {
		for (int j = 1; j <= 1000; j++) {
			if (cnt[j] >= 2) {
				a[i][tmp + 1] = j;
				a[n + 1 - i][tmp + 1] = j;
				cnt[j] -= 2;
				break;
			}
		}
	}
	for (int i = 1; i <= 1000; i++) {
		if (cnt[i] > 0) {
			a[tmp + 1][tmp + 1] = i;
			cnt[i]--;
			break;
		}
	}
	print();
	return 0;
}