#include <iostream>
#include <vector>
using namespace std;

const int N = 300 * 1000 + 7;
int n;

int a[N];
int b[N];
vector <pair <int, int> > v;
void chng(int i, int j) {
	if (i == j)
		return ;
	if (abs (i - j) >= n / 2) {
		b[a[i]] = j;
		b[a[j]] = i;
		swap(a[i], a[j]);
		v.push_back({i, j});
		//cout << i << " " << j << endl;
	}
	else {
		int k;
		if (i <= n / 2 && j <= n / 2) {
			k = n;
			b[a[i]] = j;
			b[a[j]] = i;
			swap(a[i], a[j]);
			v.push_back({i, k});
			v.push_back({j, k});
			v.push_back({i, k});
			//cout << i << " " << k << endl;
			//cout << k << " " << j << endl;
			//cout << i << " " << k << endl;
			return ;
		}
		if (i > n / 2 && j > n / 2) {
			k = 1;
			b[a[i]] = j;
			b[a[j]] = i;
			swap(a[i], a[j]);
			v.push_back({i, k});
			v.push_back({j, k});
			v.push_back({i, k});
			//cout << i << " " << k << endl;
			//cout << k << " " << j << endl;
			//cout << i << " " << k << endl;
			return ;
		}
		if (i > j)
			swap(i, j);
		//b[a[i]] = j;
		//b[a[j]] = i;
		//swap(a[i], a[j]);
		chng(i, n);
		chng(j, 1);
		chng(1, n);
		chng(i, n);
		chng(j, 1);
		
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios :: sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		//cout << 73 << " " << i << " " << b[i] << endl;
		chng(i, b[i]);
	}
	chng(1, b[1]);
	if (v.size() > 5 * n) {
		int x = 0;
		int y = v.size() / x;
	}
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << endl;
	}
	return 0;
}