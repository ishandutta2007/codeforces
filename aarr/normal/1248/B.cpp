#include <iostream>
#include <algorithm>
using namespace std;


const int N = 100 * 1000 + 5;


int a[N];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	long long s1 = 0, s2 = 0;
	for (int i = 1; i <= n / 2; i++) {
		s1 += a[i];
	} 
	for (int i = n / 2 + 1; i <= n; i++) {
		s2 += a[i];
	}
	cout << s1 * s1 + s2 * s2;
	return 0;
}