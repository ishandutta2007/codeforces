#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;

const int MAXINT = 1073741823;

bitset<MAXN> is_prime;

int primes_before[MAXN];

int answer_of[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int answer = 0, t, x;
	answer_of[0] = 0;
	is_prime.set();
	for (int i = 2; i < MAXN; i++) {
		if (is_prime[i]) {
			for (int j = 2 * i; j < MAXN; j += i)
				is_prime[j] = false;
			answer++;
		}
		primes_before[i] = answer;
	}
	for (int i = 1; i < MAXN; i++)
		answer_of[i] = primes_before[i] - primes_before[(int)sqrt(i)] + 1;
	cin >> t;
	for (int q = 0; q < t; q++) {
		cin >> x;
		cout << answer_of[x] << '\n';
	}
	return 0;
}