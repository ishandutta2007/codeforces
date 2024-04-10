#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 51, V = 26 * 50000;

int n;
int a[N];
bitset<V> f[51][26];
vector<int> b1, b2;

int main() {
	scanf("%d", &n);
	int sum = 0;
	for (int i = 1; i <= (n << 1); i++) {
		scanf("%d", a + i);
		sum += a[i];
	}
	sort(a + 1, a + (n << 1) + 1);
	f[0][0].set(0);
	b1.push_back(a[1]);
	sum -= a[1], sum -= a[2];
	b2.push_back(a[2]);
	for (int i = 1; i <= n * 2 - 2; i++)
		a[i] = a[i + 2];
	for (int i = 1; i <= (n << 1) - 2; i++) {
		b2.push_back(a[i]);
		for (int j = min(n - 1, i); j; j--) {
			f[i][j] = f[i - 1][j] | (f[i - 1][j - 1] << a[i]);
		}
		f[i][0].set(0);
	}
	sum >>= 1;
	int pos = n * 2 - 2, cnt = n - 1;
	while (!f[pos][cnt].test(sum))
		sum--;
	while (cnt) {
		if (a[pos] > sum || !f[pos - 1][cnt - 1].test(sum - a[pos])) {
			pos--;
		} else {
			cnt--;
			b2.erase(find(b2.begin(), b2.end(), a[pos]));
			b1.push_back(a[pos]);
			sum -= a[pos--];
		}
	}
	sort(b1.begin(), b1.end());
	sort(b2.begin(), b2.end(), greater<int>());
	for (auto x : b1)
		printf("%d ", x);
	putchar('\n');
	for (auto x : b2)
		printf("%d ", x);
	putchar('\n');
	return 0;
}