#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
typedef long long ll;
int t;
int n;
map<ll, ll> num;
map<ll, ll> required;
int main() {
	scanf("%d", &t);
	for (int CASE = 0; CASE < t; CASE++) {
		scanf("%d", &n);
		num.clear();
		required.clear();
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			ll a;
			scanf("%lld", &a);
			sum += a;
			required[a]++;
		}
		num[sum]++;
		bool imposs = false;
		while (num.size()) {
			map<ll, ll> nxt;
			for (auto a : num) {
				ll need = required[a.first];
				//printf("at %lld %lld, need %lld\n", a.first, a.second, need);
				ll providing = min(need, a.second);
				required[a.first] -= providing;
				if (a.first == 1 && providing < a.second) {
					imposs = true;
				}
				if (a.second-providing > 0 && a.first != 1) {
					nxt[a.first/2] += a.second-providing;
					nxt[(a.first+1)/2] += a.second-providing;
				}
			}
			num.swap(nxt);
		}
		if (imposs) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}

}