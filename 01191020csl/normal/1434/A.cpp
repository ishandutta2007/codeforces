#include<bits/stdc++.h>
using namespace std;
int a[7], b[100001];
int p[100001];
struct node {
	int p, c;
}nd[600001];
bool operator<(const node &x, const node &y) {
	return b[x.p]-a[x.c] < b[y.p]-a[y.c];
}
int main() {
	for (int i = 1; i <= 6; i++) cin >> a[i];
	sort(a + 1, a + 7);
	int n;
	cin >> n;
	int l0 = 0x3f3f3f3f, r0 = 0, tot = 0;
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		for (int j = 1; j <= 6; j++) 
			++tot, nd[tot].p = i, nd[tot].c = j;
	}
	sort(nd + 1, nd + tot + 1);
	int minn = 0x3f3f3f3f, ans = 0;
	for (int i = 1; i <= n; i++) p[i] = 1, minn = min(minn, b[i] - a[1]), ans = max(ans, b[i]-a[1]);
	ans -= minn;
	for (int i = tot; i >= 1; i--) {
		++p[nd[i].p];
		if (p[nd[i].p] > 6) {
			cout << ans << endl;
			return 0;
		}
		minn = min(minn, b[nd[i].p]-a[nd[i].c+1]);
		ans = min(ans, b[nd[i-1].p]-a[nd[i-1].c]-minn);
	}
}