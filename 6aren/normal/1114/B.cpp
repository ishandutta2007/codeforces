#include <bits/stdc++.h>

using namespace std;

const int N = 200000 + 5;

int n, m, k;

bool check[N];

pair<int, int> a[N];

long long res;

bool cmp (pair<int, int> x, pair<int, int> y) {
	return x.second < y.second;
}

int main() {
	//freopen("in", "r", stdin);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first;
		a[i].second = i;
		check[i] = false;
	} 
	sort(a + 1, a + n + 1);
	for (int i = n; i > n - m * k; i--) {
		check[a[i].second] = true;
		res += a[i].first;
	}
	sort(a + 1, a + n + 1, cmp);
	cout << res << endl;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (check[i]) {
			cnt++;
			if (cnt % m == 0 && cnt != m * k) {
				cout << i << " ";
			}
		}
	}
	return 0;
}
/* 
g++ online.cpp -o online.exe
*/