#include <bits/stdc++.h>
using namespace std;
vector<string> ans;
inline string tostr(long long x) {
	char str[60];
	sprintf(str, "%lld", x);
	return (string)str;
}
namespace LB {
	long long b[60];
	inline bool check(long long x) {
		for (int i = 59; ~i; i--) if (x >> i & 1) x ^= b[i];
		return !x;
	}
	inline void Add(long long x) {
		if (x >= (1ll << 60)) return;
		for (int i = 59; ~i; i--) if (x >> i & 1) {
			if (!b[i]) {
				b[i] = x;
				break;
			}
			ans.push_back(tostr(x) + " ^ " + tostr(b[i]));
			x ^= b[i];
		}
	}
}
int main() {
	int x;
	scanf("%d", &x);
	LB::Add(x);
	vector<long long> vec;
	vec.push_back(x);
	while (!LB::check(1)) {
		vector<long long> nv;
		for (long long a : vec) {
			for (long long b : vec) {
				if (!LB::check(a + b)) {
					ans.push_back(tostr(a) + " + " + tostr(b));
					LB::Add(a + b);
					nv.push_back(a + b);
				}
			}
		}
		for (auto a : nv) vec.push_back(a);
	}
	printf("%d\n", (int)ans.size());
	for (auto &s : ans) puts(s.c_str());
	return 0;
}