#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define endl '\n'
#define sp ' '
#define fi first
#define se second

int n, a[100005];
map<int, int> cnt;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	long long res = 0;
	int dem = 0;
	for (int i = 2; i <= n; i++) {
		if (a[i] == a[i - 1]) dem++;
		if (a[i] == a[i + 1] && a[i] == a[i - 1] + 1) return cout << "cslnb", 0;
	}
	if (dem >= 2) return cout << "cslnb", 0;

	for (int i = 1; i <= n; i++) {
		if (a[i] < i - 1) {
			return cout << "cslnb", 0;
		}
		res += a[i] - i + 1;
	}
	if (res % 2 == 1) cout << "sjfnb";
	else cout << "cslnb";

	return 0;
}