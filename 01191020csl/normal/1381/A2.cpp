#include<bits/stdc++.h>
using namespace std;
char a[100001], b[100001];
int seq[300001], tot;
void solve(int l, int r, int len, int op) {
	if (!len) return;
	if (op) {
		if (a[l] != b[len]) seq[++tot] = 1;
		seq[++tot] = len, solve(r, l - 1, len - 1, 0);
	}
	else {
		if (a[l] == b[len]) seq[++tot] = 1;
		seq[++tot] = len, solve(r, l + 1, len - 1, 1);
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n >> a + 1 >> b + 1;
		tot = 0, solve(1, n, n, 0);
		cout << tot;
		for (int i = 1; i <= tot; i++) cout << ' ' << seq[i];
		cout << endl;
	}
}