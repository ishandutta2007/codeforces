#include <bits/stdc++.h>

constexpr int N = 79;
constexpr long long f[N + 1] = {
	1ll, 2ll, 3ll, 5ll, 8ll, 13ll, 21ll, 34ll, 55ll, 89ll, 144ll, 233ll, 377ll,
	610ll, 987ll, 1597ll, 2584ll, 4181ll, 6765ll, 10946ll, 17711ll, 28657ll,
	46368ll, 75025ll, 121393ll, 196418ll, 317811ll, 514229ll, 832040ll,
	1346269ll, 2178309ll, 3524578ll, 5702887ll, 9227465ll, 14930352ll,
	24157817ll, 39088169ll, 63245986ll, 102334155ll, 165580141ll, 267914296ll,
	433494437ll, 701408733ll, 1134903170ll, 1836311903ll, 2971215073ll,
	4807526976ll, 7778742049ll, 12586269025ll, 20365011074ll, 32951280099ll,
	53316291173ll, 86267571272ll, 139583862445ll, 225851433717ll,
	365435296162ll, 591286729879ll, 956722026041ll, 1548008755920ll,
	2504730781961ll, 4052739537881ll, 6557470319842ll, 10610209857723ll,
	17167680177565ll, 27777890035288ll, 44945570212853ll, 72723460248141ll,
	117669030460994ll, 190392490709135ll, 308061521170129ll, 498454011879264ll,
	806515533049393ll, 1304969544928657ll, 2111485077978050ll,
	3416454622906707ll, 5527939700884757ll, 8944394323791464ll,
	14472334024676221ll, 23416728348467685ll, 37889062373143906ll
};

std::pair<long long, long long> dis(int n, long long u, long long w) {
	if (n == 0) {
		return std::make_pair(0ll, 0ll);
	}
	if (n == 1) {
		if (u == 0) {
			return std::make_pair(0ll, 1ll);
		} else {
			return std::make_pair(1ll, 0ll);
		}
	}
	w = std::min<long long>(w, (n + 1) / 2);
	if (u < f[n - 1]) {
		auto tmp = dis(n - 1, u, 2);
		return std::make_pair(tmp.first, std::min(tmp.first + w, tmp.second + w));
	} else {
		auto tmp = dis(n - 2, u - f[n - 1], w + 1);
		return std::make_pair(std::min(tmp.first + 1, tmp.second + w), tmp.second);
	}
}

long long solve(int n, long long u, long long v, long long w) {
	if (n == 0 || u == v) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	w = std::min<long long>(w, (n + 1) / 2);
	if (u > v) {
		std::swap(u, v);
	}
	if (v < f[n - 1]) {
		return solve(n - 1, u, v, 2);
	}
	if (u >= f[n - 1]) {
		return solve(n - 2, u - f[n - 1], v - f[n - 1], w + 1);
	}
	auto du = dis(n - 1, u, 2);
	auto dv = dis(n - 2, v - f[n - 1], w + 1);
	return std::min({du.second + dv.first + 1, du.first + dv.first + 1, du.first + dv.second + w});
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int T, n;
	std::cin >> T >> n;
	n = std::min(n, N);

	while (T--) {
		long long u, v;
		std::cin >> u >> v;
		--u, --v;
		std::cout << solve(n, u, v, f[n]) << "\n";
	}
}