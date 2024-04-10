#include<bits/stdc++.h>
using namespace std;

#define int long long

const int REP = 10;

int n, a[1000005];
vector<int> divisor;
unordered_map<int, int> cnt;

long long Rand(long long l, long long h) {
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}	
	int res = 1;
	clock_t startTime = clock();
	while (clock() - startTime < 3.0 * CLOCKS_PER_SEC) {
		int id = Rand(1, n);
		cnt.clear();
		divisor.clear();
		for (int i = 1; i <= n; i++) {
			cnt[__gcd(a[id], a[i])]++;
		}
		for (int i = 1; i * i <= a[id]; i++) {
			if (a[id] % i == 0) {
				divisor.push_back(i);
				divisor.push_back(a[id] / i);
			}
		}
		sort(divisor.begin(), divisor.end());
		reverse(divisor.begin(), divisor.end());
		for (int i = 0; i < divisor.size(); i++) {
			int count = 0;
			for (int j = 0; j <= i; j++) {
				if (divisor[j] % divisor[i] == 0) {
					count += cnt[divisor[j]];
				}
			}
			if (count * 2 >= n) {
				res = max(res, divisor[i]);
				break;
			}
		}
	}
	cout << res;
	return 0;
}