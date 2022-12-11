#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> lst[100005];
const long long MOD = 1e9+7;

long long lcm(long long a, long long b) {
	return (a * b / __gcd(a, b)) % MOD;
}

long long add(long long a, long long b) {
	return (a + b) % MOD;
}

long long sub(long long a, long long b) {
	return ((a - b) % MOD + MOD) % MOD;
}

long long mult(long long a, long long b) {
	return a * b % MOD;
}


int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			lst[j].push_back(i);
		}
		reverse(lst[i].begin(), lst[i].end());
	}
	long long ans = 0;
	for (int c = 1; c <= N-2; c++) {
		unordered_map<int, long long> mp;
		int d = N - c;
		for(int g : lst[d]) {
			long long tot = d / g - 1;
			for(int k : lst[d/g]) {
				if(k != 1) {
					tot -= mp[g*k];
				}
			}
			ans = add(ans, mult(tot, lcm(c, g)));
			mp[g] = tot;
		}
	}
	cout << ans << "\n";
}