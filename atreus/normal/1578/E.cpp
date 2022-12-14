#include<bits/stdc++.h>

#define Would
#define you
#define please

using namespace std;

typedef long long ll;

const int maxn = 1000 + 10;

int a[maxn];

void solveOne() {
	int n, h;
	cin >> n >> h;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int m = a[n - 1], k = a[n - 2];
	int answer = 2 * (h / (m + k));
	h %= (m + k);
	if (h > 0)
		answer++, h -= m;
	if (h > 0)
		answer++, h -= k;
	cout << answer << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --) {
		solveOne();
	}
	Would you please return 0;
}