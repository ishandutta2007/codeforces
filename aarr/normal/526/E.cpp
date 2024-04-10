#include <iostream>
#include <algorithm>
using namespace std;


const int N = 1000 * 1000 + 5;
int n, q;

int a[N];
int nxt[N];
int prv[N];
long long ps[N];
int cal(int x) {
	int s = 0, ans = 0;
	while (true) {
		ans++;
		int d = (nxt[x] - x + n) % n;
		if (s + d >= n) {
			break;
		}
		s += d;
		x = nxt[x];
	}	
	return ans;
}
int main() {
	ios :: sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ps[i] = ps[i - 1] + a[i];
	}
	for (int ii = 0; ii < q; ii++) {
		long long k;
		cin >> k;
		int maxfor = 1;
		long long maxi = 0;
		if (k >= ps[n]) {
			cout << 1 << endl;
			continue;
		}
		for (int i = 1; i <= n; i++) {
			if (ps[n] > ps[i - 1] + k) {
				int x = upper_bound(ps + i, ps + n + 1, ps[i - 1] + k) - ps;
				nxt[i] = x;
			}
			else {
				int x = upper_bound(ps + 1, ps + i + 1, ps[i - 1] + k - ps[n]) - ps;
				nxt[i] = x;
			}
		//	cout << k << " " << i << " " << nxt[i] << endl; 
		}
		int s = 0, ans = 0;
		int x = 1, mini = n, minfor = 1;
		while (true) {
			ans++;
			int d = (nxt[x] - x + n) % n;
			if (s + d >= n) {
				break;
			}
			if (d < mini) {
				mini = d;
				minfor = x;
			}
			s += d;
			x = nxt[x];
		}
		for (int i = minfor; i <= nxt[minfor]; i++) {
			ans = min(ans, cal(i));
		}
		cout << ans << endl;
	}
	return 0;
}