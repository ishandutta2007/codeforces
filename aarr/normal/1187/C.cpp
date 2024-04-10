#include <iostream>
#include <vector>
using namespace std;

const int N = 1005;

vector <pair <int, int> > v;
bool b[N];
int a[N];
int main() {
	int n, m;
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int t, l, r;
		cin >> t;
		cin >> l;
		cin >> r;
		if (t == 0) {
			v.push_back({l, r});
		}
		else {
			for (int j = l; j < r; j++) {
				b[j] = true;
			}
		}
	}
	a[1] = N;
	for (int j = 2; j <= n; j++) {
		if (b[j - 1])
			a[j] = a[j - 1];
		else
			a[j] = a[j - 1] - 1;
	}
	for (int i = 0 ; i < v.size(); i++) {
		int l = v[i].first, r = v[i].second;
		bool d = false;
		for (int j = l; j < r; j++) {
			if (a[j] > a[j + 1])
				d = true;
		}
		if (!d) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES" << endl;
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}