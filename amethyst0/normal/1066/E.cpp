#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

void write(int x) {
	//       <= x,        b( b   ),  x  b.
	//    2    

	vector <int> v;

	if (x == 0) {
		cout << 0 << endl;
	}
	else {
		while (x != 0) {
			v.push_back(x % 2);
			x /= 2;
		}

		for (int i = (int)v.size() - 1; i >= 0; i--) {
			cout << v[i];
		}

		cout << endl;
	}
}

const int mod = 998244353;

string a, b;

const int maxn = 200010;

int st[maxn];
int suff_sum[maxn];

int main() {
	st[0] = 1;

	for (int i = 1; i < maxn; i++) {
		st[i] = st[i - 1] * 2;
		st[i] %= mod;
	}

	int n, m;

	cin >> n >> m;

	cin >> a >> b;

	long long ans = 0;

	//   .

	reverse(a.begin(), a.end()); //  !
	reverse(b.begin(), b.end());

	int cur_sum = 0;

	for (int i = m - 1; i >= 0; i--) {
		if (b[i] == '1') {
			cur_sum += 1;
		}

		suff_sum[i] = cur_sum;
	}

	for (int i = n - 1; i >= 0; i--) {
		if (a[i] == '1') {
			int cnt = suff_sum[i];

			//    cnt * (2 ^ i).
			// 2 ^ i (st[i]   10 ^ 9)  cnt = 10,  10 ^ 10    int!
			//cout << "!" << i << ' ' << cnt << endl;
			ans += (long long)st[i] * cnt;
			ans %= mod;
		}
	}

	//O(n + m);

	cout << ans << endl;

	//system("pause");
}

// ,     b(  ),    . O(min(n, m) * m) = O(n ^ 2);
//    a,   pos,   (   b)     1.

//1010
//0001

// pos = 2