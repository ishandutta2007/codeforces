#include<bits/stdc++.h>
using namespace std;
int ans;
int x[500001], y[500001];
void solve(int l, int len) {
	if (!len) return;
	solve(l, len-1), solve(l+(1<<len-1), len-1);
	for (int i = l; i < l+(1<<len-1); i++) {
		++ans;
		x[ans] = i, y[ans] = i+(1<<len-1);
	}
}
int main() {
	int n;
	cin >> n;
	int p = 0;
	while ((1<<p+1) < n) ++p;
	solve(1, p), solve(n-(1<<p)+1, p);
	cout << ans << endl;
	for (int i = 1; i <= ans; i++) cout << x[i] << ' ' << y[i] << endl;
}