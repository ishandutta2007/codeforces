#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <string.h>
#include <assert.h>
#include <complex>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
mt19937 rr(random_device{}());



int main() {
	// freopen("input.txt", "r", stdin);
	
	int n, k;
	cin >> n >> k;

	if (n == 2 || n == 3 || k >= 4 || k == 1) {
		cout << -1 << endl;
		return 0;
	}

	if (n == 4 && k == 2) {
		cout << -1 << endl;
		return 0;
	}
	cout << n - 1 << endl;

	if (k == 3) {
		for (int i = 2; i <= n - 1; ++i)
			cout << 1 << " " << i << endl;
		cout << n - 1 << " " << n << endl;
		return 0;
	}

	for (int i = 1; i <= n - 1; ++i)
			cout << i << " " << i + 1 << endl;


	return 0;
}