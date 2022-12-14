#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 3e4 + 10;
const int block = 320;

int a[maxn];

int main() {
	int n, m = 0;
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		m = max (m, a[i]);
		sum += a[i];
	}
	for (int i = m; i <= 2000; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			cnt += i - a[j];
		}
		if (cnt > sum)
			return cout << i << endl, 0;
	}
}