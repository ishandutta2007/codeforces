#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
int gcd(int a, int b)
{
	int c;
	while (a != 0) {
		c = a; a = b%a;  b = c;
	}
	return b;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	int g = K;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		g = gcd(A[i], g);
	}
	cout << (K / g) << endl;
	for (int i = 0; i < K / g; i++) {
		if (i > 0)cout << " ";
		cout << i * g;
	}
	cout << endl;
}