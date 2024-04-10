#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k, kol;
	cin >> n >> k;
	kol = n / k;
	vector< pair<int, int> > a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	int q, x;
	cin >> q;
	double mmin = 1e9, mmax = 0, sr;
	vector< vector<int> > b(q);
	vector<bool> used(n, false);
	bool fl;
	int kol_r = 0;
	for (int i = 0; i < q; i++) {
		sr = 0;
		fl = false;
		for (int g = 0; g < kol; g++) {
			scanf("%d", &x);
			--x;
			if (!used[x]) {
				fl = true;
			}
			used[x] = true;
			sr += a[x].first;
		}
		if (fl) {
			kol_r++;
		}
		sr /= kol;
		mmin = min(mmin, sr);
		mmax = max(mmax, sr);
	}
	if (kol_r < k) {
		sort(a.begin(), a.end());
		int nabr = 0;
		sr = 0;
		for (int i = 0; i < n; i++) {
			if (!used[a[i].second]) {
				sr += a[i].first;
				nabr++;
				if (nabr == kol) {
					sr /= kol;
					mmin = min(mmin, sr);
					mmax = max(mmax, sr);
					break;
				}
			}
		}
		nabr = 0;
		sr = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (!used[a[i].second]) {
				sr += a[i].first;
				nabr++;
				if (nabr == kol) {
					sr /= kol;
					mmin = min(mmin, sr);
					mmax = max(mmax, sr);
					break;
				}
			}
		}
	}
	printf("%.7f %.7f", mmin, mmax);




	return 0;
}//beybvh