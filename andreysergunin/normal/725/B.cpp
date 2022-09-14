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

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

int main() {
	// freopen("input.txt", "r", stdin);
	
	string s;
	cin >> s;
	unsigned long long n = 0;
	for (int i = 0; i < sz(s) - 1; ++i) {
		n *= 10;
		n += s[i] - '0';
	}
	--n;
	int c = s.back() - 'a';
	vector<int> v = {4, 5, 6, 3, 2, 1};

	unsigned long long ans = (n / 4) * 12 + (n % 2) * 6 + v[c] + n;
	if (n % 4 == 3 || n % 4 == 2)
		ans -= 2;
	cout << ans << endl;

	return 0;
}