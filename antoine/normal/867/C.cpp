#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <string>
#include <array>
#include <queue>
#include <functional>

struct Cont {
	long long s, a, b, id;
	bool operator<(const Cont &o) const {
		auto diff = std::abs(a - b) - std::abs(o.a - o.b);
		if (diff != 0) return diff > 0;
		return id < o.id;
	}
};

long long N, S;

long long f(long long aSlices, long long bSlices, const std::set<Cont> &conts) {
	long long tempAns = 0;
	for(auto it = conts.begin(); it != conts.end(); ++it) {
		if (it->a > it->b) {
			long long dec = std::min(aSlices, it->s);
			aSlices -= dec;
			tempAns += it->a * dec;

			tempAns += (it->s - dec) * it->b;
			bSlices -= (it->s - dec);
		}
		else {
			long long dec = std::min(bSlices, it->s);
			bSlices -= dec;
			tempAns += it->b * dec;

			tempAns += (it->s - dec) * it->a;
			aSlices -= (it->s - dec);
		}
	}
	return tempAns;
}



int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N >> S;
	long long ans = 0;
	std::set<Cont> conts;
	long long aDemand = 0;
	long long bDemand = 0;

	for (int i = 0; i < N; ++i) {
		int s, a, b;
		std::cin >> s >> a >> b;
		conts.insert({ s, a, b, i });
		if (a > b)
			aDemand += s;
		else
			bDemand += s;
	}

	long long aSlices = 0;
	long long bSlices = 0;

	auto it = conts.begin();
	bool aDemandStopped = false;
	bool bDemandStopped = false;
	while (!aDemandStopped || !bDemandStopped) {
		if (it == conts.end()) break;
		if (it->a > it->b) {
			if (!aDemandStopped && aDemand - it->s >= S) {
				aDemand -= it->s;
				aSlices -= it->s;
				ans += it->s * it->a;
				it = conts.erase(it);
			}
			else {
				++it;
				aDemandStopped = true;
			}
		} else {
			if (!bDemandStopped && bDemand - it->s >= S) {
				bDemand -= it->s;
				bSlices -= it->s;
				ans += it->s * it->b;
				it = conts.erase(it);
			}
			else {
				++it;
				bDemandStopped = true;
			}

		}
	}
	aSlices %= S;
	bSlices %= S;
	if (aSlices < 0)
		aSlices += S;
	if (bSlices < 0)
		bSlices += S;

	long long pizzasToOrderLeft = (aDemand + bDemand - aSlices - bSlices + S - 1) / S;
	long long tempAns = 0;
	for (int i = 0; i <= pizzasToOrderLeft; ++i) {
		aSlices += S*i;
		bSlices += S*(pizzasToOrderLeft - i);
		tempAns = std::max(tempAns, f(aSlices, bSlices, conts));
		aSlices -= S*i;
		bSlices -= S*(pizzasToOrderLeft - i);
	}

	std::cout << (ans + tempAns);
	return 0;
}