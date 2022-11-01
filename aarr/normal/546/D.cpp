#include <iostream>
using namespace std;

const int N = 5000 * 1000 + 5;

long long p[N];
long long s[N];
int main() {
	for (int i = 2; i < N; i++) {
		if (p[i] == 0) {
			for (int j = i; j < N; j += i) {
				int x = j;
				while (x % i == 0) {
					x /= i;
					p[j]++;
				}
			}
		}
	}
	for (int i = 2; i < N; i++) {
		s[i] = s[i - 1] + p[i];
	}
	int t;
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		cout << s[a] - s[b] << '\n';
	}
	return 0;
}