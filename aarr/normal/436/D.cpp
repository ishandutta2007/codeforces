#include <iostream>
#include <algorithm>
using namespace std;



const int N = 200 * 1000 + 5, M = 2005;



int a[N], b[M], l[N], r[N];
bool mark[N];
int dp1[N], dp2[N];


int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
		mark[b[i]] = true;
	}
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	l[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] == a[i - 1] + 1) {
			l[i] = l[i - 1];
		}
		else {
			l[i] = i;
		}
	}
	for (int i = n; i; i--) {
		if (a[i] + 1 == a[i + 1]) {
			r[i] = r[i + 1];
		}
		else {
			r[i] = i;
		}
	}
	if (n == 1) {
		cout << 0;
		return 0;
	}
	if (mark[a[1]]) {
		dp2[1] = dp1[1] = 1;
	}
	int k = 0;
	for (int j = 1; j <= m; j++) {
		if (b[j] > a[1]) {
			k++;
			int x = 1 + (b[j] - a[1]);
			int y = r[x];
			if (x <= n) {
				dp2[y] = max(dp2[y], dp1[1] + k);
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		int k = 0;
		for (int j = m; j; j--) {
			if (b[j] < a[i]) {
				k++;
				int x = i - (a[i] - b[j]);
				if (x > 0) {
					int y = l[x];
					dp1[i] = max(dp1[i], dp2[y - 1] + k);
				}
			}
			else if (b[j] == a[i]) {
				k++;
			}
		}
	//	if (mark[a[i]]) {
	//		dp2[a[i]]++;
	//	}
		dp1[i] = max(dp1[i], dp2[i - 1]);
		if (mark[a[i]]) {
			dp1[i] = max(dp1[i], dp2[i - 1] + 1);
		}
		dp2[i] = max(dp2[i], dp1[i]);
		dp2[i] = max(dp2[i], dp2[i - 1]);
		k = 0;
		for (int j = 1; j <= m; j++) {
		//	if (b[j] == a[i]) {
		//		k++;
		//	}
			if (b[j] > a[i]) {
				k++;
				int x = i + (b[j] - a[i]);
				int y = r[x];
				if (x <= n) {
					dp2[y] = max(dp2[y], dp1[i] + k);
				//	if (mark[a[y]]) {
				//		dp2[y] = max(dp2[y], dp1[i] + k + 1);
				//	}
				}
			}
		}
	//	cout << "73 " << i << " " << a[i] << " " << dp1[i] << " " << dp2[i] << endl;
	}
	cout << dp2[n];
	return 0;
}