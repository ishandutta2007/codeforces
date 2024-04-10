#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

const int MAXINT = 1073741823;

const long long int MOD = 998244353;

long long int degree[MAXN];

long long int factorial[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long int n, u, v, answer = 1;
	cin >> n;
	factorial[0] = 1;
	for (int i = 1; i <= n; i++)
		factorial[i] = (factorial[i - 1] * i) % MOD;
	for (int i = 1; i <= n - 1; i++) {
		cin >> u >> v;
		degree[u]++;
		degree[v]++;
	}
	for (int i = 1; i <= n; i++)
		answer = (answer * factorial[degree[i]]) % MOD;
	answer = (answer * n) % MOD;
	cout << answer;
	return 0;
}