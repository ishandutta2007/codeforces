#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997 };
vector<int> primefactorise(int n) {
	vector<int> p;
	for (auto a : primes) {
		int am = 0;
		if (n == 1) break;
		while (n%a == 0) {
			n /= a;
			am++;
		}
		if (am % 2) p.push_back(a);
	}
	if (n > 1) p.push_back(n);
	return p;
}
int n, q;
map<vector<int>, int> c;
int main() {
	int t;
	scanf("%d", &t);
	for (int CASE = 0; CASE < t; CASE++) {
		scanf("%d", &n);
		c.clear();
		int ans1 = 0;
		int ans2 = 0;
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			auto factors = primefactorise(a);
			c[factors]++;
			ans1 = max(ans1, c[factors]);
		}
		for (auto it = c.begin(); it != c.end(); ++it) {
			if (it->second % 2 == 0 || it->first.empty()) {
				ans2 += it->second;
			}
		}
		scanf("%d", &q);
		for (int i = 0; i < q; i++) {
			ll a;
			scanf("%lld", &a);
			if (a) printf("%d\n", max(ans1, ans2));
			else printf("%d\n", ans1);
		}
	}
}