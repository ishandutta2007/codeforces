#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector<string> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		sort(all(a[i]));
		a[i].erase(unique(all(a[i])), a[i].end());
	}
	sort(all(a));
	a.erase(unique(all(a)), a.end());
	cout << sz(a);
}