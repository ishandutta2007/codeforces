#include <bits/stdc++.h>

using namespace std;

#define int long long

struct man {
	int s, a, b;
};

int n, s;
long long tot;
man a[100000];
vector<man> fi, se;
int A, B;
long long ans;

int get(int A, int B) {
	if(A < 0 || B < 0) return 0;
	int ret = 0;
	int pc1 = A * s, pc2 = B * s;
	for(int i = 0; i < fi.size(); i++) {
		if(fi[i].s <= pc1) {
			ret += 1LL * fi[i].s * fi[i].a;
			pc1 -= fi[i].s;
		} else {
			ret += 1LL * pc1 * fi[i].a + 1LL * (fi[i].s - pc1) * fi[i].b;
			pc1 = 0;
		}
	}
	for(int i = 0; i < se.size(); i++) {
		if(se[i].s <= pc2) {
			ret += 1LL * se[i].s * se[i].b;
			pc2 -= se[i].s;
		} else {
			ret += 1LL * pc2 * se[i].b + 1LL * (se[i].s - pc2) * se[i].a;
			pc2 = 0;
		}
	}
	return ret;
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> s;
	for(int i = 0; i < n; i++) {
		cin >> a[i].s >> a[i].a >> a[i].b;
		if(a[i].a <= a[i].b) se.push_back(a[i]);
		else fi.push_back(a[i]);
		tot += a[i].s;
	}
	tot = (tot + s - 1) / s;
	sort(fi.begin(), fi.end(), [](man a, man b){ return a.a - a.b > b.a - b.b; });
	sort(se.begin(), se.end(), [](man a, man b){ return a.b - a.a > b.b - b.a; });
	for(int i = 0; i < fi.size(); i++) A += fi[i].s;
	A = (A + s - 1) / s;
	cout << max({get(A, tot - A), get(A - 1, tot - A + 1), get(A + 1, tot - A - 1)});
}