#include<bits/stdc++.h>
using namespace std;
int a[1001];
int x[1000001], y[1000001], cnt;
vector<pair<int, int> > tmp;
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = n; i >= 1; i--) {
		tmp.clear();
		for (int j = 1; j < i; j++)
			if (a[j] > a[i]) tmp.push_back(make_pair(a[j], j));
		sort(tmp.begin(), tmp.end());
		for (int j = 0; j < tmp.size(); j++) {
			++cnt;
			x[cnt] = tmp[j].second, y[cnt] = i;
		}
	}
	cout << cnt << endl;
	for (int i = 1; i <= cnt; i++) cout << x[i] << ' ' << y[i] << endl;
}