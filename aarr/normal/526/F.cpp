#include <iostream>
#include <algorithm>
using namespace std;

const int N = 300 * 1000 + 5;
long long ans;

pair <int, int> a[N];
int b[N];
int lmn[N];
int rmn[N];
int lmx[N];
int rmx[N];
int cnt[3 * N];

void solve(int l, int r) {
//	cout << l << " " << r << " " << ans << endl;
	if (r - l == 1) {
		ans++;
		lmn[l] = lmx[l] = rmn[l] = rmx[l] = b[l];
		return;
	}
	int md = (l + r) / 2;
	solve(l, md);
	solve(md, r);
/*	lmn[l] = lmx[l] = b[l];
	lmn[md] = lmx[md] = b[md];
	rmn[r - 1] = rmx[r - 1] = b[r - 1];
	rmn[md - 1] = */
	for (int i = md; i < r; i++) {
		int maxi = lmx[i], mini = lmn[i];
		int x = i + mini - maxi;
		if (x < md && x >= l && rmn[x] > mini && rmx[x] < maxi) {
		//	cout << "73 " << l << " " << r << " " << i << " " << mini << " " << maxi << " " << x << endl;
			ans++;
		}
	}
	for (int i = l; i < md; i++) {
		int maxi = rmx[i], mini = rmn[i];
		int x = i - mini + maxi;
		if (x >= md && x < r && lmn[x] > mini && lmx[x] < maxi) {
		//	cout << "74 " << l << " " << r << " " << i << " " << mini << " " << maxi << " " << x << endl;
			ans++;
		}
	}
	int L = md - 1, R = md - 1;
	for (int i = md; i < r; i++) {
		int maxi = lmx[i], mini = lmn[i];
		while (L >= l && rmx[L] <= maxi) {
			cnt[rmn[L] - L + N]++;
			L--;
		}
		while (R >= l && rmn[R] >= mini) {
			cnt[rmn[R] - R + N]--;
			R--;
		}
		//cout << "37 " << l << " " << r << " " << L << " " << R << endl;
		ans += max(cnt[maxi - i + N], 0);
	}
	for (int i = l; i < r; i++) {
		cnt[rmn[i] - i + N] = 0;
	//	cout << "48 " << i << " " << lmx[i] << endl;
	}
	L = md - 1, R = md - 1;
	for (int i = md; i < r; i++) {
		int maxi = lmx[i], mini = lmn[i];
		while (R >= l && rmn[R] >= mini) {
			cnt[rmx[R] + R + N]++;
			R--;
		}
		while (L >= l && rmx[L] <= maxi) {
			cnt[rmx[L] + L + N]--;
			L--;
		}
	//	cout << "38 " << l << " " << r << " " << L << " " << R << endl;
		ans += max(cnt[mini + i + N], 0);
	}
	for (int i = l; i < r; i++) {
		cnt[rmx[i] + i + N] = 0;
	//	cout << "49 " << i << " " << lmx[i] << endl;
	}	
	for (int i = md; i < r; i++) {
		lmn[i] = min(b[i], lmn[i - 1]);
		lmx[i] = max(b[i], lmx[i - 1]);
	}
	for (int i = md - 1; i >= l; i--) {
		rmn[i] = min(b[i], rmn[i + 1]);
		rmx[i] = max(b[i], rmx[i + 1]);
	}
}

int main() {
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		b[i] = a[i].second;
	}
	solve(0, n);
	cout << ans << endl;
	return 0;
}